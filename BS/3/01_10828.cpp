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

int s[10000];
int size = 0, N;

void push(int n) {
    s[size] = n;
    size++;
}

void pop() {
    if (!size) {
        cout << -1 << '\n';
        return;
    }
    size--;
    cout << s[size] << '\n';
    s[size] = 0;
}

void empty() {
    cout << (size == 0) << '\n';
}

void top() {
    if (!size) {
        cout << -1 << '\n';
        return ;
    }
    cout << s[size-1] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while (N--) {
        string cmd;
        cin >> cmd;
        if (cmd == "push") {
            int n;
            cin >> n;
            push(n);
        }
        else if (cmd == "pop") {
            pop();
        }
        else if (cmd == "size") {
            cout << size << '\n';
        }
        else if (cmd == "empty") {
            empty();
        }
        else {
            top();
        }
    }
    return 0;
}
