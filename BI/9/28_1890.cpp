#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int n,mat[101][101];
ll dp[101][101];
ll go(int sy,int sx){
	if(sy>=n||sx>=n)return 0;
	if(sy==n-1&&sx==n-1)return 1;
	if(dp[sy][sx]!=-1)return dp[sy][sx];
	dp[sy][sx]=(!mat[sy][sx])?0:go(sy+mat[sy][sx],sx)+go(sy,sx+mat[sy][sx]);
	return dp[sy][sx];
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	for(int i=0;i<n;i++)fill(dp[i],dp[i]+n,-1);
	printf("%lld",go(0,0));
}
