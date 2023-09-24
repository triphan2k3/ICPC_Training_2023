/// hhoangcp

#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;
ll A, S, L, R;
ll cal(ll i, ll D) {
    ll d = -1;
    for(ll l=1, r=1e5; l <= r;) {
        ll mid = l + (r-l)/2;
        if((mid+1)*i*2 + mid*(mid+1)*D <= 2 * S) {
            d = mid; l = mid+1;
        }
        else r = mid-1;
    }

    if (d < 0) return 0;
    if(i + d*D < A) return 0;
    if(i + d*D > R) return 0;
    if((d+1)*i*2 + d*(d+1)*D == 2*S) return 1;
    return 0;
}
void hhoangcp() {
    cin >> A >> S >> L >> R;
    ll ans = 0;
    for(ll i=L; i<A; i++) {
        for(ll D=1; D*D <= A-i; D++)
        if ((A - i) % D == 0) {
            if(D*D == A-i) ans += cal(i, D);
            else {
                    ans += cal(i, (A-i)/D);
                    ans += cal(i, D);
            }
        }
    }
    for(ll i=1; i<=R-A; i++) ans += cal(A, i);
    cout << ans + (S == A) << endl;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int tests = 1; //cin >> tests;
    while (tests--) hhoangcp();

    return 0;
}
