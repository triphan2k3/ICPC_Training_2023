#include <bits/stdc++.h>

using namespace std;
int a[10] = {1,0,0,0,1,0,1,0,2,1};

int main() {
    int t; cin >> t; 
    while (t--) {
        int x, k;
        cin >> x >> k;
        while (x && k) {
            int newX = 0;
            while (x) {
                newX += a[x % 10];
                x /= 10;
            }
            x = newX;
            --k;
        }
        if (k == 0)
            cout << x << "\n";
        else 
            cout << k % 2 << "\n";
    }
}