#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;

const int INF = 2147483648;
const int MOD = 1000000007;
const double PI = acos(-1);

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, m, cnt, all;
int visit[502][502];
int mat[502][502];
queue<pii> q;

void BFS(int x, int y) {
    int n = 0;
    cnt++;
    visit[x][y] = 1;
    q.push(mp(x, y));
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        n++;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!visit[nx][ny] && mat[nx][ny]) {
                visit[nx][ny] = 1;
                q.push(mp(nx, ny));
            }
        }
    }
    if (all<n) all = n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int t;
            cin >> t;
            if(t) mat[i][j] = t;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mat[i][j] && !visit[i][j]) {
                BFS(i, j);
            }
        }
    }

    cout << cnt << '\n' << all;
    return 0;
}
