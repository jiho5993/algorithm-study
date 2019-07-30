#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int n,dp[1001],a[1001],ans; 
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(a[j]>a[i])dp[i]=max(dp[i],dp[j]+1);
		}	
		
	}
	for(int i=0;i<n;i++)ans=max(ans,dp[i]);
	printf("%d",ans);
}
