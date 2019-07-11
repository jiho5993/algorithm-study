#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int main(){
	bool visited[101][101]={};
	int n,m,maze[101][101],dir[4][2]={{0,1},{-1,0},{1,0},{0,-1}},cnt[101][101]={};
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d",&maze[i][j]);
		}
	}
	queue<pii> q;
	q.push(mp(0,0));
	visited[0][0]=true;
	while(!q.empty()){
		int y=q.front().first,x=q.front().second;
		q.pop();
		if(y==n-1&&x==m-1)return!printf("%d",cnt[y][x]+1);
		for(int i=0;i<4;i++){
			int yy=y+dir[i][0],xx=x+dir[i][1];
			if(yy<0||yy>n||xx<0||xx>m)continue;
			if(visited[yy][xx]||!maze[yy][xx])continue;
			cnt[yy][xx]=cnt[y][x]+1;
			visited[yy][xx]=true;
			q.push(mp(yy,xx));
		}
	}
}
