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

int N;
int star[3072][3072*2-1];

void recursion(int x, int y, int n) {
    if (n == 3) {
        star[x][y] = 1;
        star[x+1][y-1] = 1; star[x+1][y+1] = 1;
        star[x+2][y-2] = 1; star[x+2][y-1] = 1; star[x+2][y] = 1; star[x+2][y+1] = 1; star[x+2][y+2] = 1;
        return;
    }
    int next = n / 2;
    recursion(x,y,next);
    recursion(x+next,y-next,next);
    recursion(x+next,y+next,next);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    recursion(0,N-1,N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2*N-1; j++) {
            if (star[i][j]) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
