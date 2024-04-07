#include <iostream>
#include <string>
#include <stack>

using namespace std;

int N,cnt;
int main(){
    cin>>N;;
    while(N--){
        string s;
        cin>>s;
        stack <char> st;
        for(auto ch: s){
            if(st.size()==0) st.push(ch);
            else if(st.size()==1) {
                if(st.top()==ch) st.pop();
                else st.push(ch);
            }
            else{
                if(st.top()!=ch) break;
                else st.pop();
            }
        }
        if(st.empty()) cnt++;
    }
    cout<<cnt;
}
//abaaba 반례있음
//받으면서 처리하면 해결하기 힘들다
//즉 전부 디테일하게 잡으면 못 푸는 문제
//그럴때는 전체적인 구조만 잡아주고 마지막 결과로 판단하기