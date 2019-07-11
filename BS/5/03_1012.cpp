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

int T;
int mat[52][52], vis[52][52];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pii> q;

void BFS(int x, int y) {
    vis[x][y] = 1;
    q.push({x, y});
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (mat[nx][ny] && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        vector<pii> v;
        fill(mat[0], mat[0]+52*52, 0);
        fill(vis[0], vis[0]+52*52, 0);
        int M, N, K, cnt = 0;
        cin >> M >> N >> K;
        while (K--) {
            int x, y;
            cin >> x >> y;
            mat[x+1][y+1] = 1;
            v.pb({x+1, y+1});
        }
        for (int i = 0; i < v.size(); i++) {
            int x = v[i].first;
            int y = v[i].second;
            if (!vis[x][y]) {
                BFS(x,y);
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
   
    return 0;
}
