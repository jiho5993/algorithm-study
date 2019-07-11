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
int vis[100001], logs[100001];

void BFS() {
    queue<int> q;
    q.push(N);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == K) {
            cout << vis[x] <<'\n';
            stack<int> s;
            while (x != N) {
                s.push(x);
                x = logs[x];
            }
            s.push(N);
            while (!s.empty()) {
                cout << s.top() << ' ';
                s.pop();
            }
            return;
        }
        int dx[3] = {x-1, x+1, 2*x};
        for (int i = 0; i < 3; i++) {
            int nx = dx[i];
            if (0<=nx && nx<=100000) {
                if (!vis[nx]) {
                    vis[nx] = vis[x]+1;
                    logs[nx] = x;
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
    BFS();
    return 0;
}
