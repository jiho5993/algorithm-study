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

int d[10000];
int head, tail, N;

void push_front(int n) {
    head--;
    head = (10000 + head) % 10000;
    d[head] = n;
}

void push_back(int n) {
    d[tail] = n;
    tail++;
    tail = (10000 + tail) % 10000;
}

void pop_front() {
    if (head == tail) {
        cout << -1 << '\n';
        return;
    }
    cout << d[head] << '\n';
    d[head] = 0;
    head++;
    head = (10000 + head) % 10000;
}

void pop_back() {
    if (head == tail) {
        cout << -1 << '\n';
        return;
    }
    cout << d[(10000 + tail-1) % 10000] << '\n';
    d[(10000 + tail-1) % 10000] = 0;
    tail--;
    tail = (10000 + tail) % 10000;
}

void empty() {
    cout << (head == tail) << '\n';
}

void front() {
    if (head == tail) {
        cout << -1 << '\n';
        return;
    }
    cout << d[head] << '\n';
}

void back() {
    if (head == tail) {
        cout << -1 << '\n';
        return;
    }
    cout << d[(10000 + tail-1) % 10000] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while (N--) {
        string cmd;
        cin >> cmd;
        if (cmd == "push_front") {
            int n;
            cin >> n;
            push_front(n);
        }
        else if (cmd == "push_back") {
            int n;
            cin >> n;
            push_back(n);
        }
        else if (cmd == "pop_front") {
            pop_front();
        }
        else if (cmd == "pop_back") {
            pop_back();
        }
        else if (cmd == "size") {
            cout << (10000 + tail - head) % 10000 << '\n';
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
