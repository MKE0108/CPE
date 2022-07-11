#include<iostream>
using namespace std;
#define lli unsigned long long
lli c_n_2(lli a) {
	return a * (a - 1) / 2;
}
lli f(lli a) {
	return c_n_2(a)*2;
}
int main() {
	int m, n;
	while (cin >> m >> n) {
		if (m < n) {
			int tmp = n;
			n = m;
			m = tmp;
		}
		int k = m - n + 1;
		lli temp = 0;
		for (int i = 2; i <= n - 1; i++) {
			temp += f(i) * 2;
		}
		lli dai = (k * f(n) + temp) * 2;
		cout<<dai+m*f(n)+n*f(m) << endl;
	}
}