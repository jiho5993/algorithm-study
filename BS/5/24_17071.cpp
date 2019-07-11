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

int N, K;
int odd[500002];
int even[500002];
queue<pii> q;

int BFS(int x) {
    q.push({x,0});
    while (!q.empty()) {
        x = q.front().first;
        int k = q.front().second;
        int sum = K + (k*(k+1))/2;
        q.pop();
        if (sum > 500000) return -1;
        if (x == sum) return k;
        if (k%2 && odd[sum]) return k;
        else if (!(k%2) && (even[sum] || sum == N)) return k;
        int dx[3] = {x-1, x+1, x*2};
        for (int i = 0; i < 3; i++) {
            int nx = dx[i];
            if (0 <= nx && nx <= 500000) {
                if ((k+1)%2) {
                    if (!odd[nx]) {
                        odd[nx] = k+1;
                        q.push({nx,k+1});
                    }
                }
                else {
                    if (!even[nx] && nx != N) {
                        even[nx] = k+1;
                        q.push({nx,k+1});
                    }

                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    cout << BFS(N);
    return 0;
}
