#include <iostream>
#include <cmath>

using namespace std;

double n,x,y;

double solve(int x,int y,int n){
    if(n==1){
        if(x==1 && y==1) return 0;
        if(x==1 && y==2) return 1;
        if(x==2 && y==1) return 2;
        if(x==2 && y==2) return 3;
    }
    int cnt=0;
    if(x>pow(2,n-1) && y>pow(2,n-1)){
        x-=pow(2,n-1);
        y-=pow(2,n-1);
        cnt=3;
    }
    if (x>pow(2,n-1) && y<=pow(2,n-1)) {
        x-=pow(2,n-1);
        cnt=2;
    }
    if(x<=pow(2,n-1) && y>pow(2,n-1)) {
        y-=pow(2,n-1);
        cnt=1;
    }
    return solve(x,y,n-1) + pow(4,n-1) * cnt;
}
int main(){
    cin>>n>>x>>y;
    x++;y++;
    cout<<int(solve(x,y,n));
}