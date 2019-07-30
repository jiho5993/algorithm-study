#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int dp[1001][1001];
int main(){
	string s1,s2;
	cin>>s1>>s2;
	int l1=s1.size(),l2=s2.size();
	for(int i=1;i<=l1;i++){
		for(int j=1;j<=l2;j++){
			if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]); 
		}
	}
	printf("%d",dp[l1][l2]);
}
