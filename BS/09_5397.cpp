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

int T;

stack<char> l, r;

void L() {
    if (l.empty()) return;
    r.push(l.top());
    l.pop();
}
void R() {
    if (r.empty()) return;
    l.push(r.top());
    r.pop();
}
void B() {
    if (l.empty()) return;
    l.pop();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            char cmd = s[i];
            if (cmd == '<') {
                L();
            }
            else if (cmd == '>') {
                R();
            }
            else if (cmd == '-') {
                B();
            }
            else {
                l.push(cmd);
            }

        }
        while (!l.empty()) {
            L();
        }

        while (!r.empty()) {
            cout << r.top();
            r.pop();
        }
        cout << '\n';
    }

    return 0;
}
