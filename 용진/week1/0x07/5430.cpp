#include <iostream>
#include <list>
#include <math.h>
#include <vector>
#include <string>

using namespace std;

list<int> li;
int main() {
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string p;
        cin >> p;
        int n;
        cin >> n;
        string s;
        cin>>s;
            if (n != 0) {
            vector<int> v;
            for (auto ch : s) {
                bool ff = false;
                if (ch - '0' >= 0 && ch - '0' <= 9) {
                    v.push_back(ch-'0');
                    ff=true;
                }else if(ff=true){
                    int sum=0;
                    for(int i=0;i<v.size();i++){                        
                        sum +=v[i]*pow(10,i);
                    }
                    li.push_back(sum);
                    v.clear();
                    ff=false;
                }
            }
            for (auto ch : p) {
                if (ch == 'R') li.reverse();
                if (ch == 'D') li.pop_front();
            }
            /*
            cout<<"list check= ";
            for(auto l:li) cout<<l<<" ";
            cout<<"\n";
            */
            cout<<"[";
            for(auto l:li){
                if(l==li.back()){
                    cout<<l<<"]";
                }
                else cout<<l<<",";
            }
            cout<<"\n";
        }else cout<<"error"<<"\n";
    }
}