#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int arr[10];
string s;
int main(){
    cin.tie(0);
    cin>>s;
    for(auto a:s){
        arr[a-'0']++;
    }
    int temp=(arr[6]+arr[9]+1)/2;
    arr[6]=temp;
    arr[9]=temp;
    sort(arr,arr+10);
    cout<<arr[9];
}

//sort-><algorithm>