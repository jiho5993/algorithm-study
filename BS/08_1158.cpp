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

int N, K;
queue<int> q;
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }
    while (!q.empty()) {
        for (int i = 0; i < K-1; i++) {
            int tmp = q.front();
            q.push(tmp);
            q.pop();
        }
        v.pb(q.front());
        q.pop();
    }

    cout << '<';
    for (int i = 0; i < v.size() - 1; i++) {
        cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << '>';
    return 0;
}
