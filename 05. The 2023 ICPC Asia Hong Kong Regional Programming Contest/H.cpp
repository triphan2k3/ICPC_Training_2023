#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3e5;
vector<int> e[N];
void solve() {
    ll l, r, k, b; cin >> l >> r >> b >> k;
    ll du = (l+b-1)/b;
    ll time = du*b*k;
    cout << time << endl;
}
int main() {
    int t;t = 1;// cin >> t;
    while (t--) { solve();
    }
}