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

int T;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        stack<char> s;
        string e;
        cin >> e;
        bool ctn = false;
        for (int i = 0; i < e.length(); i++) {
            if (e[i] == '(') {
                s.push(' ');
            }
            else if (e[i] == ')') {
                if (s.empty()) {
                    cout << "NO\n";
                    ctn = true;
                    break;
                }
                s.pop();
            }
        }
        if (ctn) continue;
        if (s.empty()) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}
