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

int boys[7];
int girls[7];
int N, K;
int minRoom;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int gender, grade;
        cin >> gender >> grade;
        if (gender) boys[grade]++;
        else girls[grade]++;
    }

    for (int i = 1; i < 7; i++) {
        minRoom += boys[i] / K;
        if (boys[i] % K) minRoom++;
        minRoom += girls[i] / K;
        if (girls[i] % K) minRoom++;
    }
    cout << minRoom;
    return 0;
}
