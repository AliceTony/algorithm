template <typename key_t, typename val_t>
class Red_Black_Tree {
private:
	//static_assert(is_integral<key_t>::value, "key_t must be an integral type");														//��̬���ԣ����ڼ��ģ������Ƿ�����Ҫ��
	//static_assert(is_class<val_t>::value, "val_t must be a class type");															//��̬���ԣ����ڼ��ģ������Ƿ�����Ҫ��
	typedef enum Color_t { RED, BLACK } color_t;						//ö�����ͣ���ɫΪ0����ɫΪ1
	typedef struct Tree_t {
		key_t key;														//��ֵ
		val_t val;														//ֵ
		bool color;														//0Ϊ��ɫ��1Ϊ��ɫ
		Tree_t* left, * right, * parent;
		Tree_t(key_t key, val_t val, color_t color, Tree_t* left, Tree_t* right, Tree_t* parent) : key(key), val(val), color(color), left(left), right(right), parent(parent) {}	//���캯��
		Tree_t() : key(), val(), color(BLACK), left(nullptr), right(nullptr), parent(nullptr) {}									//���캯��
	} Tree_t;
	Tree_t* root = nullptr;												//���ڵ�
	//����
	void rotate_left(Tree_t* tree) {
		Tree_t* right = tree->right;									//ָ��ǰ�ڵ���Ҷ���
		if ((tree->right = right->left)) right->left->parent = tree;		//��ǰ�ڵ���Ҷ���ָ���Ҷ��ӵ������
		right->left = tree;
		if ((right->parent = tree->parent)) {								//�Ҷ��ӵĸ���ָ��ǰ�ڵ�ĸ���
			if ((tree == tree->parent->left)) tree->parent->left = right;	//�����ǰ�ڵ��Ǹ��׵�����ӣ���ô���׵������ָ���Ҷ���
			else tree->parent->right = right;							//�����ǰ�ڵ��Ǹ��׵��Ҷ��ӣ���ô���׵��Ҷ���ָ���Ҷ���
		}
		else root = right;												//�����ǰ�ڵ�û�и��ף���ô�Ҷ��Ӿ��Ǹ��ڵ�
		tree->parent = right;											//��ǰ�ڵ�ĸ���ָ���Ҷ���
	}
	//����
	void rotate_right(Tree_t* tree) {
		Tree_t* left = tree->left;										//ָ��ǰ�ڵ�������
		if ((tree->left = left->right)) left->right->parent = tree;		//��ǰ�ڵ�������ָ������ӵ��Ҷ���
		left->right = tree;
		if ((left->parent = tree->parent)) {								//����ӵĸ���ָ��ǰ�ڵ�ĸ���
			if ((tree == tree->parent->left)) tree->parent->left = left;	//�����ǰ�ڵ��Ǹ��׵�����ӣ���ô���׵������ָ�������
			else tree->parent->right = left;							//�����ǰ�ڵ��Ǹ��׵��Ҷ��ӣ���ô���׵��Ҷ���ָ�������
		}
		else root = left;												//�����ǰ�ڵ�û�и��ף���ô����Ӿ��Ǹ��ڵ�
		tree->parent = left;											//��ǰ�ڵ�ĸ���ָ�������
	}
	//�����޸�
	void insert_fix(Tree_t* tree, Tree_t* parent) {
		if (parent->color == BLACK) return;														//��������Ǻ�ɫ����ô����Ҫ�޸�	
		Tree_t* grandparent = parent->parent;													//�游
		Tree_t* uncle = grandparent->left == parent ? grandparent->right : grandparent->left;	//����
		if (uncle && uncle->color == RED) {														//��������ڵ�������ڵ�Ϊ��ɫ
			uncle->color = parent->color = BLACK;
			grandparent->color = RED;
			if (grandparent->parent)insert_fix(grandparent, grandparent->parent);				//���游�ڵ㵱���²���Ľڵ�����޸�
			else grandparent->color = BLACK;													//�游�ڵ�Ϊ���ڵ� ��ɫ�ָ�Ϊ��ɫ
		}
		else if (grandparent->left == parent) {													//���׽ڵ����游�ڵ�������
			if (parent->left == tree) {															//LL��� Ⱦɫ+����
				parent->color = BLACK;
				grandparent->color = RED;
				rotate_right(grandparent);
			}
			else {																				//LR��� Ⱦɫ+����+����
				grandparent->color = RED;
				tree->color = BLACK;
				rotate_left(parent);
				rotate_right(grandparent);
			}
		}
		else {																					//���׽ڵ����游�ڵ���Ҷ���
			if (parent->right == tree) {														//RR��� Ⱦɫ+����	
				parent->color = BLACK;
				grandparent->color = RED;
				rotate_left(grandparent);
			}
			else {																				//RL��� Ⱦɫ+����+����
				grandparent->color = RED;
				tree->color = BLACK;
				rotate_right(parent);
				rotate_left(grandparent);
			}
		}
	}
	//����ǰ�̽ڵ�
	Tree_t* find_precursor(Tree_t* tree) {
		Tree_t* left;
		tree = tree->left;
		while ((left = tree->right)) tree = left;
		return tree;
	}
	//���Һ�̽ڵ�
	Tree_t* find_successors(Tree_t* tree) {
		Tree_t* right;
		tree = tree->right;
		while ((right = right->left)) tree = right;
		return tree;
	}
	//���������ڵ�
	void copy(Tree_t* tree1, Tree_t* tree2) {
		tree1->key = tree2->key;
		tree1->val = tree2->val;
	}
	//��Ҫɾ���Ľڵ�ת��Ϊһ��Ҷ�ӽڵ�
	void erase_find(Tree_t* tree) {
		if (tree->left && tree->right) {								//������Ҷ��Ӷ�����						
			Tree_t* precursor = find_precursor(tree);					//�ҵ�ǰ�̽ڵ�
			copy(tree, precursor);										//����ǰ�ڵ㸳ֵǰ�̽ڵ�
			tree = precursor;
		}
		Tree_t* child = tree->left ? tree->left : tree->right;
		if (child) {													//������ڶ��ӽڵ� ����ӽڵ㽻��
			copy(tree, child);
			tree = child;
		}
		if (!tree->parent) {
			root = nullptr;
			delete tree;
			return;
		}
		bool color = tree->color;
		if (color == BLACK) erase_fix(tree);							//���ɾ���ڵ�Ϊ��ɫ�����޸�
		Tree_t* parent = tree->parent;
		parent&& tree == parent->left ? parent->left = nullptr : parent->right = nullptr;	//ȡ�����ӵ�ǰֵ
		delete tree;
	}
	//ɾ������е���
	void erase_fix(Tree_t* tree) {
		Tree_t* parent = tree->parent;
		Tree_t* brother = parent->left == parent ? parent->right : parent->left;
		if (brother->color == RED) {										//����ֵܽڵ���ɫΪ��ɫ ���б�ɫ 
			rotate_right(parent);
			brother->color = BLACK;
			parent->color = RED;
			erase_fix(tree);
		}
		if (brother->left) {												//����ֵܽڵ�������ӽڵ� ����һ�α�ɫ+����
			brother->color = parent->color;
			rotate_right(parent);
			brother->left->color = BLACK;
			brother->right->color = BLACK;
		}
		else if (brother->right) {											//����ֵܽڵ�������ӽڵ� ����һ��˫������ɫ
			Tree_t* child = brother->right;
			rotate_left(brother);
			rotate_right(parent);
			child->color = parent->color;
			child->left->color = BLACK;
			child->right->color = BLACK;
		}
		else if (parent->color == RED) {									//�ֵܽڵ㲻�����ӽڵ��Ҹ��ڵ�Ϊ��ɫ ���б�ɫ
			parent->color = BLACK;
			brother->color = RED;
		}
		else {																//���ڵ�Ϊ��ɫ ת��Ϊ��ɫ �ݹ鴦��
			parent->color = BLACK;
			brother->color = RED;
			if (parent->parent) erase_fix(parent);
		}
	}
public:
	//����
	Tree_t* find(key_t key) {
		Tree_t* tree = root;
		while (tree) {
			if (key == tree->key) return tree;							//����ҵ��ˣ����ص�ǰ�ڵ�
			else if (key < tree->key) tree = tree->left;				//���С�ڵ�ǰ�ڵ㣬��ô���������
			else tree = tree->right;									//������ڵ�ǰ�ڵ㣬��ô���Ҷ�����
		}
		return nullptr;													//���û���ҵ������ؿ�ָ��
	}
	//����ڵ�
	bool insert(key_t key, val_t val) {
		if (!root) {														//������ڵ�Ϊ��
			root = new Tree_t(key, val, BLACK, nullptr, nullptr, nullptr);	//���ڵ�Ϊ��ɫ
			return 1;
		}
		Tree_t* parent = root;
		while (parent) {
			if (parent->key > key) {
				if (parent->left) parent = parent->left;
				else {
					parent->left = new Tree_t(key, val, RED, nullptr, nullptr, parent);
					insert_fix(parent->left, parent);
					return 1;
				}
			}
			else if (parent->key < key) {
				if (parent->right) parent = parent->right;
				else {
					parent->right = new Tree_t(key, val, RED, nullptr, nullptr, parent);
					insert_fix(parent->right, parent);
					return 1;
				}
			}
			else return 0;
		}
		return 0;
	}
	//ɾ��
	bool erase(key_t key) {
		Tree_t* tree = find(key);
		if (!tree) return 0;
		erase_find(tree);
		return 1;
	}
	~Red_Black_Tree() {
		Tree_t* tree = root;
		while (tree) {
			if (tree->left) tree = tree->left;
			else if (tree->right) tree = tree->right;
			else {
				Tree_t* parent = tree->parent;
				if (parent) {
					if (parent->left == tree) parent->left = nullptr;
					else parent->right = nullptr;
				}
				delete tree;
				tree = parent;
			}
		}
		return;
	}
};