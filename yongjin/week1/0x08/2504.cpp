#include <iostream>
#include <string>
#include <deque>
#include <stack>

using namespace std;

stack<char> st;
stack<char> st2;
deque<char> dq;
int main(){
    string s;
    cin>>s;
    for(auto ch : s){
        if(ch==')'){
            if(st.top()=='(') st.pop();
        }if(ch==']'){
            if(st.top()=='[') st.pop();
        }else st.push(ch);
    }
    if(!st.empty()) {
        cout<<0;
        return 0;
    }
    for(auto ch : s){dq.push_back(ch);}
    while(!dq.empty()){
        char ch=dq.back();
        if(st2.top()==')') {
            if(ch==')') 
        
        if(st2.top()==']'){
        }
        st2.push(ch);
        dq.pop_back();
    }

}