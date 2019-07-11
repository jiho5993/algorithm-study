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

int F, S, G, U, D;
int mat[1000001];
queue<int> q;

void BFS(int y) {
    q.push(y);
    while (!q.empty()) {
        y = q.front();
        q.pop();
        if (mat[G]) {
            cout << mat[G];
            return;
        }
        int dy[2] = {U, -1*D};
        for (int i = 0; i < 2; i++) {
            int ny = y + dy[i];
            if (1 <= ny && ny <= F) {
                if (!mat[ny] && ny != S) {
                    mat[ny] = mat[y] + 1;
                    q.push(ny);
                }
            }
        }
    }
    cout << "use the stairs";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> F >> S >> G >> U >> D;
    if (S == G) return !(cout << 0);
    BFS(S);
    return 0;
}
