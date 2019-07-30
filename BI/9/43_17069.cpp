#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int n,house[33][33];
ll dp[33][33][3];
ll go(int y,int x,int type){//0: 가로 1: 세로 2: 대각선 
	if(y>=n||x>=n||house[y][x])return 0;
	if(type==2&&(house[y-1][x]||house[y][x-1]))return 0;
	if(y==n-1&&x==n-1)return 1;
	if(dp[y][x][type]!=-1)return dp[y][x][type];
	if(type==0)dp[y][x][type]=go(y,x+1,0)+go(y+1,x+1,2);
	else if(type==1)dp[y][x][type]=go(y+1,x,1)+go(y+1,x+1,2);
	else dp[y][x][type]=go(y,x+1,0)+go(y+1,x,1)+go(y+1,x+1,2);
	return dp[y][x][type];
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&house[i][j]);
			fill(dp[i][j],dp[i][j]+3,-1);
		}
	}
	printf("%lld",go(0,1,0));
}
