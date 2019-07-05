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

int N;
vector<pii> v;
vector<int> ans;
stack<pii> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        v.pb(mp(t, i+1));
    }

    for (int i = 0; i < N; i++) {
        while (!s.empty() && s.top().first < v[i].first) {
            s.pop();
        }
        if (s.empty()) {
            ans.pb(0);
        }
        else {
            ans.pb(s.top().second);
        }
        s.push(v[i]);
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}
