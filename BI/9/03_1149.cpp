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
	int n,dp[1001][3]={},r[1001],g[1001],b[1001];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&r[i],&g[i],&b[i]);
	}
	for(int i=1;i<=n;i++){
		dp[i][0]=min(dp[i-1][1],dp[i-1][2])+r[i];
		dp[i][1]=min(dp[i-1][0],dp[i-1][2])+g[i];
		dp[i][2]=min(dp[i-1][0],dp[i-1][1])+b[i];
	}
	printf("%d",min(min(dp[n][0],dp[n][1]),dp[n][2]));
}
