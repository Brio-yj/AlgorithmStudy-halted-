#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> li;
    auto it = li.begin();
    li.insert(it, 1);
    li.insert(it, 2);
    li.insert(it, 3);
    for (auto a : li) cout << a;
}