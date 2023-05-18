/*
Ŀ¼
1. gcd				��С��Լ��
2. read				���ٶ�ȡ
3. quick_pow		������
4. quick_pow_mod	��mod�Ŀ�����
5.
*/
class Tools {
public:
	gcd(int, int);
	read();
	quick_pow(int, int);
	quick_pow_mod(int, int, int);

	/*
		���ټ�����С��Լ��(ֻ������ȫΪ���������)
	*/
	int gcd(int a, int b) {
		return b ? gcd(b, a % b) : a;
	}


	/*
		���ٶ���int����������
	*/
	int read() {
		int x = 0, f = 1;
		char ch = getchar();
		while (ch < '0' || ch > '9') {
			if (ch == '-')
				f = -1;
			ch = getchar();
		}
		while (ch >= '0' && ch <= '9') {
			x = (x << 1) + (x << 3) + (ch ^ 48);
			ch = getchar();
		}
		return x * f;
	}
	

	/*
		������,���ټ���x^n
	*/
	int quick_pow(int x, int n) {
		int ans = 1;
		while (n) {
			if (n & 1) ans *= x);
			x *= x;
			n >>= 1;
		}
		return ans;
	}
	

	/*
		������,���ټ���x^n % mod
	*/
	int quick_pow_mod(int x, int n, int mod) {
		long long ans = 1;
		while (n) {
			if (n & 1) ans = (ans * x) % mod;
			x *= x;
			n >>= 1;
		}
		return ans;
	}


};

