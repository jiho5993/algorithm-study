#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const int mod = 10007;
const double PI = acos(-1);
int main(){
	int n,dp[1001][11]={{},{1,1,1,1,1,1,1,1,1,1}},ans=0; 
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		for(int j=0;j<10;j++){
			for(int k=j;k<10;k++){
				dp[i][j]+=dp[i-1][k]%mod;
				dp[i][j]%=mod;
			}
		}
	}
	for(int i=0;i<10;i++)ans=(ans%mod+dp[n][i]%mod)%mod;
	printf("%d",ans);
}

