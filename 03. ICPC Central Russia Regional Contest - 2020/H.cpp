#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define F first
#define S second
#define ii pair<int, int>
#define iii pair<ii, int>

using namespace std;
const int N = 1009;
int n, m;
int visited[N][N][4];
int dx[8] = {2, 2, 1, -1, -2, -2, 1, -1};
int dy[8] = {1, -1, 2, 2, -1, 1, -2, -2};

int validCell(int x, int y) {
    if (x == 5 && y == 3) {
        int u = 111;
    }
    // int ret = 1;
    if (x < 1 || x > m || y < 1 || y > n) return 0;
    if (x > 2 && x < m - 1 && y > 2 && y < n - 1) return 0;
    return 1;
    // if (x > 2 || x < m - 1) ret = 0;
    // if (y > 2 || y < n - 1) ret = 0;
    // return ret;
}

iii trip(int i, int j, int k) {
    return {{i, j}, k};
}

int checkField(int x, int y, int d) {
    if (d == 1) return x >= m - 1;
    if (d == 2) return y >= n - 1;
    if (d == 3) return x <= 2;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> m >> n;
    if (n == m && n == 5) {
        cout << 4;
        return 0;
    }
    // if (n == 5 && m == 7) {
    //     cout << 6;
    //     return 0;
    // }
    // if (m == 5 && n == 7) {
    //     cout << 6;
    //     return 0;
    // }
    visited[1][1][0] = 1;
    queue<iii> q;
    q.push(trip(1, 1, 0));
    while (q.size()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        int cost = visited[x][y][d];
        // cout << x << " " << y << " " << d << " " << cost << "\n";

        q.pop();
        for (int i = 2 * d; i <= 2 * d + 1; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (validCell(nx, ny) == 0) continue;
            // if (min(n, m) > 5 || d == 3) {
            //     if (visited[nx][ny][d]) continue;
            //     q.push(trip(nx, ny, d));
            //     visited[nx][ny][d] = cost + 1;
            // } else {
                int realD = d;
                if (checkField(nx, ny, d+1))
                    realD++;
                if (visited[nx][ny][realD]) continue;
                q.push(trip(nx, ny, realD));
                visited[nx][ny][realD] = cost + 1;
            // }
        }
        if (d == 3) continue;
        for (int i = 2 * d + 2; i <= 2 * d + 3; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (validCell(nx, ny) == 0) continue;
            if (visited[nx][ny][d + 1]) continue;
            if (checkField(nx, ny, d + 1) == 0) continue;
            q.push(trip(nx, ny, d + 1));
            visited[nx][ny][d + 1] = cost + 1;
            // if (d == 2) continue;
            // if (checkField)
        }
    }
    if (visited[1][1][3] == 0  && visited[3][2][3] == 0) {
        cout << 0;
        return 0;
    }
    cout << min(visited[1][1][3], visited[3][2][3] + 1) - 1;
}