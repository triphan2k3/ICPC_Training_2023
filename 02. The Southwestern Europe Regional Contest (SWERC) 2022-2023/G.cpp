#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(2*n, 0);
    for (int i = 1; i <= 2*n - 1; i++)
        a[i] = a[i - 1] + (s[i - 1] == 'W');
    int ma = 0;
    for (int i = n; i <= 2 * n - 1; i++)
        ma = max(ma, a[i] - a[i - n]);
    cout << ma; return 0;
    if (a[n] > 0) {
        cout << a[n];
    } else {
        cout << a[2*n - 1] - a[n - 1];
    }
}