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

int T;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        string cmd, arr;
        int l;
        cin >> cmd >> l >> arr;
        deque<int> dq;
        string num;
        for (int i = 1; i < arr.length(); i++) {
            if (arr[i] >= '0' && arr[i] <= '9') {
                num += arr[i];
            }
            else {
                if (!num.empty()) {
                    dq.pb(stoi(num));
                    num.clear();
                }
            }
        }
        bool ctn = false;
        bool rvs = false;

        for (int i = 0; i < cmd.length(); i++) {
            if (cmd[i] == 'R') rvs = !rvs;
            else {
                if (dq.empty()) {
                    ctn = true;
                    cout << "error\n";
                    break;
                }
                else {
                    if (rvs) dq.pop_back();
                    else dq.pop_front();
                }
            }
        }
        if (ctn) continue;
        if (rvs) {
            cout << '[';
            while (!dq.empty()) {
                cout << dq.back();
                dq.pop_back();
                if (!dq.empty()) {
                    cout << ',';
                }
            }
            cout << "]\n";
        }
        else {
            cout << '[';
            while (!dq.empty()) {
                cout << dq.front();
                dq.pop_front();
                if (!dq.empty()) {
                    cout << ',';
                }
            }
            cout << "]\n";
        }
    }
    
    return 0;
}
