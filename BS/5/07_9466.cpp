#include <bits/stdc++.h>
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;

const int INF = 2147483647;
const int MOD = 1000000007;
const double PI = acos(-1);

int T, n;
int mat[100001];
int vis[100001];
int cycle[100001];
int check[100001];

void dfs(int now) {
    vis[now] = 1;
    int next = mat[now];
    if (vis[next]) {
        if (!check[next]) {
            while (next != now) {
                cycle[next] = 1;
                next = mat[next];
            }
            cycle[now] = 1;
        }
    }
    else dfs(next);
    check[now] = 1;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> mat[i];
        }

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfs(i);
            }
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!cycle[i]) cnt++;
        }
        cout << cnt << '\n';
        fill(mat, mat + n + 1, 0);
        fill(vis, vis + n + 1, 0);
        fill(check, check + n + 1, 0);
        fill(cycle, cycle + n + 1, 0);
    }
    return 0;
}
