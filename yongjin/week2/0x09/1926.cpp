#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define x first
#define y second

using namespace std;

vector<int> sizev;
int n, m, cnt, dsize;
int board[501][501];
int visit[501][501];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<int, int>> q;

int main() {
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            board[i][j] = num;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1 && visit[i][j] == 0) {  // 수정된 부분
                dsize = 1;
                cnt++;
                q.push(make_pair(i, j));
                visit[i][j] = 1;
                while (!q.empty()) {
                    int x = q.front().x;
                    int y = q.front().y;
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1)
                            continue;
                        if (visit[nx][ny] == 0 && board[nx][ny] == 1) {
                            visit[nx][ny] = 1;
                            dsize++;
                            q.push(make_pair(nx, ny));
                        }
                    }
                }
                sizev.push_back(dsize);
            }
        }
    }
    sort(sizev.rbegin(), sizev.rend());
    cout << cnt << "\n";
    if (!sizev.empty()) {
        cout << sizev[0];
    } else {
        cout << 0; 
    }
}
//
