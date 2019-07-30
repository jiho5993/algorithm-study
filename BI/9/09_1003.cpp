#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int dp[41][2]={{1,0},{0,1}};
int fib(int n,int m){
	if(n<=1)return n==m;
	if(dp[n][m]>0)return dp[n][m];
	dp[n][m]=fib(n-1,m)+fib(n-2,m);
	return dp[n][m];
}
int main(){
	int t;
	scanf("%d",&t);
	for(int i=2;i<=40;i++){
		fib(i,0);
		fib(i,1);
	}
	for(int i=0;i<t;i++){
		int N;
		scanf("%d",&N);
		printf("%d %d\n",dp[N][0],dp[N][1]);
	}
}
