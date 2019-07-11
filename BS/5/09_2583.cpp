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

int M,N,K,cnt;
bool mat[102][102];
int vis[102][102];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

queue<pii> q;
vector<int> cnts;

void BFS(int x, int y) {
    int n = 0;
    vis[x][y] = 1;
    q.push({x,y});
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop(); n++;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (mat[nx][ny] && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
    cnt++;
    cnts.pb(n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N >> K;
    while (K--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = y1+1; i <= y2; i++) {
            for (int j = x1+1; j <= x2; j++) {
                mat[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= M; i++ ) {
        for (int j = 1; j <= N; j++) {
             mat[i][j] = (mat[i][j]+1) % 2;
        }
    }
    for (int i = 1; i <= M; i++ ) {
        for (int j = 1; j <= N; j++) {
            if (mat[i][j] && !vis[i][j]) {
                BFS(i, j);
            }
        }
    }
    cout << cnt << '\n';
    sort(cnts.begin(), cnts.end());
    for (int i = 0; i < cnts.size(); i++) {
        cout << cnts[i] << ' ';
    }
    return 0;
}
