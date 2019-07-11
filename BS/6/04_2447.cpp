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

int star[2187][2187];

int N;
void recursion(int x, int y, int n){
    if (n == 1) {
        star[x][y] = 1;
        return;
    }
    int next = n/3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i==1&&j==1) continue;
            recursion(x+i*next,y+j*next,next);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    recursion(0,0,N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (star[i][j]) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
