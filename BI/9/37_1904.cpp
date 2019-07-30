#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const int mod = 15746;
const double PI = acos(-1);
int n,dp[1000001]={0,1,2};
int main(){
	scanf("%d",&n);
	for(int i=3;i<=n;i++)dp[i]=(dp[i-1]%mod+dp[i-2]%mod)%mod;
	printf("%d",dp[n]);
}
