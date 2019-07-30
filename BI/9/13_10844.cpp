#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000000;
const double PI = acos(-1);
int main(){
	ll n,stair[101][11]={},ans=0;
	scanf("%lld",&n);
	for(int i=1;i<10;i++)stair[1][i]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<10;j++){
			if(j>0)stair[i][j]=(stair[i-1][j-1]%mod+stair[i-1][j+1]%mod)%mod;
			else stair[i][j]=stair[i-1][j+1]%mod;
		}
	}
	for(int j=0;j<10;j++)ans=(ans%mod+stair[n][j]%mod)%mod;
	printf("%lld",ans);
}
