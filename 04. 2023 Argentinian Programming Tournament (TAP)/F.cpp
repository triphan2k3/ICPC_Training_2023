/// hhoangcp

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, W, L, Tx, Ty;

double dis(int x, int y) {
    ll u = (Tx - x) * (Tx- x) + (Ty - y) * (Ty - y);
    return sqrt(u);
}

void hhoangcp() {
    cin >> n;
    cin >> W >> L >> Tx >> Ty;
    vector<double> distA, distB;
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        distA.push_back(dis(x, y));
    }

    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        distB.push_back(dis(x, y));
    }
    sort(distA.begin(), distA.end());
    sort(distB.begin(), distB.end());
    if (distA[0] < distB[0]) {
        cout << "A ";
        int cnt = 0;
        for (int i = 0; i < distA.size(); i++)
            if (distA[i] < distB[0])
                ++cnt;
        cout << cnt;
    } else {
        cout << "R ";
        int cnt = 0;
        for (int i = 0; i < distB.size(); i++)
            if (distB[i] < distA[0])
                ++cnt;
        cout << cnt;
    }

}

int main() {

    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int tests = 1; //cin >> tests;
    while (tests--) hhoangcp();

    return 0;
}
