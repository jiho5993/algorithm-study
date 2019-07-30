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
	int n,t[16]={},p[16]={},dp[16]={};
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&t[i],&p[i]);
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<i;j++){
			if(j+t[j]<=i&&dp[j]+p[j]>dp[i])dp[i]=dp[j]+p[j];
		}
	}
	sort(dp,dp+n+1);
	printf("%d",dp[n]);
}
