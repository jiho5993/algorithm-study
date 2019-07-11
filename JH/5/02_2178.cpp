#include <bits/stdc++.h>
#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(a) ((int)(a.size()))
#define len(a) ((int)(a.length()))
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '
using namespace std;

int n, m;
int arr[101][101];
int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfs() {
    queue<pair<int, int> > qp;
    qp.push(mp(0, 0));
    while(!qp.empty()) {
        int nx = qp.front().second;
        int ny = qp.front().first;
        qp.pop();
        fr(i, 0, 4) {
            int xx = nx + go[i][0];
            int yy = ny + go[i][1];
            if((0 <= xx && xx < m) && (0 <= yy && yy < n) && arr[yy][xx] == 1) {
                qp.push(mp(yy, xx));
                arr[yy][xx] = arr[ny][nx] + 1; 
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n >> m; // 4 6
    fr(i, 0, n) {
        string s; cin >> s;
        fr(j, 0, m)
            arr[i][j] = s[j]-'0';
    }
    bfs();
    pt(arr[n-1][m-1]);

    return 0;
}