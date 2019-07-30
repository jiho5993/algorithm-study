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
	int n,arr[100001],dp[100001];
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&arr[i]);
	for(int i=0;i<n;i++){
		dp[i]=arr[i];
		if(i>0&&dp[i]<dp[i-1]+arr[i])dp[i]=dp[i-1]+arr[i];
	}
	sort(dp,dp+n);
	printf("%d",dp[n-1]);
}
