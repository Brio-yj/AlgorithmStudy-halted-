#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> v;
stack<int> st;
int N;
int main() {
    cin >> N;
    while (N--) {
        int num;
        cin >> num;
        v.push_back(num);
        int lastnum = v.back();
        int sub = lastnum - num;
        if (sub > 1) {
            vector<int> chev;
            for (int i = 1; i < sub; i++) {
                if (find(v.begin(), v.end(), num + i) != v.end())
                    chev.push_back(1);
                else
                    chev.push_back(0);
            }
            if (find(chev.begin(), chev.end(), 0) != chev.end()) {
                cout << "NO";
                return 0;
            }
        }
    }
    while (1) {
        for (int i = 1; i < N + 1; i++) {
            if (st.top() == v.front()) {
                auto it = v.begin();
                cout << "- \n";
                st.pop();
                v.erase(it);
            }
            else{
                cout << "+ \n";
                st.push(i);
            }
        }
        if(!v.empty()) break;
    }
}