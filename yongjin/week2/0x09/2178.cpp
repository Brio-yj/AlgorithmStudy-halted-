#include <iostream>
#include <utility>
#include <string>
#include <queue>


using namespace std;

int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
int visit[100][100];
int board[100][100];
int n,m;
queue<pair<int,int>> q;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        int j=0;
        for(auto ch :s){
            board[i][j]=ch-'0';
            j++;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==1 && visit[i][j]==0){
                q.push(make_pair(i,j));
                visit[i][j]=1;    
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(nx<0 || nx>n-1 || ny<0 || ny>m-1) continue;
                        if(board[nx][ny]==1 &&visit[nx][ny]==0){
                            visit[nx][ny]+=visit[x][y];
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
    }
    cout<<visit[n-1][m-1]+1;
}