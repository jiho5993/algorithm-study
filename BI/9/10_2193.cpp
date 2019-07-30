#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 987654321;
const ll mod = 1000000007;
const double PI = acos(-1);
ll dp[91][2];
ll go(int n,int m){
	if(n==1){
		if(!m)return 0;
		else return 1;
	}
	if(dp[n][m]>0)return dp[n][m];
	if(!m)dp[n][m]=go(n-1,0)+go(n-1,1);
	else dp[n][m]=go(n-1,0);
	return dp[n][m];
}
int main(){
	int N;
	scanf("%d",&N);
	printf("%lld",go(N,0)+go(N,1));
}
