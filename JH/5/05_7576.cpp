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

bool chk = false;
int m, n, cnt=1, z_cnt=0;
int tomato[1001][1001];
int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
queue<pair<int, int> > qp;

bool ripen() {
    fr(i, 0, n) {
        fr(j, 0, m) {
            if(!tomato[i][j])
                return false;
        }
    }
    return true;
}

void bfs() {
    if(!chk) return;
    while(!qp.empty()) {
        int ss = sz(qp);
        fr(i, 0, ss) {
            int x = qp.front().second;
            int y = qp.front().first;
            qp.pop();
            fr(j, 0, 4) {
                int xx = x + go[j][1];
                int yy = y + go[j][0];
                if((0 <= xx && xx <m) && (0 <= yy && yy <n) && tomato[yy][xx] == 0) {
                    tomato[yy][xx] = 1;
                    z_cnt--;
                    qp.push(mp(yy, xx));
                }
                if(!z_cnt) return;
            }
        }
        cnt++;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> m >> n;
    fr(i, 0, n) {
        fr(j, 0, m) {
            cin >> tomato[i][j];
            if(tomato[i][j] == 0) {
                chk = 1;
                z_cnt++;
            }
            else if(tomato[i][j] == 1) qp.push(mp(i, j));
        }
    }
    bfs();
    if(chk) ripen() ? pt(cnt) : pt("-1");
    else pt("0");

    return 0;
}