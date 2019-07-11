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

int L, R, C;
int mat[32][32][32];
int vis[32][32][32];

int dx[6] = {1,0,0,-1,0,0};
int dy[6] = {0,1,0,0,-1,0};
int dz[6] = {0,0,1,0,0,-1};

pair<int, pii> start, e;
queue<pair<pii, pii> > q;

int BFS(int x, int y, int z) {
    vis[z][x][y] = 1;
    q.push({{x,y},{z,0}});
    while (!q.empty()) {
        x = q.front().first.first;
        y = q.front().first.second;
        z = q.front().second.first;
        int now = q.front().second.second;
        q.pop();
        if (z == e.first && x == e.second.first && y == e.second.second) return now;
        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if (0 <= nz && nz < L && 0 <= nx && nx < R && 0 <= ny && ny < C) {
                if (!vis[nz][nx][ny] && !mat[nz][nx][ny]) {
                    vis[nz][nx][ny] = 1;
                    q.push({{nx,ny},{nz,now+1}});
                }
            }
        }
    }
    return -1;
}

int main() {
    while (1) {
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0)break;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                string s;
                cin >> s;
                for (int k = 0; k < C; k++) {
                    char w = s[k];
                    if (w == 'S') start = {i,{j,k}};
                    else if (w == 'E') e = {i,{j,k}};
                    else if (w == '#') mat[i][j][k] = -1;
                }
            }
        }
        int res = BFS(start.second.first, start.second.second, start.first);
        if (res == -1) cout << "Trapped!\n";
        else cout << "Escaped in " << res << " minute(s).\n";
        while (!q.empty()) q.pop();
        fill(vis[0][0],vis[0][0]+32*32*32,0);
        fill(mat[0][0],mat[0][0]+32*32*32,0);
    }
    return 0;
}
