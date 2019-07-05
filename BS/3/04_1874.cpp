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

int N, now, top=-1;
vector<int> v;
vector<char> ans;
stack<int> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        v.pb(t);
    }

    for (int i = 0; i < v.size(); i++) {
        if (top > v[i]) {
            return !(cout << "NO");
        }
        else if (top < v[i]) {
            while(v[i] > now) {
                now++;
                s.push(now);
                ans.pb('+');
            }
            s.pop();
            ans.pb('-');
            top = s.size() ? s.top() : -1;
        }
        else {
            s.pop();
            ans.pb('-');
            top = s.size() ? s.top() : -1;
        }
    }
    
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
