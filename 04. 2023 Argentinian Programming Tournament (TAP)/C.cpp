/// hhoangcp

#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

void hhoangcp() {
    int n; cin >> n;
    llong a[n+10], b[n+10];
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];
    sort(a+1, a+1+n);
    sort(b+1, b+1+n);
    llong mx = a[1] + b[n], mn = a[1] + b[n];
    for(int i=1; i<=n; i++) {
        mx = max(mx, a[i]+b[n-i+1]);
        mn = min(mn, a[i] + b[n-i+1]);
    }
    cout << mx - mn << endl;
}

int main() {
  //  freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int tests = 1; //cin >> tests;
    while (tests--) hhoangcp();

    return 0;
}
