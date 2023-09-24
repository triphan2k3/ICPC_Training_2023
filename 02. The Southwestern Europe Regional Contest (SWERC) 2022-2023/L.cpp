/// hhoangcp

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <climits>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <array>
#include <stack>
#include <assert.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define llong long long
#define ullong unsigned llong
#define ldouble long double
#define uint unsigned int
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define ft first
#define sd second
#define all(x) x.begin(), x.end()

using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> pii;
typedef pair<llong, int> pli;
typedef pair<int, llong> pil;
typedef pair<llong, llong> pll;
typedef tuple<int, int, int> tiii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<llong, null_type, less<llong>, rb_tree_tag, tree_order_statistics_node_update> ordered_setll;
typedef tree<ldouble, null_type, less<ldouble>, rb_tree_tag, tree_order_statistics_node_update> ordered_setld;

template<typename _type_>
void readInt(_type_ &num) {
    char c = getchar();
    while (c != '-' && ('0' > c || c > '9')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true, c = getchar();
    for(num = 0; '0' <= c && c <= '9'; c = getchar()) num = (num << 1) + (num << 3) + (c - '0');
    if (neg) num = -num;
}

template<typename _type_>
void writeInt(_type_ num) {
    if (num < 0) {
        putchar('-');
        writeInt(-num);
        return;
    }

    if (num > 9) writeInt(num / 10);
    putchar(num % 10 + '0');
}

template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template <class T> bool chmin(T &t, const T &f) { if (t > f) { t = f; return true; } return false; }
template <class T> bool chmax(T &t, const T &f) { if (t < f) { t = f; return true; } return false; }

template<unsigned mod_>
struct mint {
    static constexpr unsigned mod = mod_;
    unsigned x;
    constexpr mint() : x(0U) {}
    constexpr mint(unsigned x_) : x(x_ % mod) {}
    constexpr mint(ullong x_) : x(x_ % mod) {}
    constexpr mint(int x_) : x(((x_ %= static_cast<int>(mod)) < 0) ? (x_ + static_cast<int>(mod)) : x_) {}
    constexpr mint(llong x_) : x(((x_ %= static_cast<llong>(mod)) < 0) ? (x_ + static_cast<llong>(mod)) : x_) {}
    mint &operator += (const mint &a) { x = ((x += a.x) >= mod) ? (x - mod) : x; return *this; }
    mint &operator -= (const mint &a) { x = ((x -= a.x) >= mod) ? (x + mod) : x; return *this; }
    mint &operator *= (const mint &a) { x = (static_cast<ullong>(x) * a.x) % mod; return *this; }
    mint &operator /= (const mint &a) { return (*this *= a.inv()); }
    mint pow(llong e) const {
        if (e < 0) return inv().pow(-e);
        mint a = *this, b = 1U; for (; e; e >>= 1) { if (e & 1) b *= a; a *= a; } return b;
    }

    mint inv() const {
        unsigned a = mod, b = x; int y = 0, z = 1;
        for (; b; ) { const unsigned q = a / b; const unsigned c = a - q * b; a = b; b = c; const int w = y - static_cast<int>(q) * z; y = z; z = w; }
        assert(a == 1U); return mint(y);
    }

    mint operator + () const { return *this; }
    mint operator - () const { mint a; a.x = x ? (mod - x) : 0U; return a; }
    mint operator + (const mint &a) const { return (mint(*this) += a); }
    mint operator - (const mint &a) const { return (mint(*this) -= a); }
    mint operator * (const mint &a) const { return (mint(*this) *= a); }
    mint operator / (const mint &a) const { return (mint(*this) /= a); }
    template <class T> friend mint operator + (T a, const mint &b) { return (mint(a) += b); }
    template <class T> friend mint operator - (T a, const mint &b) { return (mint(a) -= b); }
    template <class T> friend mint operator * (T a, const mint &b) { return (mint(a) *= b); }
    template <class T> friend mint operator / (T a, const mint &b) { return (mint(a) /= b); }
    explicit operator bool() const { return x; }
    bool operator == (const mint &a) const { return (x == a.x); }
    bool operator != (const mint &a) const { return (x != a.x); }
    friend std::ostream &operator << (std::ostream &os, const mint &a) { return os << a.x; }
};

/// PRIME < 2^32
template <unsigned PRIME> struct proth_prime {};
template <> struct proth_prime<1224736769> { static constexpr int a =             73, b = 24, g =  3; };
template <> struct proth_prime<1053818881> { static constexpr int a =     3 * 5 * 67, b = 20, g =  7; };
template <> struct proth_prime<1051721729> { static constexpr int a =        17 * 59, b = 20, g =  6; };
template <> struct proth_prime<1045430273> { static constexpr int a =            997, b = 20, g =  3; };
template <> struct proth_prime<1012924417> { static constexpr int a =     3 * 7 * 23, b = 21, g =  5; };
template <> struct proth_prime<1007681537> { static constexpr int a =        31 * 31, b = 20, g =  3; };
template <> struct proth_prime<1004535809> { static constexpr int a =            479, b = 21, g =  3; };
template <> struct proth_prime< 998244353> { static constexpr int a =         7 * 17, b = 23, g =  3; };
template <> struct proth_prime< 985661441> { static constexpr int a =         5 * 47, b = 22, g =  3; };
template <> struct proth_prime< 976224257> { static constexpr int a =     7 * 7 * 19, b = 20, g =  3; };
template <> struct proth_prime< 975175681> { static constexpr int a =     3 * 5 * 31, b = 21, g = 17; };
template <> struct proth_prime< 962592769> { static constexpr int a = 3 * 3 * 3 * 17, b = 21, g =  7; };
template <> struct proth_prime< 950009857> { static constexpr int a =        4 * 151, b = 21, g =  7; };
template <> struct proth_prime< 943718401> { static constexpr int a =  3 * 3 * 5 * 5, b = 22, g =  7; };
template <> struct proth_prime< 935329793> { static constexpr int a =            223, b = 22, g =  3; };
template <> struct proth_prime< 924844033> { static constexpr int a =  3 * 3 * 7 * 7, b = 21, g =  5; };
template <> struct proth_prime< 918552577> { static constexpr int a =         3 * 73, b = 22, g =  5; };
template <> struct proth_prime< 469762049> { static constexpr int a =              7, b = 26, g =  3; };
template <> struct proth_prime< 167772161> { static constexpr int a =              5, b = 25, g =  3; };

constexpr unsigned mod[5] = {998244353, 985661441, 943718401, 935329793, 918552577};
constexpr unsigned MOD = 1000000007, PHI = 1000000006;

int pos = 0, neg = 0;

void hhoangcp() {
    int n; cin >> n;
    string s; cin >> s;
    for(char c: s) if (c == '+') ++pos; else ++neg;
    int delta = pos - neg;

    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b;
        if (a == b) {
            if (pos != neg) cout << "NO\n";
            else cout << "YES\n";

            continue;
        }

        llong lcm = 1LL * a * b / __gcd(a, b);
        llong c = lcm / a, d = lcm / b;

        if (delta % (c - d) == 0) {
            int t = delta / (c - d);
            c *= t;
            d *= t; d *= -1;

            bool ok = true;
            if (c < 0) ok &= -c <= neg;
            else ok &= c <= pos;

            if (d < 0) ok &= -d <= neg;
            else ok &= d <= pos;

            if (ok) cout << "YES\n";
            else cout << "NO\n";
        } else cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int tests = 1; //cin >> tests;
    while (tests--) hhoangcp();

    return 0;
}

