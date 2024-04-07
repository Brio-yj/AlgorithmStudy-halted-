#include <iostream>
using namespace std;
int const mx = 2000001;
int arr[mx];
int comparr[mx];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        comparr[arr[i]]++;
    }
    int x;
    int cnt=0;
    cin>>x;
    for(int i=0;i<n;i++){
        if(x-arr[i]<0) continue;
        if(comparr[x-arr[i]]==1)cnt++;
    }
    cout<<cnt/2;
}