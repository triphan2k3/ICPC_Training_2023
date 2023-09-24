/// hhoangcp

#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

void hhoangcp() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a += c;
    b += d;
    string ans;
    if (a > b) ans = "A";
    else if (b > a) ans = "P";
    else ans = "D";
    cout << ans;
}

int main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int tests = 1; //cin >> tests;
    while (tests--) hhoangcp();

    return 0;
}
