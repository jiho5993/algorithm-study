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

int K, H, W, m=INF;
int mat[202][202];
int vis[31][202][202];
int dx[12] = {1,0,-1,0,1,1,2,2,-1,-1,-2,-2};
int dy[12] = {0,1,0,-1,2,-2,1,-1,2,-2,1,-1};

queue<pair<pii, pii> > q;

int BFS(int x, int y) {
    q.push({{0,0},{x,y}});
    vis[0][x][y] = 1;
    while (!q.empty()) {
        int cnt = q.front().first.first;
        int now = q.front().first.second;
        x = q.front().second.first;
        y = q.front().second.second;
        q.pop();
        if (x == H && y == W) return now;
        for (int i = 0; i < 12; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 < nx && nx <= H && 0 < ny && ny <= W) {
                if (!mat[nx][ny]) {
                    if (i < 4 && !vis[cnt][nx][ny]) {
                        vis[cnt][nx][ny] = 1;
                        q.push({{cnt,now+1},{nx,ny}});
                    }
                    else if (i >= 4 && !vis[cnt+1][nx][ny]) {
                        if (cnt < K) {
                            vis[cnt+1][nx][ny] = 1;
                            q.push({{cnt+1,now+1},{nx,ny}});
                        }
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> K >> W >> H;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> mat[i][j];
        }
    }
    cout << BFS(1,1);
    return 0;
}
