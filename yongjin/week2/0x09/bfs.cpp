#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second  // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[502][502] = {
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 0}, {1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};  // 1이 파란 칸, 0이 빨간 칸에 대응
bool vis[502][502];  // 해당 칸을 방문했는지 여부를 저장
int n = 7, m = 10;   // n = 행의 수, m = 열의 수
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};  // 상하좌우 네 방향을 의미
queue<pair<int, int>> q;

int main(void) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1 && vis[i][j] == 0) {
                q.push(make_pair(i, j));
                vis[i][j] = 1;
                while (!q.empty()) {
                    int x = q.front().X;
                    int y = q.front().Y;
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (x < 0 || x > n - 1 || y < 0 || y > m - 1) continue;
                        if (board[nx][ny] == 1 & vis[nx][ny] == 0) {
                            q.push(make_pair(x, y));
                            vis[nx][ny] = 1;
                        }
                    }
                }
            }
        }
    }
}