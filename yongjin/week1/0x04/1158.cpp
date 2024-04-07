#include <iostream>
#include <list>
#include <vector>

using namespace std;

int N, K;
list<int> li;
vector<int> v;
int main() {
    cin >> N >> K;
    for (int i = 1; i < N + 1; i++) li.push_back(i);
    while (li.size() != 1) {
        for (int i = 0; i < K; i++) {
            if (i == K - 1) {
                int num = li.front();
                v.push_back(num);
                li.pop_front();
            } else {
                int num = li.front();
                li.push_back(num);
                li.pop_front();
            }
        }
    }
    int num = li.front();
    v.push_back(num);

    cout << "<";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1) cout << ", ";
    }
    cout << ">";

}