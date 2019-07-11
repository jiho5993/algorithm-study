#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
bool visited[101][101],light_on[101][101];
int n,m,mat[101][101],dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}},cnt;
int main(){
	queue<pii>q,add;
	vector<pii> btn[101][101];
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int x,y,a,b;
		scanf("%d %d %d %d",&x,&y,&a,&b);
		btn[x][y].pb(mp(a,b));
	}
	mat[1][1]=1;
	light_on[1][1]=true;
	q.push(mp(1,1));
	visited[1][1]=true;
	while(!q.empty()){
		int y=q.front().first,x=q.front().second;
		q.pop();
		for(int i=0;i<btn[y][x].size();i++){
			int ty=btn[y][x][i].first,tx=btn[y][x][i].second;
			if(visited[ty][tx]&&light_on[ty][tx]==false)add.push(mp(ty,tx));
			light_on[ty][tx]=true;
		}
		for(int i=0;i<4;i++){
			int yy=y+dir[i][0],xx=x+dir[i][1];
			if(yy<1||yy>n||xx<1||xx>n)continue;
			if(!visited[yy][xx]){
				visited[yy][xx]=true;
				if(light_on[yy][xx])q.push(mp(yy,xx));
			}
		}
		while(!add.empty()){
			int ay=add.front().first,ax=add.front().second;
			q.push(mp(ay,ax));
			add.pop();
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(light_on[i][j])cnt++;
		}
	}
	printf("%d",cnt);
}
