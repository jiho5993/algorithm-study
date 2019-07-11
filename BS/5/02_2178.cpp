#include <bits/stdc++.h>
#define mp make_pair
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

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int N, M;
queue<pii> q;
int visit[102][102];
int mat[102][102];

void BFS() {
    visit[1][1] = 1;
    q.push(mp(1, 1));
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (mat[nx][ny] > 0 && visit[nx][ny] == 0) {
                visit[nx][ny] = 1;
                mat[nx][ny] = mat[x][y] + 1;
                q.push(mp(nx,ny));
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
            mat[i+1][j+1] = s[j]-'0';
        }
    }

    BFS();

    cout << mat[N][M];

    return 0;
}
