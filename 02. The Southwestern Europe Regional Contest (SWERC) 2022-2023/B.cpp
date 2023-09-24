#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(), (s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
ll memo[305][305];
int a[305];
int n, h;

ll dp(int l,int r){
    if (l == r) return memo[l][r] = h;
    ll& res = memo[l][r];
    if (res != -1) return res;
    res = ll(1e18) + 10;
    for (int m = l; m < r; m++){
        ll cost = max(h + 1 - (a[r] - a[l] + 1)/2,0);
        res = min(res,dp(l,m) + dp(m + 1,r) - cost);
    }
    return res;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> h;
    for (int i = 1; i <= n; i++) cin >> a[i];

    memset(memo,-1,sizeof(memo));
    cout << dp(1,n);
	return 0;
}
