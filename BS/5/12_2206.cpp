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

int N, M;
int mat[1001][1001];
int vis[2][1001][1001];
int cnt[2][1001][1001];
queue<pair<int, pii> > q;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void BFS(int bc, int x, int y) {
    cnt[bc][x][y] = 1;
    vis[bc][x][y] = 1;
    q.push({bc,{x,y}});
    while (!q.empty()) {
        bc = q.front().first;
        x = q.front().second.first;
        y = q.front().second.second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (mat[nx][ny] == 1) {
                    if (bc == 0) {
                        if (!vis[1][nx][ny]) {
                            vis[1][nx][ny] = 1;
                            cnt[1][nx][ny] = cnt[0][x][y] + 1;
                            q.push({1,{nx,ny}});
                        }
                    }
                }
                else {
                    if (!vis[bc][nx][ny]) {
                        vis[bc][nx][ny] = 1;
                        cnt[bc][nx][ny] = cnt[bc][x][y] + 1;
                        q.push({bc,{nx,ny}});
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            mat[i][j] = s[j] - '0';
        }
    }
    BFS(0,0,0);
    int a = cnt[1][N-1][M-1], b = cnt[0][N-1][M-1];
    int res;
    if (a && b) res = min(a,b);
    else {
        if (a || b) {
            res = max(a,b);
        }
        else {
            res = -1;
        }
    }
    return !(cout << res);
}
