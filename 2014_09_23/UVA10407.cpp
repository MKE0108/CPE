#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int sol(int a, int b) {
	if (a < 0) {
		return (b + a % b) % b;
	}
	else {
		return a % b;
	}
}
int main() {
	int a;
	while (cin >> a, a) {
		vector<int> data;
		int max = abs(a);
		int min = abs(a);
		data.push_back(a);
		int b;
		while (cin >> b, b) {
			if (max < abs(b)) {
				max = abs(b);
			}if (min > abs(b)) {
				min = abs(b);
			}
			data.push_back(b);
		}
		int d;
		int r;
		int max_d = 0;
		for (int i = 1; i <= max + min; i++) {
			r = sol(data[0], i);
			d = i;
			for (int j = 0; j < data.size(); j++) {
				if (r != sol(data[j], i)) {
					r = -1;
				}
			}
			if (max_d < d && r != -1) {
				max_d = d;
			}
		}
		cout << max_d << endl;
	}
}