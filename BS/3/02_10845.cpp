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

int q[10000];
int head, tail, N;

void push(int n) {
    q[tail] = n;
    tail++;
}

void pop() {
    if (head == tail) {
        cout << -1 << '\n';
        return;
    }
    cout << q[head] << '\n';
    q[head] = 0;
    head++;
}

void empty() {
    cout << (head == tail) << '\n';
}

void front() {
    if (head == tail) {
        cout << -1 << '\n';
        return;
    }
    cout << q[head] << '\n';
}

void back() {
    if (head == tail) {
        cout << -1 << '\n';
        return ;
    }
    cout << q[tail-1] << '\n';
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
            cout << tail - head << '\n';
        }
        else if (cmd == "empty") {
            empty();
        }
        else if (cmd == "front") {
            front();
        }
        else {
            back();
        }
    }
    return 0;
}
