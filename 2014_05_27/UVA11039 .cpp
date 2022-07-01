#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int sol(vector<int> first, vector<int> second) {
	int building = 0;
	int top = 0x3f3f3f3f;
	while (1) {
		vector<int>* to_do_data;
		if (building % 2 == 0) {
			to_do_data = &first;
		}
		else {
			to_do_data = &second;
		}
		if (to_do_data->size() == 0) {
			break;
		}
		while (to_do_data->size() != 0)
		{
			if (to_do_data->back() < top) {
				top = to_do_data->back();
				building++;
				to_do_data->pop_back();
				break;
			}
			else {
				to_do_data->pop_back();
			}
		}
	}
	return building;
}
int main() {
	int p;
	cin >> p;
	while (p--) {
		int f;
		cin >> f;
		vector<int> red;
		vector<int> blue;
		while (f--) {
			int size;
			cin >> size;
			if (size < 0) {
				red.push_back(-size);
			}
			else {
				blue.push_back(size);
			}
		}
		sort(red.begin(), red.end());
		sort(blue.begin(), blue.end());
		int ans = max(sol(red,blue),sol(blue,red));
		cout << ans<<endl;
	}
}