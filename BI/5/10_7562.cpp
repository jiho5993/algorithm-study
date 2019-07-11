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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int t,dir[8][2]={{2,1},{2,-1},{1,2},{1,-2},{-1,2},{-1,-2},{-2,1},{-2,-1}};
	cin>>t;
	for(int i=0;i<t;i++){
		bool visited[301][301]={};
		int l,mat[301][301],sy,sx,ey,ex,cnt[301][301]={};
		cin>>l>>sy>>sx>>ey>>ex;
		queue<pii>q;
		q.push(mp(sy,sx));
		visited[sy][sx]=true;
		while(!q.empty()){
			int y=q.front().first,x=q.front().second;
			q.pop();
			if(y==ey&&x==ex){
				cout<<cnt[y][x]<<'\n';
				break;
			}
			for(int i=0;i<8;i++){
				int yy=y+dir[i][0],xx=x+dir[i][1];
				if(0<=yy&&yy<l&&0<=xx&&xx<l&&!visited[yy][xx]){
					visited[yy][xx]=true;
					q.push(mp(yy,xx));
					cnt[yy][xx]=cnt[y][x]+1;
				}
			}
		}
	}
}
