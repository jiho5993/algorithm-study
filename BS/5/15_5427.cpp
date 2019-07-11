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

int T, w, h;

int mat[1003][1003];
int fire[1003][1003];
int vis[1003][1003];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

pii man;
queue<pii> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--) {
        cin >> w >> h;
        for (int i = 1; i <= h; i++) {
            string s;
            cin >> s;
            for (int j = 1; j <= w; j++) {
                if (s[j-1] == '#') {
                    mat[i][j] = -1; fire[i][j] = -1;
                }
                else if(s[j-1] == '*') {
                    fire[i][j] = 1;
                    q.push({i,j});
                }
                else if (s[j-1] == '@') {
                    mat[i][j] = 1;
                    man = {i,j};
                }
            }
        }
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (0 < nx && nx <= h && 0 < ny && ny <= w) {
                    if (!vis[nx][ny] && !fire[nx][ny]) {
                        vis[nx][ny] = 1;
                        fire[nx][ny] = fire[x][y] + 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        fill(vis[0], vis[0]+1002*1002, 0);
        q.push(man);
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (0 < nx && nx <= h && 0 < ny && ny <= w) {
                    if (!vis[nx][ny] && mat[nx][ny] == 0 && (mat[x][y] + 1 < fire[nx][ny] || !fire[nx][ny])) {
                        vis[nx][ny] = 1;
                        mat[nx][ny] = mat[x][y] + 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        int min = INF;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (i==1 || j == 1 || i == h || j == w) {
                    if (mat[i][j] > 0) {
                        if (min > mat[i][j]) min = mat[i][j];
                    }
                }
            }
        }
        if (min == INF) cout << "IMPOSSIBLE\n";
        else cout << min << '\n';
        fill(vis[0], vis[0]+1002*1002, 0);
        fill(mat[0], mat[0]+1002*1002, 0);
        fill(fire[0], fire[0]+1002*1002, 0);
    }
    return 0;
}
