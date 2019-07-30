#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int n,p[1001],dp[1001];
int main(){	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[i]=max(dp[i],dp[i-j]+p[j]);
		}
	}
	printf("%d",dp[n]);
}
