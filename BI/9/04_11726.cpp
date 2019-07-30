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
	int n,dp[1001]={0,1,2};
	scanf("%d",&n);
	for(int i=3;i<=n;i++){
		dp[i]=(dp[i-1]%mod+dp[i-2]%mod)%mod;
	}
	printf("%d",dp[n]);
}
