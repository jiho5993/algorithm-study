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

int N, apt;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int mat[27][27];
int vis[27][27];
queue<pii> q;
vector<pii> v; 
vector<int> apts;

void BFS(int x, int y) {
    int n = 0;
    vis[x][y] = 1;
    q.push({x,y});
    while(!q.empty()) {
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
    apt++;
    apts.pb(n);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= s.length(); j++) {
            if (s[j-1] == '1') {
                mat[i][j] = 1;
                v.pb({i,j});
            }
        }
    }
    for (int i = 0; i < v.size(); i++) {
        if (!vis[v[i].first][v[i].second]) {
            BFS(v[i].first, v[i].second);
        }
    }
    sort(apts.begin(), apts.end());
    cout << apt << '\n';
    for (int i = 0; i < apts.size(); i++) {
        cout << apts[i] << '\n';
    } 
    
    return 0;
}
