#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 987654321;
const ll mod = 1000000007;
const double PI = acos(-1);
int n,m,k,mid_y,mid_x,dp[16][16];
int go_finish(int y,int x){
	if(y==n-1&&x==m-1)return 1;
	if(y>=n||x>=m)return 0;
	if(dp[y][x]>0)return dp[y][x];
	dp[y][x]=go_finish(y+1,x)+go_finish(y,x+1);
	return dp[y][x];
}
int go_mid(int y,int x){
	if(y==mid_y&&x==mid_x)return 1;
	if(y>mid_y||x>mid_x)return 0;
	if(dp[y][x]>0)return dp[y][x];
	dp[y][x]=go_mid(y+1,x)+go_mid(y,x+1);
	return dp[y][x];
}
int main(){	
	scanf("%d %d %d",&n,&m,&k);
	if(k>0)mid_y=(k-1)/m,mid_x=(k-1)%m;
	printf("%d",go_mid(0,0)*go_finish(mid_y,mid_x));
}
