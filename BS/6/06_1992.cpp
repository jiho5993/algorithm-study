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

int N;
int mat[64][64];

void recursion(int x, int y, int N) {
    int compress = true;
    int check = mat[x][y];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mat[x+i][y+j] != check) {
                compress = false;
            }
        }
        if (!compress) break;
    }
    if (!compress) {
        cout << '(';
        int next = N / 2;
        recursion(x,y,next);
        recursion(x,y+next,next);
        recursion(x+next,y,next);
        recursion(x+next,y+next,next);
        cout << ')';
    }
    else cout << check;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            mat[i][j] = s[j]-'0';
        }
    }
    recursion(0,0,N);
    return 0;
}
