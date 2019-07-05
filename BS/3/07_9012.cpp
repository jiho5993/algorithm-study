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
int ep;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        ep = 0;
        string e;
        cin >> e;
        for (int i = 0; i < e.length(); i++) {
            if (e[i] == '(') {
                ep++;
            }
            else if (e[i] == ')'){
                ep--;
            }

            if (ep < 0) {
                cout << "NO\n";
                break;
            }
        }
        if (ep == 0) {
            cout << "YES\n";
        }
        else if (ep > 0) {
            cout << "NO\n";
        }
    }
    return 0;
}
