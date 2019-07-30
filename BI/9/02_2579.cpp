#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 987654321;
const ll mod = 1000000007;
const double PI = acos(-1);
int dp[301][2],score[301];
int go(int idx,int one){
	if(idx<0)return -INF;
	if(idx==0)return 0;
	if(idx==1)return score[1];
	if(dp[idx][one]>0)return dp[idx][one];
	if(one)dp[idx][one]=go(idx-2,0)+score[idx];
	else dp[idx][one]=max(go(idx-1,1),go(idx-2,0))+score[idx];
	return dp[idx][one];
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&score[i]);
	printf("%d",max(go(n,0),go(n,1)));
}
