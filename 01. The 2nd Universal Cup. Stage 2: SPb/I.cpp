#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

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
const ll MX = 30101;
void solve() {
    int n; cin >> n;
    int ans;
    if(n%2 == 0) {
        int fr = n/2;
        ans = (fr+2)/3; ans *= 2;
    }
    else {
        int fr = n/2+1;
        ans = (fr+2)/3; ans += ans-1;
    }
    cout << ans << " " << n << endl;
}
int main (){
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("cf.inp", "r", stdin); freopen("cf.out", "w", stdout);
	//cin >> tc; while(tc--)
	solve();
}