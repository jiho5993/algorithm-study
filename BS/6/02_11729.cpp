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

void hanoi(int n, int source, int target, int bridge) {
    if (n == 1) cout << source << ' ' << target << '\n';
    else {
        hanoi(n-1, source, bridge, target);
    cout << source << ' ' << target << '\n';
        hanoi(n-1, bridge, target, source);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int cnt = 1 << N;
    cnt--;
    cout << cnt << '\n';
    hanoi(N,1,3,2);
    return 0;
}
