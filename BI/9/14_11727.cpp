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
	int n,dp[1001]={0,1,3};
	scanf("%d",&n);
	for(int i=3;i<=n;i++){
		dp[i]=(dp[i-1]%10007+2*dp[i-2]%10007)%10007;
	}
	printf("%d",dp[n]);
}
