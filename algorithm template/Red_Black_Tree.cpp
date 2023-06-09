template <typename key_t, typename val_t>
class Red_Black_Tree {
private:
	//static_assert(is_integral<key_t>::value, "key_t must be an integral type");														//静态断言，用于检查模板参数是否满足要求
	//static_assert(is_class<val_t>::value, "val_t must be a class type");															//静态断言，用于检查模板参数是否满足要求
	typedef enum Color_t { RED, BLACK } color_t;						//枚举类型，红色为0，黑色为1
	typedef struct Tree_t {
		key_t key;														//键值
		val_t val;														//值
		bool color;														//0为红色，1为黑色
		Tree_t* left, * right, * parent;
		Tree_t(key_t key, val_t val, color_t color, Tree_t* left, Tree_t* right, Tree_t* parent) : key(key), val(val), color(color), left(left), right(right), parent(parent) {}	//构造函数
		Tree_t() : key(), val(), color(BLACK), left(nullptr), right(nullptr), parent(nullptr) {}									//构造函数
	} Tree_t;
	Tree_t* root = nullptr;												//根节点
	//左旋
	void rotate_left(Tree_t* tree) {
		Tree_t* right = tree->right;									//指向当前节点的右儿子
		if ((tree->right = right->left)) right->left->parent = tree;		//当前节点的右儿子指向右儿子的左儿子
		right->left = tree;
		if ((right->parent = tree->parent)) {								//右儿子的父亲指向当前节点的父亲
			if ((tree == tree->parent->left)) tree->parent->left = right;	//如果当前节点是父亲的左儿子，那么父亲的左儿子指向右儿子
			else tree->parent->right = right;							//如果当前节点是父亲的右儿子，那么父亲的右儿子指向右儿子
		}
		else root = right;												//如果当前节点没有父亲，那么右儿子就是根节点
		tree->parent = right;											//当前节点的父亲指向右儿子
	}
	//右旋
	void rotate_right(Tree_t* tree) {
		Tree_t* left = tree->left;										//指向当前节点的左儿子
		if ((tree->left = left->right)) left->right->parent = tree;		//当前节点的左儿子指向左儿子的右儿子
		left->right = tree;
		if ((left->parent = tree->parent)) {								//左儿子的父亲指向当前节点的父亲
			if ((tree == tree->parent->left)) tree->parent->left = left;	//如果当前节点是父亲的左儿子，那么父亲的左儿子指向左儿子
			else tree->parent->right = left;							//如果当前节点是父亲的右儿子，那么父亲的右儿子指向左儿子
		}
		else root = left;												//如果当前节点没有父亲，那么左儿子就是根节点
		tree->parent = left;											//当前节点的父亲指向左儿子
	}
	//插入修复
	void insert_fix(Tree_t* tree, Tree_t* parent) {
		if (parent->color == BLACK) return;														//如果父亲是黑色，那么不需要修复	
		Tree_t* grandparent = parent->parent;													//祖父
		Tree_t* uncle = grandparent->left == parent ? grandparent->right : grandparent->left;	//叔叔
		if (uncle && uncle->color == RED) {														//存在叔叔节点且叔叔节点为红色
			uncle->color = parent->color = BLACK;
			grandparent->color = RED;
			if (grandparent->parent)insert_fix(grandparent, grandparent->parent);				//将祖父节点当做新插入的节点进行修复
			else grandparent->color = BLACK;													//祖父节点为根节点 颜色恢复为黑色
		}
		else if (grandparent->left == parent) {													//父亲节点是祖父节点的左儿子
			if (parent->left == tree) {															//LL情况 染色+右旋
				parent->color = BLACK;
				grandparent->color = RED;
				rotate_right(grandparent);
			}
			else {																				//LR情况 染色+左旋+右旋
				grandparent->color = RED;
				tree->color = BLACK;
				rotate_left(parent);
				rotate_right(grandparent);
			}
		}
		else {																					//父亲节点是祖父节点的右儿子
			if (parent->right == tree) {														//RR情况 染色+左旋	
				parent->color = BLACK;
				grandparent->color = RED;
				rotate_left(grandparent);
			}
			else {																				//RL情况 染色+右旋+左旋
				grandparent->color = RED;
				tree->color = BLACK;
				rotate_right(parent);
				rotate_left(grandparent);
			}
		}
	}
	//查找前继节点
	Tree_t* find_precursor(Tree_t* tree) {
		Tree_t* left;
		tree = tree->left;
		while ((left = tree->right)) tree = left;
		return tree;
	}
	//查找后继节点
	Tree_t* find_successors(Tree_t* tree) {
		Tree_t* right;
		tree = tree->right;
		while ((right = tree->left)) tree = right;
		return tree;
	}
	//交换两个节点
	void copy(Tree_t* tree1, Tree_t* tree2) {
		tree1->key = tree2->key;
		tree1->val = tree2->val;
	}
	//将要删除的节点转化为一个叶子节点
	void erase_find(Tree_t* tree) {
		if (tree->left && tree->right) {								//如果左右儿子都存在						
			Tree_t* precursor = find_precursor(tree);					//找到前继节点
			copy(tree, precursor);										//将当前节点赋值前继节点
			tree = precursor;
		}
		Tree_t* child = tree->left ? tree->left : tree->right;
		if (child) {													//如果存在儿子节点 与儿子节点交换
			copy(tree, child);
			tree = child;
		}
		if (!tree->parent) {
			root = nullptr;
			delete tree;
			return;
		}
		bool color = tree->color;
		if (color == BLACK) erase_fix(tree);							//如果删除节点为黑色进行修复
		Tree_t* parent = tree->parent;
		parent&& tree == parent->left ? parent->left = nullptr : parent->right = nullptr;	//取消链接当前值
		delete tree;
	}
	//删除后进行调整
	void erase_fix(Tree_t* tree) {
		Tree_t* parent = tree->parent;
		Tree_t* brother = parent->left == parent ? parent->right : parent->left;
		if (brother->color == RED) {										//如果兄弟节点颜色为红色 进行变色 
			rotate_right(parent);
			brother->color = BLACK;
			parent->color = RED;
			erase_fix(tree);
		}
		if (brother->left) {												//如果兄弟节点存在左子节点 进行一次变色+右旋
			brother->color = parent->color;
			rotate_right(parent);
			brother->left->color = BLACK;
			brother->right->color = BLACK;
		}
		else if (brother->right) {											//如果兄弟节点存在右子节点 进行一次双旋并变色
			Tree_t* child = brother->right;
			rotate_left(brother);
			rotate_right(parent);
			child->color = parent->color;
			child->left->color = BLACK;
			child->right->color = BLACK;
		}
		else if (parent->color == RED) {									//兄弟节点不存在子节点且父节点为红色 进行变色
			parent->color = BLACK;
			brother->color = RED;
		}
		else {																//父节点为红色 转化为黑色 递归处理
			parent->color = BLACK;
			brother->color = RED;
			if (parent->parent) erase_fix(parent);
		}
	}
public:
	//查找
	Tree_t* find(key_t key) {
		Tree_t* tree = root;
		while (tree) {
			if (key == tree->key) return tree;							//如果找到了，返回当前节点
			else if (key < tree->key) tree = tree->left;				//如果小于当前节点，那么往左儿子走
			else tree = tree->right;									//如果大于当前节点，那么往右儿子走
		}
		return nullptr;													//如果没有找到，返回空指针
	}
	//插入节点
	bool insert(key_t key, val_t val) {
		if (!root) {														//如果根节点为空
			root = new Tree_t(key, val, BLACK, nullptr, nullptr, nullptr);	//根节点为黑色
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
	//删除
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
