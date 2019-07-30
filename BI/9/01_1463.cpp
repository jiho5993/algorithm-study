#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int dp[1000001];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1]+1;
		if(i%3==0&&dp[i]>dp[i/3]+1)dp[i]=dp[i/3]+1;
		if(i%2==0&&dp[i]>dp[i/2]+1)dp[i]=dp[i/2]+1;
	}	
	printf("%d",dp[n]);
}
