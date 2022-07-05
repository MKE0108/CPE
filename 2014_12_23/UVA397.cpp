#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
struct EQ {
	vector<int> nums;
	vector<char> op;
	string right;
	EQ(vector<int> nums, vector<char> op, string right) {
		this->nums = nums;
		this->op = op;
		this->right = right;
	}
	void show() {
		int total = op.size() + nums.size();
		int j, k;
		j = 0;
		k = 0;
		for (int i = 0; i < total; i++) {
			if (i % 2 == 0) {
				cout << nums[j++] << " ";
			}
			else {
				cout << op[k++] << " ";
			}
		}
		cout << right << endl;
	}
	void combine(int pos) {
		char op1 = op[pos];
		op.erase(op.begin() + pos);
		if (op1 == '+') {
			nums[pos] += nums[pos + 1];
		}
		if (op1 == '-') {
			nums[pos] -= nums[pos + 1];
		}
		if (op1 == '*') {
			nums[pos] *= nums[pos + 1];
		}
		if (op1 == '/') {
			nums[pos] /= nums[pos + 1];
		}
		nums.erase(nums.begin() + pos + 1);
	}
	void ex() {
		while (1) {
			int left_op = -1;//  '/'or'*'
			for (int i = 0; i < op.size(); i++) {
				if (op[i] == '*' || op[i] == '/') {
					left_op = i;
					break;
				}
			}
			if (left_op == -1) {
				break;
			}
			combine(left_op);
			show();
		}
		while (op.size() != 0) {
			combine(0);
			show();
		}

	}
};
int main() {
	int first;
	int t = 0;
	while (cin >> first) {
		vector<int> nums;
		vector<char> op;
		string right;
		if (t) {
			cout << "\n";
		}
		else {
			t = 1;
		}
		nums.push_back(first);
		for (int i = 0;; i++) {
			if (i % 2 == 1) {
				int temp;
				cin >> temp;
				nums.push_back(temp);
			}
			else {
				char temp;
				cin >> temp;
				if (temp == '=') {
					right += temp;
					right += " ";
					string str;
					cin >> str;
					right += str;
					break;
				}
				else {
					op.push_back(temp);
				}
			}
		}
		EQ a(nums, op, right);
		a.show();
		a.ex();
	}
}
