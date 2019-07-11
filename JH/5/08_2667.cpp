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

int t, d[26][26], visit[26][26], n[1000], cnt;
int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
queue<pair<int, int> > qp;

void bfs(int x, int y, int num) {
    qp.push(mp(x, y));
    visit[x][y] = 1;
    while(!qp.empty()) {
        int ss = sz(qp);
        fr(i, 0, ss) {
            int nx = qp.front().first;
            int ny = qp.front().second;
            qp.pop();
            fr(j, 0, 4) {
                int xx = nx + go[j][0];
                int yy = ny + go[j][1];
                if ((0 <= xx && xx < t) && (0 <= yy && yy < t) && !visit[xx][yy] && d[xx][yy]) {
                    qp.push(mp(xx, yy));
                    visit[xx][yy] = 1;
                }
            }
            n[num]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> t;
    fr(i, 0, t) {
        string s; cin >> s;
        fr(j, 0, t)
            d[i][j] = s[j]-'0';
    }
    fr(i, 0, t) {
        fr(j, 0, t) {
            if(!visit[i][j] && d[i][j]) {
                bfs(i, j, cnt);
                cnt++;
            }
        }
    }
    sort(n, n+cnt);
    pt(cnt);
    fr(i, 0, cnt) pt(n[i]);

    return 0;
}