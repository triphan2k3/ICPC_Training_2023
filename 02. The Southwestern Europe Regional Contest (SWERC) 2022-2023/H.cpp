#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front

string alp = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
const ll pd = 998244353; //1e9+7
ll oo = 1e18 + 1, tc;
const ll MX = 200101;
int a[MX], b[MX], ok[MX], vt[MX];
void solve() {
	int n; cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=n; i++) {
		cin >> b[i];
		vt[b[i]] = i;
	}
    int cnt = 0;
    for (int i = n; i >= 1; i--) {
        if (a[i] == b[n - cnt]) {
            ++cnt;
        }
    }
    cout << n - cnt << "\n";
    return;
	for(int i=1; i<=n; i++) {
		ok[i] = 0;
	}

	int dem = 0, l=1;
	for(int i=1; i<=n; i++) {
		int p = a[i];
		if(ok[p]) continue;
		for(int j=l; j<vt[p]; j++) {
			dem += 1;
			ok[b[j]] = 1;
		}
		ok[p] = 1;
		l = vt[p] + 1;
	}
	cout << dem << endl;
}
int main (){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("cf.inp", "r", stdin); freopen("cf.out", "w", stdout);
	cin >> tc; while(tc--)
	solve();
}