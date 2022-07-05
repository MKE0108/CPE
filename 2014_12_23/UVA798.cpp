#include<iostream>
#include<string.h>
using namespace std;
struct block {
	int h, w;
	int num;
};
block blocks[11];
int map[101][101];
int r, c, n, ans;
void init() {

	for (int i = 0; i < n; i++) {
		int r, c, n;
		cin >> n >> c >> r;
		blocks[i].w = c;
		blocks[i].h = r;
		blocks[i].num = n;
	}
	memset(map, 0, sizeof(map));
	ans = 0;
}
bool judge(int cur_x, int cur_y, block a) {
	if (cur_x + a.h > r || cur_y + a.w > c) return 0;
	for (int i = 0; i < a.h; i++) {
		for (int j = 0; j < a.w; j++) {
			if (map[cur_x + i][cur_y + j] == 1) {
				return 0;
			}
		}
	}
	return 1;
}
void set(int cur_x, int cur_y, block a, int status) {
	for (int i = 0; i < a.h; i++) {
		for (int j = 0; j < a.w; j++) {
			map[cur_x + i][cur_y + j] = status;
		}
	}
}
void dfs(int x, int y) {
	if (y == c) {
		x++;
		y = 0;
	}
	if (x == r) {
		ans++;
		return;
	}
	if (map[x][y] == 0) {
		for (int i = 0; i < n; i++) {
			if (blocks[i].num != 0) {
				if (judge(x, y, blocks[i])) {
					set(x, y, blocks[i], 1);
					blocks[i].num--;
					dfs(x, y + 1);
					blocks[i].num++;
					set(x, y, blocks[i], 0);
				}
				block temp = blocks[i];
				swap(temp.h, temp.w);
				if (judge(x, y, temp) && temp.w != temp.h) {
					set(x, y, temp, 1);
					blocks[i].num--;
					dfs(x, y + 1);
					blocks[i].num++;
					set(x, y, temp, 0);
				}
			}
		}
	}
	else {
		dfs(x, y + 1);
	}

}
int main() {
	while (cin >> c >> r >> n) {
		init();
		dfs(0, 0);
		cout << ans << endl;
	}
}