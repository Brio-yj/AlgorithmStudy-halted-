#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;
int n,m;
int dx[]{-1,1,0,0};
int dy[]{0,0,-1,1};
int board[1002][1002];
int visit[1002][1002];

queue<pair<int,int>> q;

int main(){
    cin>>m>>n;
    bool riped = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int num;
            cin>>num;
            if(num==0) riped = false;
            board[i][j]=num;
        }
    }
    if(riped == true) {
        cout<<"0";
    return 0;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==1 &&visit[i][j]==0){
                q.push(make_pair(i,j));
                visit[i][j]=1;
            }
        }
    }

    while(!q.empty()){
        int x =q.front().first;
        int y =q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx<0 || nx>n-1|| ny<0 || ny>m-1) continue;
            if(board[nx][ny]==0 &&visit[nx][ny]==0){
                visit[nx][ny] = visit[x][y]+1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    bool findzero= false;
    int temp = 0; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(board[i][j]== 0 && visit[i][j]==0) findzero=true;
            temp = max(temp, visit[i][j]); 
        }
    }
    if(findzero==true) cout<<"-1";
    else cout<<temp-1;
}