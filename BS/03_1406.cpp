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

stack<char> r;
stack<char> l;
string s;
int n;

void L() {
    if (l.empty()) return;
    r.push(l.top());
    l.pop();
}

void D() {
    if (r.empty()) return;
    l.push(r.top());
    r.pop();
}

void B() {
    if (l.empty()) return;
    l.pop();
}

void P(char c) {
    l.push(c);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> n;

    for (int i = 0; i < s.length(); i++) {
        l.push(s[i]);
    }

    for (int i = 0; i < n; i++) {
        char cmd;
        cin >> cmd;
        if (cmd == 'P') {
            char c;
            cin >> c;
            P(c);
        } else if (cmd == 'L') {
            L();
        } else if (cmd == 'D') {
            D();
        } else {
            B();
        }
    }

    while (!l.empty()) {
        L();
    }

    while (!r.empty()) {
        cout << r.top();
        r.pop();
    }

    return 0;
}
