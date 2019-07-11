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

int N, number=1;
int mat[101][101];
int vis[101][101];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

queue<pii> q;

int BFS(int a, int b, int c) {
    queue<pair<pii,int> > q2;
    fill(vis[0], vis[0]+101*101, 0);
    vis[a][b] = 1;
    q2.push({{a,b},0});
    while(!q2.empty()) {
        int x = q2.front().first.first;
        int y = q2.front().first.second;
        int now = q2.front().second;
        q2.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                if (mat[nx][ny] != c && mat[nx][ny]) return now;
                if (!vis[nx][ny] && !mat[nx][ny]) {
                    vis[nx][ny] = 1;
                    q2.push({{nx,ny},now+1});
                }
            }
        }
    }
    return INF;
}

void BFS_num(int x, int y) {
    vis[x][y] = 1;
    mat[x][y] = number;
    q.push({x,y});
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                if (!vis[nx][ny] && mat[nx][ny] == 1) {
                    vis[nx][ny] = 1;
                    mat[nx][ny] = number;
                    q.push({nx,ny});
                }
            }
        }
    }
    number++;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!vis[i][j] && mat[i][j] == 1) {
                BFS_num(i, j);
            }
        }
    }
    int res = INF;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mat[i][j]) {
                res = min(res, BFS(i, j, mat[i][j]));
            }
        }
    }
    return !(cout << res);
}
