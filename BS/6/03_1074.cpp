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

int N, r, c;
int res;

void Z(int x, int y, int n) {
    if (x == r && y == c) {
        cout << res;
        return;
    }
    if (n == 1) {
        res++;
        return;
    }
    if (x > r || r-n >= x || y > c || c-n >= y) {
        res += n*n;
        return;
    }
    int half = n/2;
    Z(x,y,half);
    Z(x,y+half,half);
    Z(x+half,y,half);
    Z(x+half,y+half,half);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> r >> c;
    Z(0,0,1<<N);
    return 0;
}
