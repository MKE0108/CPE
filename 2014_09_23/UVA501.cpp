#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int M, N;
int m[30000];
int n[30000];
int main() {
	int a;
	cin >> a;
	while (a--) {
		vector<int> pq;
		cin >> M >> N;
		for (int i = 0; i < M; i++) {
			cin >> m[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> n[i];
		}
		int t = 0;
		int t1 = 0;
		int index = 0;
		while (t != N) {
			for (; pq.size() < n[t];) {
				vector<int>::iterator iter = lower_bound(pq.begin(), pq.end(), m[t1]);
				pq.insert(iter, m[t1++]);
			}
			index++;
			cout << pq[index - 1] << endl;
			t++;
		}

		if (a != 0) {
			cout << endl;
		}
	}

}