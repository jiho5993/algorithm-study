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

int N, cnt;
int RGB[101][101];
int vis[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

queue<pii> q;

void BFS(int x, int y) {
    vis[x][y] = 1;
    q.push({x,y});
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        int now = RGB[x][y];
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < 100 && 0 <= ny && ny < 100) {
                if (now == RGB[nx][ny] && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }
    }
    cnt++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == 'R') {
                RGB[i][j] = 1;
            }
            else if (s[j] == 'G') {
                RGB[i][j] = 3;
            }
            else {
                RGB[i][j] = 2;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!vis[i][j]) BFS(i,j);
        }
    }
    cout << cnt << ' ';
    fill(vis[0],vis[0]+101*101,0);
    cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (RGB[i][j] == 3) RGB[i][j] = 1;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!vis[i][j]) BFS(i,j);
        }
    }
    cout << cnt;
    return 0;

}
