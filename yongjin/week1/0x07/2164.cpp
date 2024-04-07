#include <iostream>
#include <list>
using namespace std;

list<int> li;
int N;
int main(){
    cin>>N;
    for(int i=N;i>0;i--){
        li.push_back(i);
    }
    while(li.size()!=1){
        li.pop_back();
        int num = li.back();
        li.push_front(num);
        li.pop_back();
    }
    cout<<*li.begin();
}
