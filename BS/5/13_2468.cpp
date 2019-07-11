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

int N, small = INF, big;
int mat[101][101];
int vis[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pii> q;

void BFS(int h, int x, int y)  {
    vis[x][y] = 1;
    q.push({x,y});
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                if (mat[nx][ny]-h > 0 && !vis[nx][ny]) {
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
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int t;
            cin >> t;
            if (small > t) small = t;
            if (big < t) big = t;
            mat[i][j] = t;
        }
    }
    int m = 0;
    for (int i = small; i <= big; i++) {
        int cnt = 0;
        for (int j = 0; j < N ; j++) {
            for (int k = 0; k < N; k++) {
                if (mat[j][k]-i > 0 && !vis[j][k]) {
                    BFS(i, j, k); cnt++;
                }
            }
        }
        if (m < cnt) m = cnt;
        fill(vis[0], vis[0] + 101*101, 0);
    }
    if (m == 0) m = 1;
    cout << m;
    return 0;
}
