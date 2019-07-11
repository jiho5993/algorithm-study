#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int w,h,dir[4][2]={{0,1},{-1,0},{0,-1},{1,0}},cnt[1001][1001];
bool visited[1001][1001];
char building[1001][1001];
int main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int escape=0,ans=0;
		memset(visited,false,sizeof(visited));
		memset(cnt,0,sizeof(cnt));
		queue<pii> q;
		scanf("%d %d",&w,&h);
		for(int j=0;j<h;j++){
			scanf(" %s",&building[j]);
			for(int k=0;k<w;k++){
				if(building[j][k]=='@')q.push(mp(j,k));
			}
		}
		for(int j=0;j<h;j++){
			for(int k=0;k<w;k++){
				if(building[j][k]=='*')q.push(mp(j,k));
			}
		}
		while(!q.empty()){
			int y=q.front().first,x=q.front().second;
			q.pop();
			if((y==0||x==0||y==h-1||x==w-1)&&(building[y][x]=='.'||building[y][x]=='@')){
				escape=1;
				ans=cnt[y][x]+1;
				break;
			}
			for(int j=0;j<4;j++){
				int yy=y+dir[j][0],xx=x+dir[j][1];
				if(yy<0||xx<0||yy>=h||xx>=w||building[yy][xx]=='#'||visited[yy][xx])continue;
				if(building[y][x]=='*'){
					visited[yy][xx]=true;
					building[yy][xx]='*';
					q.push(mp(yy,xx));
				}
				else if(building[y][x]=='@'&&building[yy][xx]=='.'){
					bool no=false;
					for(int k=0;k<4;k++){
						int fy=yy+dir[k][0],fx=xx+dir[k][1];
						if(0<=fy&&fy<h&&0<=fx&&fx<w&&building[fy][fx]=='*'){
							no=true;
						}
					}
					if(!no){
						q.push(mp(yy,xx));
						building[yy][xx]='@';
						visited[yy][xx]=true;
						cnt[yy][xx]=cnt[y][x]+1;
					}
				}
			}
		}
		if(escape)printf("%d\n",ans);
		else printf("IMPOSSIBLE\n");
	}
}

