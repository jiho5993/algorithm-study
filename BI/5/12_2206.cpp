#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int n,m,mat[1002][1002],visited[1002][1002][2],dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}},cnt[1002][1002][2]={};
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d",&mat[i][j]);
		}
	}
	queue<pair<pii,int> >q;
	q.push(mp(mp(0,0),0));
	visited[0][0][0]=true;
	while(!q.empty()){
		int y=q.front().first.first,x=q.front().first.second,broken=q.front().second;
		q.pop();
		if(y==n-1&&x==m-1){
			if(!cnt[y][x][0])return !printf("%d",cnt[y][x][1]+1);
			if(!cnt[y][x][1])return !printf("%d",cnt[y][x][0]+1);
			return !printf("%d",min(cnt[y][x][0],cnt[y][x][1])+1);
		}
		for(int i=0;i<4;i++){
			int yy=y+dir[i][0],xx=x+dir[i][1];
			if(0<=yy&&yy<n&&0<=xx&&xx<m&&!visited[yy][xx][broken]){
				if(!mat[yy][xx]){
					visited[yy][xx][broken]=true;
					cnt[yy][xx][broken]=cnt[y][x][broken]+1;
					q.push(mp(mp(yy,xx),broken));
				}
				else if(!broken){
					visited[yy][xx][broken]=true;
					cnt[yy][xx][1]=cnt[y][x][0]+1;
					q.push(mp(mp(yy,xx),1));
				}
				
			}
		}
	}
	printf("-1");
}
