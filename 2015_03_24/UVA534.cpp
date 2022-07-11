#include<bits/stdc++.h>
using namespace std;
struct p {
	double x;
	double y;
	p(int a = 0, int b = 0) {
		x = a;
		y = b;
	}
};
double operator-(p a, p b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main() {
	int t = 1;
	int num_of_rock;
	while (cin >> num_of_rock, num_of_rock) {
		vector< vector<double> > floy(num_of_rock, vector<double>(num_of_rock, 0x3f3f3f3f));
		vector<p> rocks(num_of_rock);
		for (int i = 0; i < num_of_rock; i++) {
			cin >> rocks[i].x >> rocks[i].y;
		}
		for (int i = 0; i < num_of_rock; i++) {
			for (int j = 0; j < num_of_rock; j++) {
				floy[i][j] = rocks[i] - rocks[j];
			}
		}
		for (int k = 0; k < num_of_rock; k++) {
			for (int i = 0; i < num_of_rock; i++) {
				for (int j = 0; j < num_of_rock; j++) {

					floy[i][j] = min(max(floy[i][k], floy[k][j]), floy[i][j]);
				}
			}
		}
		cout << "Scenario #" << t++ << "\nFrog Distance = ";
		cout << fixed << setprecision(3) << floy[0][1] << endl << endl;
	}
}