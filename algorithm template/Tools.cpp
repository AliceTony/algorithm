/*
目录
1. gcd				最小公约数
2. read				快速读取
3. quick_pow		快速幂
4. quick_pow_mod	带mod的快速幂
5.
*/
class Tools {
public:
	gcd(int, int);
	read();
	quick_pow(int, int);
	quick_pow_mod(int, int, int);

	/*
		快速计算最小公约数(只能用于全为正数的情况)
	*/
	int gcd(int a, int b) {
		return b ? gcd(b, a % b) : a;
	}


	/*
		快速读入int类型形数据
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
		快速幂,快速计算x^n
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
		快速幂,快速计算x^n % mod
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

