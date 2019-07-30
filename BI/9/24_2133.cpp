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
	int n,dp[31]={1,0,3,0};
	scanf("%d",&n);
	if(n%2!=0)return !printf("0");
	for(int i=4;i<=n;i++){
		dp[i]=3*dp[i-2];
		for(int j=4;j<=i;j+=2)dp[i]+=2*dp[i-j];			
	}
	printf("%d",dp[n]);
}
