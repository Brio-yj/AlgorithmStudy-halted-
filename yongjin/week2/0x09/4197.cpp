// 통과 : 0, 지훈 :1, 불 :2, 벽 =-1

#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int n, m;
int const mx = 1001;
int board[mx][mx];
int jvisit[mx][mx];
int fvisit[mx][mx];
int dx[]{-1, 1, 0, 0};
int dy[]{0, 0, -1, 1};

vector<int> distv;

queue<pair<int, int>> jq;
queue<pair<int, int>> fq;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            if (ch == '#') board[i][j] = -1;
            if (ch == '.') board[i][j] = 0;
            if (ch == 'J') {
                board[i][j] = 1;
                jvisit[i][j] = 1;
                jq.push({i, j});
            }
            if (ch == 'F') {
                board[i][j] = 2;
                fvisit[i][j] = 1;
                fq.push({i, j});
            }
        }
    }

    // f 전부 탐색
    while (!fq.empty()) {
        int x = fq.front().first;
        int y = fq.front().second;
        fq.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
            if (board[nx][ny] != -1 && fvisit[nx][ny] == 0) {
                fvisit[nx][ny] = fvisit[x][y] + 1;
                fq.push({nx, ny});
            }
        }
    }

    // j
    while (!jq.empty()) {
        int x = jq.front().first;
        int y = jq.front().second;
        jq.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) {
                cout<<jvisit[x][y];
                return 0;    
            }
            if(board[nx][ny]==-1 || jvisit[nx][ny]!=0) continue;
            else if(fvisit[nx][ny]!=0 && fvisit[nx][ny]<=(jvisit[x][y]+1)) continue;
            else{
                jvisit[nx][ny] = jvisit[x][y] + 1;
                jq.push({nx, ny});
            }
        }
    }
    cout<<"IMPOSSIBLE";
}

/*
지훈이가 bfs를 돌릴때


*/