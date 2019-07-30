#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 987654321;
const ll mod = 1000000007;
const double PI = acos(-1);
int arr[3][100001],dp[3][100001];
int main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int n,ans=-1;	
		scanf("%d",&n);
		for(int j=1;j<3;j++){
			for(int k=1;k<=n;k++){
				scanf("%d",&arr[j][k]);
			}
		}
		memset(dp,0,sizeof(dp));
		dp[1][1]=arr[1][1];
		dp[2][1]=arr[2][1];
		for(int j=2;j<=n;j++){
			for(int k=1;k<3;k++){
				dp[k][j]=max(max(dp[1][j-2]+arr[k][j],dp[2][j-2]+arr[k][j]),max(dp[3-k][j-1]+arr[k][j],dp[k][j-1]));
				ans=max(ans,dp[k][j]);
			}
		}
		printf("%d\n",max(dp[1][n],dp[2][n]));
	}
}
