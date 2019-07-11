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
int mat[302][302];
int vis[302][302];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

queue<pii> q;
vector<pair<int, pii> > v;

void BFS(int x, int y) {
    vis[x][y] = 1;
    q.push({x,y});
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (mat[nx][ny] && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++) {
            cin >> mat[i][j];
            if (mat[i][j]) q.push({i,j});
        }      
    }
    int time = 0;
    int sets = 0;
    while(!q.empty()) {
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int cnt = 0;
            for (int i = 0 ; i < 4; i++) {
                int cx = x + dx[i];
                int cy = y + dy[i];
                if (mat[cx][cy] == 0) cnt++;
            }
            v.pb({cnt,{x,y}});
        }
        for (int i = 0; i < v.size(); i++) {
            int x = v[i].second.first;
            int y = v[i].second.second;
            if (!vis[x][y]) {
                BFS(x, y);
                sets++;
                if (sets > 1) {
                    return !(cout << time);
                }
            }
        }
        for (int i = 0; i < v.size(); i++) {
            int cnt = v[i].first;
            int x = v[i].second.first;
            int y = v[i].second.second;
            if (mat[x][y]-cnt <= 0) mat[x][y] = 0;
            else {
                mat[x][y] -= cnt;
                q.push({x,y});
            }
        }
        time++;
        fill(vis[0], vis[0]+302*302, 0);
        v.clear();
        sets = 0;
    }
    return !(cout << 0);
}
