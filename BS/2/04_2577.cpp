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

int A, B, C;
int nums[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> A >> B >> C;
    int res = A*B*C;
    while (res) {
        nums[res%10]++;
        res /= 10;
    }

    for (int i = 0; i < 10; i++) {
        cout << nums[i] << '\n';
    }
    return 0;
}
