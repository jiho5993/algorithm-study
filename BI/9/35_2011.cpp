#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const int mod = 1000000;
const double PI = acos(-1);
int main(){
	int dp[5001][3]={{0,1,0}};
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	string s;
	cin>>s;
	int n=s.size();
	if(s[0]=='0'){
		cout<<0;
		return 0;
	}
	for(int i=1;i<n;i++){
		int curr=s[i]-'0',bnum=s[i-1]-'0';
		if(curr!=0)dp[i][1]=(dp[i-1][1]%mod+dp[i-1][2]%mod)%mod;
		if((bnum==2&&curr<=6)||bnum==1)dp[i][2]=dp[i-1][1]%mod;
	}
	printf("%d",(dp[n-1][1]%mod+dp[n-1][2]%mod)%mod);
}
