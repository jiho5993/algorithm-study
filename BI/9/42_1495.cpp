#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 987654321;
const ll mod = 1000000007;
const double PI = acos(-1);
int n,s,m,v[101],dp[101][1001];
int go(int idx,int volume){
	if(volume<0||volume>m)return -1;
	if(idx==n)return volume;
	if(dp[idx][volume]!=-INF)return dp[idx][volume];
	dp[idx][volume]=max(go(idx+1,volume-v[idx]),go(idx+1,volume+v[idx]));
	return dp[idx][volume];
}
int main(){	
	scanf("%d %d %d",&n,&s,&m);
	for(int i=0;i<n;i++)scanf("%d",&v[i]);
	for(int i=0;i<=n;i++)fill(dp[i],dp[i]+m+1,-INF);
	printf("%d",go(0,s));
}
