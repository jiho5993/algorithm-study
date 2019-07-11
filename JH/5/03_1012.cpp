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

int t, m, n, k, px, py;
int baechu[51][51], visit[51][51];
int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void init() {
    fr(i, 0, m) {
        fill(baechu[i], baechu[i]+51, 0);
        fill(visit[i], visit[i]+51, 0);
    }
}

void bfs(int x, int y) {
    queue<pair<int, int> > qp;
    qp.push(mp(x, y));
    visit[x][y] = 1;
    while(!qp.empty()) {
        int nx = qp.front().first;
        int ny = qp.front().second;
        qp.pop();
        fr(i, 0, 4) {
            int xx = nx + go[i][0];
            int yy = ny + go[i][1];
            if((0 <= xx && xx < m) && (0 <= yy && yy < n) && !visit[xx][yy] && baechu[xx][yy]) {
                visit[xx][yy] = 1;
                qp.push(mp(xx, yy));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> t;
    while(t--) {
        init();
        int cnt=0;
        cin >> m >> n >> k;
        while(k--) {
            cin >> px >> py;
            baechu[px][py] = 1;
        }
        fr(i, 0, m) {
            fr(j, 0, n) {
                if(baechu[i][j] && !visit[i][j]) {
                    cnt++;
                    bfs(i, j);
                }
            }
        }
        pt(cnt);
    }

    return 0;
}