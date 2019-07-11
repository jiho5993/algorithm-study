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
	bool visited[105][105]={},rgcvisit[105][105]={};
	int n,mat[105][105],dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}},rgc=0,normal=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf(" %c",&mat[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!visited[i][j]){
				queue<pii> q;
				q.push(mp(i,j));
				visited[i][j]=true;
				while(!q.empty()){
					int y=q.front().first,x=q.front().second;
					q.pop();
					for(int k=0;k<4;k++){
						int yy=y+dir[k][0],xx=x+dir[k][1];
						if(0<=yy&&yy<n&&0<=xx&&xx<n&&!visited[yy][xx]&&mat[yy][xx]==mat[i][j]){
							visited[yy][xx]=true;
							q.push(mp(yy,xx));
						}
					}
				}
				normal++;
			}
			if(!rgcvisit[i][j]){
				queue<pii> q;
				q.push(mp(i,j));
				rgcvisit[i][j]=true;
				while(!q.empty()){
					int y=q.front().first,x=q.front().second;
					q.pop();
					for(int k=0;k<4;k++){
						int yy=y+dir[k][0],xx=x+dir[k][1];
						if(0<=yy&&yy<n&&0<=xx&&xx<n&&!rgcvisit[yy][xx]){
							if(mat[yy][xx]==mat[i][j]||((mat[i][j]=='R'||mat[i][j]=='G')&&mat[yy][xx]!='B')){
								rgcvisit[yy][xx]=true;
								q.push(mp(yy,xx));
							}
						}
					}
				}
				rgc++;
			}
		}
	}
	printf("%d\n%d",normal,rgc);
}
