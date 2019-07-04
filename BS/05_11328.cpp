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

int N;

void check() {
    
    cout << "Possible\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s1, s2;
        vector<char> o, c;
        cin >> s1 >> s2;
        for (int i = 0; i < s1.length(); i++) {
            o.pb(s1[i]);
        }
        for (int i = 0; i < s2.length(); i++) {
            c.pb(s2[i]);
        }
        sort(o.begin(), o.end());
        sort(c.begin(), c.end());
        
        if (o.size() == c.size()) {
            for (int i = 0; i < o.size(); i++) {
                if (o[i] != c[i]) {
                    cout << "Impossible\n";
                    break;
                }
                if (i == o.size() - 1) {
                    cout << "Possible\n";
                }
            }
        }
        else {
            cout << "Impossible\n";
        }
        
    }
    return 0;
}
