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
	int n,m,dp[48]={1,1,2},start=1,ans=1;
	scanf("%d %d",&n,&m);
	for(int i=3;i<=n;i++)dp[i]=dp[i-1]+dp[i-2];
	for(int i=0;i<m;i++){
		int x;
		scanf("%d",&x);
		ans*=dp[x-start];
		start=x+1;
	}
	printf("%d",ans*dp[n+1-start]);	
}
