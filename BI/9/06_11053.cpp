#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int a[1001],n,dp[1001];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(a[j]<a[i]&&dp[i]<dp[j]+1)dp[i]=dp[j]+1;
		}
	}
	sort(dp,dp+n);
	printf("%d",dp[n-1]);
}
