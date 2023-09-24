/// hhoangcp

#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int a[100][100];
void hhoangcp() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        for (int j = 1; j <= n; j++)
            a[i][j] = (s[j-1] == 'B');
        a[i][0] = a[0][i] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        if (i + j == 2) continue;
        if (a[i][j] == 1) continue;
        if (a[i - 1][j] == 0 && 1 == 2) {
            ans++;
            a[i][j] = 1;
           // cout << i << " " << j << " " << i - 1 << " " << j << "\n";
            continue;
        }
        if (a[i][j - 1] == 0) {
            a[i][j - 1] = 1;
            a[i][j] = 2;
            ++ans;
           // cout << i << " " << j << " " << i << " " << j - 1 << "\n";
            continue;
        }
    }
    cout << ans;

}

int main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int tests = 1; //cin >> tests;
    while (tests--) hhoangcp();

    return 0;
}
