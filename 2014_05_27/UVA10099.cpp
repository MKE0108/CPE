//�ϥ�Java���ҥͽЪ`�N�A�̥~�h�����O(class)�ݩR�W�� main �C
//�p�G�J��W�G�Q�������p�A�Ч��sĶ���լݬ�!! �U�sĶ���S�ʤ��P!!
//�w�]����B�H������B�T�w����O�Ψ����U�����Ϊ��C���ɡA�u�ݷt������O�_�q�L!!
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