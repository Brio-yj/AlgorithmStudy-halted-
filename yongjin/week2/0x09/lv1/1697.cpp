#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n,k;
queue<int> q;
int board[200001];
//결국 visit이 board가 된다
int main(){
    cin>>n>>k;
    q.push(n);
    board[n]=1;
    while(!q.empty()){
        n=q.front();
        q.pop();
        for(int i=0;i<3;i++){
            if(i==0){
                if(n==k) {
                    cout<<board[n]-1;
                    return 0;
                }
                int nn = n-1;
                if(nn<0 || nn>200000) continue;
                if(board[nn]!=0) continue;
                board[nn]=board[n]+1;
                q.push(nn);
            }
            if(i==1){
                if(n==k) {
                    cout<<board[n]-1;
                    return 0;
                }
                int nn = n+1;
                if(nn<0 || nn>200000) continue;
                if(board[nn]!=0) continue;
                board[nn]=board[n]+1;
                q.push(nn);
            }
            if(i==2){
                if(n==k) {
                    cout<<board[n]-1;
                    return 0;
                }
                int nn = n*2;
                if(nn<0 || nn>200000) continue;
                if(board[nn]!=0) continue;
                board[nn]=board[n]+1;
                q.push(nn);
            }
        }
    }
}
