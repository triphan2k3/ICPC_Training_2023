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
const ll MX = 100101;
int nx[MX][26], cur[26], pr[MX][26], cur2[26];
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    string bs = "spbsu";
    int ans = 1e9;
    for(int i=0; i<26; i++) {
        cur[i] = -1; cur2[i] = -1;
        for(int j=0; j<=n; j++) {
            nx[j][i] = -1;
            pr[j][i] = -1;
        }
    }
    for(int i=s.size()-1; i>=0; i--) {
        cur[s[i]-'a'] = i;
        for(int j=0; j<26; j++) nx[i][j] = cur[j];
    }
    for(int i=0; i<s.size(); i++) {
        cur2[s[i]-'a'] = i;
        for(int j=0; j<26; j++) pr[i][j] = cur2[j];
    }
    for(int i=0; i<s.size(); i++) {
        if(s[i] == 'b') {
            int p = i, q = i;
            vector<int> vt; vt.clear();
            for(int j=2; j>=0; j--) {
                p = pr[p][bs[j]-'a'];
                //cout << p << endl;
                vt.pb(p);
                if(p == -1) break;
            }
            reverse(vt.begin(), vt.end());
            for(int j=3; j<=4; j++) {
                q = nx[q][bs[j]-'a'];
                vt.pb(q);
                if(q == -1) break;
            }
            int kq = 0;
            if(p != -1 && q != -1) {
                for(int u=0; u<5; u++) {
                    kq = kq + abs(vt[u]-(vt[2]+(u-2)));
                }
                ans = min(ans, kq);
            }
        }
    }
    cout << ans << endl;
}
int main () {
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("cf.inp", "r", stdin); freopen("cf.out", "w", stdout);
	//cin >> tc; while(tc--)
	solve();
}