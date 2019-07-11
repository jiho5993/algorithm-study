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

int C, R;

int mat[1501][1501];
int vis[1501][1501];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

vector<pii> swan;
vector<pii> melt;
queue<pii> q;

int BFS(int days) {
    while (!q.empty()) q.pop();
    fill(vis[0], vis[0] + 1501*1501, 0);
    pii start = swan[0];
    q.push(start);
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == swan[1].first && y == swan[1].second) return 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < C && 0 <= ny && ny < R) {
                if (!vis[nx][ny] && mat[nx][ny] <= days) {
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> C >> R;

    for (int i = 0; i < C; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < R; j++) {
            char t = s[j];
            if (t == 'L') {
                swan.pb({i,j});
            }
            else if (t == 'X') {
                mat[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++) {
            if (mat[i][j]) {
                bool check = false;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (0 <= ni && ni < C && 0 <= nj && nj < R) {
                        if (!mat[ni][nj]) {
                            check = true;
                            break;
                        }
                    }
                }
                if (check) {
                    vis[i][j] = 1;
                    q.push({i,j});
                }
            }
        }
    }
    int l = 0;
    int h = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (h < mat[x][y]) h = mat[x][y];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < C && 0 <= ny && ny < R) {
                if (!vis[nx][ny] && mat[nx][ny] == 1) {
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                    mat[nx][ny] = mat[x][y] + 1;
                }
            }
        }
    }

    int days = 0;
    while (l <= h) {
        int mid = (l+h)/2;
        int check = BFS(mid);
        if (check) {
            days = mid;
            h = mid - 1;
        }
        else l = mid + 1;
    }
    cout << days;
    return 0;
}
