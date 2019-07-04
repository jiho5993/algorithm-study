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

string s1, s2;
vector<char> v1, v2;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++) {
        v1.pb(s1[i]);
    }
    for (int i = 0; i < s2.length(); i++) {
        v2.pb(s2[i]);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int i = 0, j = 0;
    while(i < v1.size() && j < v2.size()) {
        if (v1[i] == v2[j]) {
            i++; 
            j++;
        }
        else if (v1[i] > v2[j]) {
            n++;
            j++;
        }
        else if (v1[i] < v2[j]) {
            n++;
            i++;
        }
    }
    n += v1.size() - i + v2.size() - j;
    cout << n;
    return 0;
}
