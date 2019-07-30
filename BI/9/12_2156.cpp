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
	int n,glass[10001],dp[10001][3]={};
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&glass[i]);
	dp[0][1]=glass[0];
	for(int i=1;i<n;i++){
		dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
		dp[i][1]=dp[i-1][0]+glass[i];
		dp[i][2]=dp[i-1][1]+glass[i];
	}
	printf("%d",max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2])));
}
