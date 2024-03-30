#include <iostream>
#include <list>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        list<int> li;
        auto it = li.begin();
        string s;
        cin >> s;
        for (auto a : s) {
            if (a == '<') {
                if (it != li.begin()) it--;
            } else if (a == '>') {
                if (it != li.end()) it++;
            } else if (a == '-') {
                if (it != li.begin()) {
                    it = li.erase(prev(it));
                }
            } else {
                li.insert(it, a);
            }
        }
        for (auto a : li) {
            cout << a;
        }
        cout << "\n";
    }
    return 0;
}
