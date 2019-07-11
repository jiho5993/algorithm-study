#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int n,m,h,farm[101][101][101],dir[6][3]={{0,1,0},{-1,0,0},{1,0,0},{0,-1,0},{0,0,1},{0,0,-1}},ans=0,f=0;
int main(){
	ios_base::sync_with_stdio(false);
	queue<pair<int,pii> >q;
	cin>>m>>n>>h;
	for(int i=0;i<h;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				cin>>farm[i][j][k];
				if(farm[i][j][k]==1)q.push(mp(i,(mp(j,k))));
			}
		}
	}
	while(!q.empty()){
		int z=q.front().first,y=q.front().second.first,x=q.front().second.second;
		q.pop();
		for(int i=0;i<6;i++){
			int zz=z+dir[i][0],yy=y+dir[i][1],xx=x+dir[i][2];
			if(0<=zz&&zz<h&&0<=yy&&yy<n&&0<=xx&&xx<m&&!farm[zz][yy][xx]){
				farm[zz][yy][xx]=farm[z][y][x]+1;
				q.push(mp(zz,mp(yy,xx)));
			}
		}
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				if(!farm[i][j][k])f=1;
				else ans=max(ans,farm[i][j][k]);
			}
		}
	}
	if(f)cout<<"-1";
	else cout<<ans-1;
}
