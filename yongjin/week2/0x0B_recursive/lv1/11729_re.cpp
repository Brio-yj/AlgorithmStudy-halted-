#include <iostream>

using namespace std;

int n;

int solve(int a, int b, int n){
    if(n==1){
        cout<<a<<" "<<b<<"\n";
        return 0;
    }
    solve(a,6-a-b,n-1);
    cout<<a<<" "<<b<<"\n";
    solve(6-a-b,b,n-1);
}
int main(){
    cin>>n;
}
//재귀함수 자체를 하나의 이동이라고 생각하면 편하다