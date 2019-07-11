#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int n,m,farm[1001][1001],dir[4][2]={{0,1},{-1,0},{1,0},{0,-1}},ans=0,f=0;
int main(){
	ios_base::sync_with_stdio(false);
	queue<pii> q;
	cin>>m>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>farm[i][j];
			if(farm[i][j]==1)q.push(mp(i,j));
		}
	}
	while(!q.empty()){
		int y=q.front().first,x=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int yy=y+dir[i][0],xx=x+dir[i][1];
			if(!farm[yy][xx]&&0<=yy&&yy<n&&0<=xx&&xx<m){
				farm[yy][xx]=farm[y][x]+1;
				q.push(mp(yy,xx));
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!farm[i][j])f=1;
			else ans=max(ans,farm[i][j]);
		}
	}
	if(f)cout<<"-1";
	else cout<<ans-1;
}
