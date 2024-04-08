#include<iostream>

using namespace std;

int a,b,c;
long long func(int a,int b,int c){
    if(b==1) return a%c;
    int val = func(a,b/2,c);
    val=val*val%c;
    if(b%2==0) return val;
    return val*a %c;
}
int main(){
    cin.tie(0);
    cin>>a>>b>>c;
    cout<<func(a,b,c);
}

int a,b,c;
int main(){
    cin>>a>>b>>c;
    if(b%2==0){
        int half = b/2;
        long long val =1;
        while(half--) val = val * a%c;
        val=val%c;
        long long result = (val * val)%c;
    }
    if(b%2==1){
        int half = (b-1)/2;
        long long val =1;
        while(half--) val = val * a%c;
        val=val%c;
        long long result = (val * val * a)%c;
    }
}

// 밑에처럼 짜는건 절차지향적이다
// 위에처럼 러프하게 처리하고 마지막에 조건만 해결하자
/*
#include<iostream>

using namespace std;
using ll = long long
ll a,b,c;
long long func(ll a,ll b,ll c){
    if(b==1) return a%c;
    if(b%2==0) return (func(a,b/2,c)*func(a,b/2,c))%c;
    if(b%2==1) return (a*func(a,b/2,c)*func(a,b/2,c))%c;
}
int main(){
    cin.tie(0);
    cin>>a>>b>>c;
    cout<<func(a,b,c);
}

*/