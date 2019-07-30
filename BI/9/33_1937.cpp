#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int n,tree[501][501],dp[501][501],dir[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
int go(int y,int x){
	if(dp[y][x]>0)return dp[y][x];
	for(int i=0;i<4;i++){
		int ny=y+dir[i][0],nx=x+dir[i][1];
		if(ny<0||nx<0||ny>=n||nx>=n||tree[y][x]<=tree[ny][nx])continue;
		dp[y][x]=max(dp[y][x],go(ny,nx)+1);
	}
	return dp[y][x];
}
int main(){
	int ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&tree[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ans=max(ans,go(i,j)+1);
		}
	}
	printf("%d",ans);
}
