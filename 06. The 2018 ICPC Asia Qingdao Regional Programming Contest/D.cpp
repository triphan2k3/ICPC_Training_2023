#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> chk[106];

void init() {
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            chk[i * j].push_back({i, j});
}

char a[1000006], b[1000006];

void Excalibur() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int t = s.size();

    if (s[0] == '0') {
        if (s == "0" && n == 1 && m == 1)
            cout << "0 0\n";
        else
            cout << "Impossible\n";
        return;
    }

    bool ok = false;
    pair<int, int> ans = {10, 10};
    int bit = 0;
    for (pair<int, int> p : chk[s[0] - '0']) {
        ok = true;

        a[1] = p.first + '0';
        b[1] = p.second + '0';
        int curr = 1, i = 1, j = 1;
        for (; curr < t && ok && j < m; ++curr) {
            if ((s[curr] == '0' || s[curr] >= a[1]) &&
                (s[curr] - '0') % (a[1] - '0') == 0) {
                b[++j] = (s[curr] - '0') / (a[1] - '0') + '0';
            } else if (curr < t - 1 && s[curr] != '0' && s[curr] < a[1] &&
                       ((s[curr] - '0') * 10 + (s[curr + 1] - '0')) %
                               (a[1] - '0') ==
                           0) {
                b[++j] = ((s[curr] - '0') * 10 + (s[curr + 1] - '0')) /
                             (a[1] - '0') +
                         '0';
                ++curr;
            } else
                ok = false;
        }

        ok &= j == m;
        if (!ok)
            continue;

        int tt = 1;
        for (; curr < t && ok; ++curr)
            if (tt == 1) {
                if (i < n && (s[curr] == '0' || s[curr] >= b[1]) &&
                    (s[curr] - '0') % (b[1] - '0') == 0) {
                    a[++i] = (s[curr] - '0') / (b[1] - '0') + '0';
                    ++tt;
                    if (tt > m)
                        tt -= m;
                } else if (i < n && curr < t - 1 && s[curr] != '0' &&
                           s[curr] < b[1] &&
                           ((s[curr] - '0') * 10 + (s[curr + 1] - '0')) %
                                   (b[1] - '0') ==
                               0) {
                    a[++i] = ((s[curr] - '0') * 10 + (s[curr + 1] - '0')) /
                                 (b[1] - '0') +
                             '0';

                    ++curr;
                    ++tt;
                    if (tt > m)
                        tt -= m;
                } else
                    ok = false;
            } else {
                if ((s[curr] == '0' || s[curr] >= b[tt]) &&
                    (a[i] - '0') * (b[tt] - '0') == (s[curr] - '0')) {
                    ++tt;
                    if (tt > m)
                        tt -= m;
                } else if (curr < t - 1 && s[curr] != '0' && s[curr] < b[tt] &&
                           ((s[curr] - '0') * 10 + (s[curr + 1] - '0')) ==
                               (a[i] - '0') * (b[tt] - '0')) {
                    ++curr;
                    ++tt;
                    if (tt > m)
                        tt -= m;
                } else
                    ok = false;
            }

        ok &= i == n && tt == 1 && curr == t;

        if (ok) {
            if (ans.first > a[1] - '0' ||
                (ans.first == a[1] - '0' && ans.second > b[1] - '0')) {
                ans = {a[1] - '0', b[1] - '0'};
                bit = 0;
            }
        }
    }

    if (t > 1 && s[0] != '0') {
        for (pair<int, int> p : chk[(s[0] - '0') * 10 + (s[1] - '0')]) {
            ok = true;

            a[1] = p.first + '0';
            b[1] = p.second + '0';
            int curr = 2, i = 1, j = 1;
            for (; curr < t && ok && j < m; ++curr) {
                if ((s[curr] == '0' || s[curr] >= a[1]) &&
                    (s[curr] - '0') % (a[1] - '0') == 0) {
                    b[++j] = (s[curr] - '0') / (a[1] - '0') + '0';
                } else if (curr < t - 1 && s[curr] != '0' && s[curr] < a[1] &&
                           ((s[curr] - '0') * 10 + (s[curr + 1] - '0')) %
                                   (a[1] - '0') ==
                               0) {
                    b[++j] = ((s[curr] - '0') * 10 + (s[curr + 1] - '0')) /
                                 (a[1] - '0') +
                             '0';
                    ++curr;
                } else
                    ok = false;
            }

            ok &= j == m;
            if (!ok)
                continue;

            int tt = 1;
            for (; curr < t && ok; ++curr)
                if (tt == 1) {
                    if (i < n && (s[curr] == '0' || s[curr] >= b[1]) &&
                        (s[curr] - '0') % (b[1] - '0') == 0) {
                        a[++i] = (s[curr] - '0') / (b[1] - '0') + '0';
                        ++tt;
                        if (tt > m)
                            tt -= m;
                    } else if (i < n && curr < t - 1 && s[curr] != '0' &&
                               s[curr] < b[1] &&
                               ((s[curr] - '0') * 10 + (s[curr + 1] - '0')) %
                                       (b[1] - '0') ==
                                   0) {
                        a[++i] = ((s[curr] - '0') * 10 + (s[curr + 1] - '0')) /
                                     (b[1] - '0') +
                                 '0';

                        ++curr;
                        ++tt;
                        if (tt > m)
                            tt -= m;
                    } else
                        ok = false;
                } else {
                    if ((s[curr] == '0' || s[curr] >= b[tt]) &&
                        (a[i] - '0') * (b[tt] - '0') == (s[curr] - '0')) {
                        ++tt;
                        if (tt > m)
                            tt -= m;
                    } else if (curr < t - 1 && s[curr] != '0' &&
                               s[curr] < b[tt] &&
                               ((s[curr] - '0') * 10 + (s[curr + 1] - '0')) ==
                                   (a[i] - '0') * (b[tt] - '0')) {
                        ++curr;
                        ++tt;
                        if (tt > m)
                            tt -= m;
                    } else
                        ok = false;
                }

            ok &= i == n && tt == 1 && curr == t;

            if (ok) {
                if (ans.first > a[1] - '0' ||
                    (ans.first == a[1] - '0' && ans.second > b[1] - '0')) {
                    ans = {a[1] - '0', b[1] - '0'};
                    bit = 1;
                }
            }
        }
    }

    if (ans.first == 10)
        cout << "Impossible\n";
    else {
        a[1] = ans.first + '0';
        b[1] = ans.second + '0';
        int curr = bit + 1, i = 1, j = 1;
        for (; curr < t && j < m; ++curr) {
            if ((s[curr] == '0' || s[curr] >= a[1]) &&
                (s[curr] - '0') % (a[1] - '0') == 0) {
                b[++j] = (s[curr] - '0') / (a[1] - '0') + '0';
            } else if (curr < t - 1 && s[curr] != '0' && s[curr] < a[1] &&
                       ((s[curr] - '0') * 10 + (s[curr + 1] - '0')) %
                               (a[1] - '0') ==
                           0) {
                b[++j] = ((s[curr] - '0') * 10 + (s[curr + 1] - '0')) /
                             (a[1] - '0') +
                         '0';
                ++curr;
            }
        }

        int tt = 1;
        for (; curr < t; ++curr)
            if (tt == 1) {
                if (i < n && (s[curr] == '0' || s[curr] >= b[1]) &&
                    (s[curr] - '0') % (b[1] - '0') == 0) {
                    a[++i] = (s[curr] - '0') / (b[1] - '0') + '0';
                    ++tt;
                    if (tt > m)
                        tt -= m;
                } else if (i < n && curr < t - 1 && s[curr] != '0' &&
                           s[curr] < b[1] &&
                           ((s[curr] - '0') * 10 + (s[curr + 1] - '0')) %
                                   (b[1] - '0') ==
                               0) {
                    a[++i] = ((s[curr] - '0') * 10 + (s[curr + 1] - '0')) /
                                 (b[1] - '0') +
                             '0';

                    ++curr;
                    ++tt;
                    if (tt > m)
                        tt -= m;
                }
            } else {
                if ((s[curr] == '0' || s[curr] >= b[tt]) &&
                    (a[i] - '0') * (b[tt] - '0') == (s[curr] - '0')) {
                    ++tt;
                    if (tt > m)
                        tt -= m;
                } else if (curr < t - 1 && s[curr] != '0' && s[curr] < b[tt] &&
                           ((s[curr] - '0') * 10 + (s[curr + 1] - '0')) ==
                               (a[i] - '0') * (b[tt] - '0')) {
                    ++curr;
                    ++tt;
                    if (tt > m)
                        tt -= m;
                }
            }

        for (int i = 1; i <= n; ++i)
            cout << a[i];
        cout << ' ';
        for (int i = 1; i <= m; ++i)
            cout << b[i];
        cout << '\n';
    }
}

int main() {
    init();

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int tests = 1;
    cin >> tests;
    while (tests--)
        Excalibur();

    return 0;
}