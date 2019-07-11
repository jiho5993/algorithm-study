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
int dx[6] = {1,0,0,-1,0,0};
int dy[6] = {0,1,0,0,-1,0};
int dz[6] = {0,0,1,0,0,-1};

int M, N, H;
int mat[100][100][100];
queue<pair<pii,int> > q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                int t;
                cin >> t;
                if (t == 1) q.push({{i,j},k});
                mat[i][j][k] = t;
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().first.second;
        int y = q.front().second;
        int z = q.front().first.first;
        q.pop();
        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && nz >=0 && nz < H) {
                if (mat[nz][nx][ny] == 0) {
                    mat[nz][nx][ny] = mat[z][x][y] + 1;
                    q.push({{nz, nx}, ny});
                }
            }
        }
    }
    int max = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (!mat[i][j][k]) return !(cout << -1);
                if (max<mat[i][j][k]) max=mat[i][j][k];
            }
        }
    }
    return !(cout << max-1);
}
