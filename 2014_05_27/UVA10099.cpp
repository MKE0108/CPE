//使用Java的考生請注意，最外層的類別(class)需命名為 main 。
//如果遇到超乎想像的狀況，請更改編譯器試看看!! 各編譯器特性不同!!
//預設測資、隨機測資、固定測資是用來幫助除錯用的。批改時，只看暗中測資是否通過!!
#include<bits/stdc++.h>
using namespace std;
int floy[101][101];
int N, R;
int testcase = 1;
int main() {
	while (cin >> N >> R, N) {
		memset(floy, 0, sizeof(floy));
		for (int i = 0; i < R; i++) {
			int node1, node2, P;
			cin >> node1 >> node2 >> P;
			floy[node1][node2] = P;
			floy[node2][node1] = P;
		}
		for (int k = 1; k <= N; k++) {
			for (int j = 1; j <= N; j++) {
				for (int i = 1; i <= N; i++) {
					floy[i][j] = max(floy[i][j], min(floy[i][k], floy[k][j]));
				}
			}
		}
		int S, D, T;
		cin >> S >> D >> T;
		int num_per_times = floy[S][D] - 1;//consider the Mr. G.
		int times = T / num_per_times;
		if (times * num_per_times != T) {
			times++;
		}
		cout << "Scenario #" << testcase++ << endl << "Minimum Number of Trips = " << times << endl << endl;;
	}
}