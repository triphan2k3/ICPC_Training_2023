/// hhoangcp

#include <bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

vector<ld> P, N;
ld T;
int n;

void hhoangcp() {
    cin >> n >> T; ld tot = 0;
    for(int i = 1; i <= n; ++i) {
        char c; cin >> c;
        int a; cin >> a;
        tot += a;
    }

    cout << fixed << setprecision(8) << tot / T;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int tests = 1; //cin >> tests;
    while (tests--) hhoangcp();

    return 0;
}
