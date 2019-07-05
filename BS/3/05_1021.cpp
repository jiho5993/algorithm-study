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

int N, M, sum;
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int t;
        cin >> t;
        v.pb(t);
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > N - i - v[i] + 1) {
            int d = N - i - v[i];
            for (int j = i; j < v.size(); j++) {
                v[j] = (N-i + v[j] + d) % (N-i);
            }
            sum += d+1;
        }
        else {
            int d = v[i];
            for (int j = i+1; j < v.size(); j++) {
                v[j] = (N-i + v[j] - d) % (N-i);
            }
            sum += d-1;
        }
    }
    cout << sum;
    return 0;
}
