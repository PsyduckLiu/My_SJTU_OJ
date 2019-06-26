#include <iostream>
using namespace std;
int maze[6][6];
bool mark[6][6];
int bx, by, ex, ey;
int minnum=1000000;
int e[4][2] = {{1,  0},{-1, 0},{0,  1},{0,  -1}};


void DFS(int x, int y, int cost, int cond) {
    if (x == ex && y == ey) {
        if (minnum > cost) minnum=cost;
        return;
    }

    if (minnum < cost)  return;

    for (int i = 0; i < 4; i++) {
        int nx = x + e[i][0];
        int ny = y + e[i][1];
        if (!mark[nx][ny] && nx >= 0 && nx <= 5 && ny >= 0 && ny <= 5) {
            mark[nx][ny]=true;
            int tcost=cond*maze[nx][ny];
            DFS(nx, ny, cost+tcost, tcost % 4 + 1);
            mark[nx][ny]=false;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int size;
    cin >> size;
    for (int i = 0; i < size; i++) {
        for (int x = 0; x < 6; x++) {
            for (int y = 0; y < 6; y++) {
            cin >> maze[x][y];
            mark[x][y] = false;
            }
        }
        cin >> bx >> by >> ex >> ey;

        DFS(bx,by,0,1);
        cout << minnum ;
    }
    return 0;

}
