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

int N, K, t;
int mat[100001];

queue<pii> q;

void BFS(int n) {
    q.push({n,1});
    mat[n] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int now = q.front().second;
        q.pop();
        int dx[3] = {2*x, x-1, x+1};
        for (int i = 0; i < 3; i++) {
            int nx = dx[i];
            if (nx == n) continue;
            if (0 <= nx && nx <= 100000) {
                if ((i && now + 1 < mat[nx]) || !mat[nx]) {
                    mat[nx] = now + 1;
                    q.push({nx, now+1});
                }
                if ((!i && now < mat[nx]) || !mat[nx]){
                    mat[nx] = now;
                    q.push({nx, now});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    BFS(N);
    cout << mat[K]-1;
    return 0;
}
