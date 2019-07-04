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

int alphabet[27];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        alphabet[s[i]-'a']++;
    }
    for (int i = 0; i < 26; i++) {
        cout << alphabet[i] << ' ';
    }

    return 0;
}
