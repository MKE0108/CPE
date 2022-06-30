#include<iostream>
#include<cmath>
#include<sstream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
struct T {
	int base;
	int exponent;
	T(int a, int b) {
		base = a;
		exponent = b;
	}
	long long operator()() {
		long long temp = 1;
		for (int i = 0; i < exponent; i++) {
			temp *= base;
		}
		return temp;
	}
};
int main() {
	string s;
	while (getline(cin, s), s != "0") {
		stringstream ss(s);
		int temp1, temp2;
		vector<T> seq;
		while (ss >> temp1 >> temp2) {
			seq.push_back(T(temp1, temp2));
		}
		unsigned long long x = 1;
		for (int i = 0; i < seq.size(); i++) {
			x *= seq[i]();
		}
		x -= 1;
		vector<T> result;
		T temp(2, 0);
		while (x != 1) {
			if (x % temp.base == 0) {
				temp.exponent++;
				x /= temp.base;
			}
			else {
				if (temp.exponent != 0) {
					result.push_back(temp);
				}
				temp.base++;
				temp.exponent = 0;
			}
			if (x == 1) {
				result.push_back(temp);
			}
		}
		cout << result[result.size() - 1].base << " " << result[result.size() - 1].exponent;
		for (int i = result.size() - 2; i >= 0; i--) {
			cout << " " << result[i].base << " " << result[i].exponent;
		}
		cout << endl;
	}
}