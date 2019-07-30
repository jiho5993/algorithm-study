#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const int mod = 9901;
const double PI = acos(-1);
int n,dp[100001][3];
int go(int y,int x){
	if(y==n-1)return 1;
	if(dp[y][x]!=-1)return dp[y][x];
	dp[y][x]=0;
	if(x==2)dp[y][x]=(go(y+1,0)%mod+go(y+1,1)%mod+go(y+1,2)%mod)%mod;
	else dp[y][x]=(go(y+1,1-x)%mod+go(y+1,2)%mod)%mod;
	return dp[y][x];
}
int main(){
	int max_value=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)fill(dp[i],dp[i]+3,-1);
	for(int i=0;i<3;i++){
		max_value+=go(0,i)%mod;
		max_value%=mod;
	}
	printf("%d",max_value);
}
