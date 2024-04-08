#include <iostream>
using namespace std;
int n;
int arr[3];
int board[2188][2188];

int check(int x, int y, int n) {
    bool same = true;
    int temp = board[x][y];
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (temp != board[x][y]) {
                same = false;
                break;
            }
        }
    }
    if (same == true) {
        if (temp = -1) {
            arr[0]++;
            return 0;
        }
        if (temp = 0) {
            arr[1]++;
            return 0;
        }
        if (temp = 1) {
            arr[2]++;
            return 0;
        }
    } else
        return 0;
}
int solve(int x, int y, int n) {
    if (n == 1) {
        check(x, y, n);
        return 0;
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            solve(x+3*i, y+3*i, n);
        }
    }
    return 0;
}
int main() {
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    solve(0, 0, n);
    for (auto a : arr) cout << a << "\n";
}
