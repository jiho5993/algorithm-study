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

char stk[9];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '9') {
            stk[6]++;
        }
        else {
            stk[s[i] - '0']++;
        }
    }
    stk[6] = (stk[6] % 2) ? stk[6]/2 + 1 : stk[6]/2;
    int max = 0;
    for (int i = 0; i < 9; i++) {
        if (stk[i] > max) max = stk[i];
    }

    cout << max;

    return 0;
}
