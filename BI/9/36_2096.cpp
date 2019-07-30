#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 987654321;
const ll mod = 1000000007;
const double PI = acos(-1);
int n,max_dp[2][5],min_dp[2][5];
int main(){
	scanf("%d",&n);
	min_dp[0][0]=min_dp[0][4]=INF;
	for(int i=0;i<n;i++){
		int a[4];
		scanf("%d %d %d",&a[1],&a[2],&a[3]);
		for(int k=1;k<=3;k++){
			max_dp[1][k]=max(max_dp[0][k-1],max(max_dp[0][k],max_dp[0][k+1]))+a[k];
			min_dp[1][k]=min(min_dp[0][k-1],min(min_dp[0][k],min_dp[0][k+1]))+a[k];
		}
		for(int k=1;k<=3;k++){
			max_dp[0][k]=max_dp[1][k];
			min_dp[0][k]=min_dp[1][k];
		}
	}
	printf("%d %d",max(max_dp[0][1],max(max_dp[0][2],max_dp[0][3])),min(min_dp[0][1],min(min_dp[0][2],min_dp[0][3])));
}
