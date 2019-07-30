#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 987654321;
const ll mod = 1000000007;
const double PI = acos(-1);
int m,n,mat[501][501],dp[501][501],dir[4][2]={{0,1},{-1,0},{1,0},{0,-1}};
bool visited[501][501];
int go(int y,int x){
	if(y==m-1&&x==n-1)return 1;
	if(dp[y][x]!=INF)return dp[y][x];
	dp[y][x]=0;
	for(int i=0;i<4;i++){
		int ny=y+dir[i][0],nx=x+dir[i][1];
		if(ny<0||nx<0||ny>=m||nx>=n||visited[ny][nx])continue;
		if(mat[ny][nx]<mat[y][x]){
			visited[ny][nx]=true;
			dp[y][x]+=go(ny,nx);
			visited[ny][nx]=false;
		}
	}
	return dp[y][x];
}
int main(){
	scanf("%d %d",&m,&n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&mat[i][j]);
			dp[i][j]=INF;
		}
	}
	visited[0][0]=true;
	printf("%d",go(0,0));
}
