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
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int n,dp[11]={1,1,2};
		scanf("%d",&n);
		for(int j=3;j<=n;j++){
			dp[j]=dp[j-1]+dp[j-2]+dp[j-3];
		}
		printf("%d\n",dp[n]);
	}
}

