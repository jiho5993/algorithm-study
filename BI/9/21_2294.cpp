#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 987654321;
const ll mod = 1000000007;
const double PI = acos(-1);
int main(){
	int n,k,coin[101],dp[10001];
	scanf("%d %d",&n,&k);
	dp[0]=0;
	fill(dp+1,dp+k+1,INF);
	for(int i=0;i<n;i++)scanf("%d",&coin[i]);
	for(int i=0;i<n;i++){
		if(coin[i]>k)continue;
		if(dp[coin[i]]==INF)dp[coin[i]]=1;
		for(int j=coin[i];j<=k;j++){
			dp[j]=min(dp[j],dp[j-coin[i]]+1);
		}
	}
	printf("%d",dp[k]==INF?-1:dp[k]);
}
