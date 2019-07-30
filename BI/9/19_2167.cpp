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
	int n,m,k,arr[301][301],dp[301][301]={};
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&arr[i][j]);
			dp[i][j]+=dp[i][j-1]+arr[i][j];
		}
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int sx,sy,ex,ey,ans=0;
		scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
		for(int i=sx;i<=ex;i++){
			ans+=dp[i][ey]-dp[i][sy-1];
		}
		printf("%d\n",ans);
	}
}
