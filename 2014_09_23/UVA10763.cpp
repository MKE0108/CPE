#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
	while (cin >> n, n) {
		map<int, vector<int> >data;
		set<int> used;
		for (int i = 1; i <= n; i++) {
			int a, b;
			cin >> a >> b;
			data[a].push_back(b);
			used.insert(a);
			used.insert(b);
		}
		string flag = "YES";
		for (set<int>::iterator it1 = used.begin(); it1 != used.end() && flag == "YES"; it1++) {
			int i = *it1;
			for (int j = 0; j < data[i].size(); j++) {
				int his_partner = data[i][j];
				vector<int>::iterator it2 = find(data[his_partner].begin(), data[his_partner].end(), i);
				if (it2 == data[his_partner].end()) {
					flag = "NO";
				}
				else {
					data[his_partner].erase(it2);
				}
			}
		}
		cout << flag << endl;
	}
}