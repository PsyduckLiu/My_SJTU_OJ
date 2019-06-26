#include <iostream>
#include <cstdio>
using namespace std;
 
struct position {
	int distance = 0;
	int posx = 0, posy = 0;
	int remain = 0;
};
 
 
class que {
	position que_[100000];
	int start = 0, end = 0;
	int mod = 100000;
public:
	bool empty() const {
		return end - start == 0;
	}
	position front() const {
		return que_[start % mod];
	}
	void pop() {
		++start;
	}
	void push(const position & val) {
		que_[(end++) % mod] = val;
	}
	int size() {
		return end - start;
	}
};
 
int map_data[309][309] = { 0 };
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int visited[309][309] = { 0 };
que que_data;
int n, m;
 
int bfs(int startx, int starty, int endx, int endy) {
	position point;
	point.posx = startx;
	point.posy = starty;
	point.distance = 0;
	point.remain = 6;
	que_data.push(point);
	visited[startx][starty] = 0;
	while (!que_data.empty()) {
		position tmp = que_data.front();
		que_data.pop();
		if (tmp.posx == endx && tmp.posy == endy) {
			return tmp.distance;
		}
		if (map_data[tmp.posx][tmp.posy] == 4) {
			tmp.remain = 6;
			map_data[tmp.posx][tmp.posy] = 0;
		}
		if (tmp.remain > 1) {
			for (int i = 0; i < 4; ++i) {
				int nextx = tmp.posx + dx[i];
				int	nexty = tmp.posy + dy[i];
				if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < m &&
					map_data[nextx][nexty]!=0) {
					position next;
					next.distance = tmp.distance + 1;
					next.posx = nextx;
					next.posy = nexty;
					next.remain = tmp.remain - 1;
					if (visited[nextx][nexty] == -1) {
						que_data.push(next);
						visited[nextx][nexty] = next.distance;
					}
					else if (next.distance <= visited[nextx][nexty] + 6) {
						que_data.push(next);
					}
				}
			}
		}
	}
	return -1;
}
 
 
 
int main() {
	int i,j;
    for (i=0;i<309;i++) {
        for (j=0;j<309;j++) {
            visited[i][j]=-1;
        }
    }
	scanf("%d %d", &n, &m);
	int startx = 0, starty = 0;
	int	endx = 0, endy = 0;
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j) {
			scanf("%d", &map_data[i][j]);
			if (map_data[i][j] == 2) {
				startx = i, starty = j;
			}
        else if (map_data[i][j] == 3) {
				endx = i, endy = j;
			}
		}
	cout << bfs(startx, starty, endx, endy);
	return 0;
 
}
