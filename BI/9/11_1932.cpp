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
	int n,dp[501][501]={},arr[501][501];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	dp[0][0]=arr[0][0];
	for(int i=1;i<n;i++){
		for(int j=0;j<=i;j++){
			if(0<j)dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+arr[i][j];
			else dp[i][j]=dp[i-1][j]+arr[i][j];
		}
	}
	sort(dp[n-1],dp[n-1]+n);
	printf("%d",dp[n-1][n-1]);
}
