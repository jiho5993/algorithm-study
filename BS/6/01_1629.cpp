#include <bits/stdc++.h>
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;

const int INF = 2147483647;
const int MOD = 1000000007;
const double PI = acos(-1);

ll A, B, C;

ll dqs(ll x, ll y)
{
    ll r = 1;
    while (y > 0){
        if (y % 2){
            r *= x;
            r %= C;
        }
        x *= x;
        x %= C;
        y /= 2;
    }
    
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> A >> B >> C;
    cout << dqs(A,B);
    return 0;
}
