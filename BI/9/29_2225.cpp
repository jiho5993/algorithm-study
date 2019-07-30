#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const int mod = 1000000000;
const double PI = acos(-1);
int main(){
	int n,k,dp[201][201]={};
	scanf("%d %d",&n,&k);
	fill(dp[1],dp[1]+n+1,1);
	for(int j=2;j<=k;j++){
		for(int i=0;i<=n;i++){
			for(int l=i;l>=0;l--){
				dp[j][i]+=dp[j-1][i-l]%mod;
				dp[j][i]%=mod;
			}
		}
	}
	printf("%d",dp[k][n]);
}
