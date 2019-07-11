#include <bits/stdc++.h>
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

int T, n;
int vis[302][302];
int dx[8] = {1,1,2,2,-1,-1,-2,-2};
int dy[8] = {2,-2,1,-1,2,-2,1,-1};

queue<pii> q;

void BFS(int x, int y) {
    vis[x][y] = 1;
    q.push({x,y});
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx > 0 && ny > 0 && nx <= n && ny <= n) {
                if (!vis[nx][ny]) {
                    vis[nx][ny] = vis[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        int sx, sy, tx, ty;
        cin >> sx >> sy >> tx >> ty;
        sx++; sy++; tx++; ty++;
        BFS(sx, sy);
        cout << vis[tx][ty]-1 << '\n'; 
        fill(vis[0], vis[0] + 302*302, 0);
    }
    return 0;
}
