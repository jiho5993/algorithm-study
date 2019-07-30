#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 987654321;
const ll mod = 1000000007;
const double PI = acos(-1);
int n,dp[10001]={1,},coin[101],k;
int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",&coin[i]);
	for(int i=0;i<n;i++){
		for(int j=coin[i];j<=k;j++)dp[j]+=dp[j-coin[i]];
	}
	printf("%d",dp[k]);
}
