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

int M, N;
int mat[1000][1000];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pii> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int t;
            cin >> t;
            if(t){
                mat[i][j] = t;
                if (t==1) q.push({i,j});
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (mat[nx][ny] == 0) {
                    mat[nx][ny] = mat[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    int max=0;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            if (!mat[i][j]) return !(cout << -1);
            if (max<mat[i][j]) max=mat[i][j];
        }
    }
    return !(cout << max-1);
}
