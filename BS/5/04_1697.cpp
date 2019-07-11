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

int N, K;
queue<int> q;
int mat[100001];

int BFS(int x) {
    q.push(x);
    while(!q.empty()) {
        x = q.front();
        if (x == K) {
            return mat[K];
        }
        q.pop();
        int dx[3] = {x-1, x+1, 2*x};
        for (int i = 0; i < 3; i++) {
            int nx = dx[i];
            if (nx >= 0 && nx <= 100000) {
                if (mat[nx] == 0) {
                    mat[nx] = mat[x] + 1;
                    q.push(nx);
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    K;
    cout << BFS(N);
    return 0;
}
