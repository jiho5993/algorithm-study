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

int N, M;
int mat[101][101];
int vis[101][101];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

queue<pii> q;
vector<pii> v[101][101];

void BFS() {
    vis[1][1] = 1;
    q.push({1,1});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < v[x][y].size(); i++) {
            int nx = v[x][y][i].first;
            int ny = v[x][y][i].second;
            if (!mat[nx][ny]) {
                fill(vis[0], vis[0] + 101*101, 0);
            }
            mat[nx][ny] = 1;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                if (!vis[nx][ny] && mat[nx][ny]) {
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    while (M--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        v[x][y].pb({a,b});
    }
    mat[1][1] = 1;
    BFS();
    int res = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (mat[i][j]) res++;
        }
    }
    cout << res;
    
    return 0;
}
