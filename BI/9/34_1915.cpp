#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 987654321;
const ll mod = 1000000007;
const double PI = acos(-1);
int n,m,arr[1001][1001],dp[1001][1001],dir[3][2]={{0,-1},{-1,-1},{-1,0}},ans=0;
int main(){
	scanf("%d %d",&n,&m);	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d",&arr[i][j]);
			if(arr[i][j]){
				dp[i][j]=1;
				ans=1;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]){
				bool pass=true;
				int tmp=INF;
				for(int k=0;k<3;k++){
					int ni=i+dir[k][0],nj=j+dir[k][1];
					if(ni<0||nj<0||ni>=n||nj>=m||!arr[ni][nj])pass=false;
					tmp=min(tmp,dp[ni][nj]);
				}
				if(pass){
					dp[i][j]=tmp+1;
					ans=max(ans,dp[i][j]);
				}
			}
		}
	}
	printf("%d",ans*ans);
}
