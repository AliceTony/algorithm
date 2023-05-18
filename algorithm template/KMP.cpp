class KMP {
private:
    char* str;                                                              //���ģʽ��
    int n;                                                                  //���ģʽ������
    vector<int> next;                                                       //���ƥ��ʧ�ܺ����λ��
public:
    KMP(char s1[]) {
        count_next(s1);
    }
    void count_next(char s[]) {                                             //����next����
        str = s;
        n = strlen(s);
        next.resize(n);
        next[0] = 0;
        for (int i = 1, j = 0; i < n; i++) {                                //���±�Ϊ1��ʼ����next����
            while (j && str[i] != str[j]) j = next[j - 1];                  //��j��Ϊ0ʱ ��ƥ��ʧ�� ���л���
            if (str[j] == str[i])j++;                                       //����ɹ�ƥ��j++
            next[i] = j;
        }
    }
    vector <int> check(char s[]) {                                          //�����ַ���ƥ��
        vector <int> res;
        int len = strlen(s);
        for (int i = 0, j = 0; i < len; i++) {                              //�����ַ�ƥ��
            while (j && s[i] != str[j]) j = next[j - 1];                    //��j��Ϊ0��ƥ��ʧ�� ���л���
            if (s[i] == str[j]) j++;                                        //ƥ��ɹ�j++
            if (j == n) res.push_back(i - n + 2), j = next[j - 1];          //����ƥ��ɹ��ַ��� ����ַ�������λ��
        }
        return res;
    }
    vector <int> get_next() {
        return next;
    }
};