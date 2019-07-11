#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 987654321;
const ll mod = 1000000007;
const double PI = acos(-1);
bool visited[101][101];
queue<pii>q;
int n,mat[101][101],dir[4][2]={{0,1},{-1,0},{0,-1},{1,0}},cnt[101][101];
int bfs(int sy,int sx,int type){	
	if(type>0){
		q.push(mp(sy,sx));
		visited[sy][sx]=true;
		mat[sy][sx]=type;
	}
	while(!q.empty()){
		int y=q.front().first,x=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int yy=y+dir[i][0],xx=x+dir[i][1];
			if(yy<0||yy>=n||xx<0||xx>=n||visited[yy][xx])continue;
			if(type>0&&mat[yy][xx]==1){
				visited[yy][xx]=true;
				q.push(mp(yy,xx));
				mat[yy][xx]=type;
			}
			else if(type==-1&&!mat[yy][xx]){
				visited[yy][xx]=true;
				q.push(mp(yy,xx));
				mat[yy][xx]=mat[y][x];
				cnt[yy][xx]=cnt[y][x]+1;
			}
		}
	}
}
int main(){
	int num=1;
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>mat[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!visited[i][j]&&mat[i][j]==1){
				bfs(i,j,num++);
			}	
		}
	}
	memset(visited,false,sizeof(visited));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(mat[i][j]&&!visited[i][j]){
				for(int k=0;k<4;k++){
					int mi=i+dir[k][0],mj=j+dir[k][1];
					if(mi<0||mj<0||mi>=n||mj>=n||mat[mi][mj])continue;
					mat[mi][mj]=mat[i][j];
					cnt[mi][mj]=cnt[i][j]+1;
					visited[mi][mj]=true;
					q.push(mp(mi,mj));
				}
				visited[i][j]=true;
			}	
		}
	}
	bfs(-1,-1,-1);
	int min_value=INF;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<4;k++){
				int mi=i+dir[k][0],mj=j+dir[k][1];
				if(mi<0||mj<0||mi>=n||mj>=n)continue;
				if(mat[mi][mj]!=mat[i][j])min_value=min(min_value,cnt[mi][mj]+cnt[i][j]);
			}	
		}
	}
	cout<<min_value;
}
