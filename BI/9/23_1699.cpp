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
	int n,dp[100001];
	scanf("%d",&n);
	fill(dp,dp+n+1,INF);
	dp[0]=0;
	for(int i=1;i*i<=n;i++){
		for(int j=i*i;j<=n;j++){
			dp[j]=min(dp[j],dp[j-i*i]+1);
		}
	}
	printf("%d",dp[n]);
}
