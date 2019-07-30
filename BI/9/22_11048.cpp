#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int n,m,maze[1001][1001],dir[3][2]={{-1,0},{0,-1},{-1,-1}},dp[1001][1001];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&maze[i][j]);
		}
	} 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dp[i][j]=maze[i][j];
			for(int k=0;k<3;k++){
				int y=i+dir[k][0],x=j+dir[k][1];
				if(y<0||x<0)continue;
				dp[i][j]=max(dp[i][j],dp[y][x]+maze[i][j]);
			}
		}
	}
	printf("%d",dp[n-1][m-1]);
}
