#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> q;
vector<int> v;

int main() {
    cin.tie(0);
    cin >> N;
    while (N--) {
        int num;
        cin >> num;
        q.push(num);
    }
    while(!q.empty()){
        int num = q.front();
        q.pop();
        v.push_back(num);
        int size = v.size();
        bool ff = false;
        for (int i = 1; i < size; i++) {
            if (v[size - i] > num) {
                cout << size - i +1 << " ";
                ff = true;
                break;
            }
        }
        if (ff == false) cout << "0 ";
    }
}


// 비교할때 == 항상 조심