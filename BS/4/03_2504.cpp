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

stack<char> s;
stack<int> c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string e;
    int ans = 0;
    cin >> e;
    for (int i = 0; i < e.length(); i++) {
        if (e[i] == '(') {
            s.push('(');
            c.push(1);
        }
        else if (e[i] == ')') {
            if (s.empty()) {
                return !(cout << 0);
            }
            else {
                if (s.top() == '(') {
                    s.pop();
                    int t = 0;
                    while (c.top() != 1) {
                        t += c.top();
                        c.pop();
                    }
                    t = 2 * (t ? t : c.top());
                    c.pop();
                    c.push(t);
                }
                else {
                    return !(cout << 0);
                }
            }
        }
        else if (e[i] == '[') {
            s.push('[');
            c.push(1);
        }
        else if (e[i] == ']') {
            if (s.empty()) {
                return !(cout << 0);
            }
            else {
                if (s.top() == '[') {
                    s.pop();
                    int t = 0;
                    while (c.top() != 1) {
                        t += c.top();
                        c.pop();
                    }
                    t = 3 * (t ? t : c.top());
                    c.pop();
                    c.push(t);
                }
                else {
                    return !(cout << 0);
                }
            }
        }
    }
    if (!s.empty()) {
        return !(cout << 0);
    }
    while (!c.empty()) {
        ans += c.top();
        c.pop();
    }
    cout << ans;
    return 0;
}
