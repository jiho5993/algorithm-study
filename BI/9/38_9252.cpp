#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
string dp[1001][1001],s1,s2;
int main(){
	int cmp=0;
	string ans;
	cin>>s1>>s2;
	for(int i=1;i<=s1.size();i++){
		for(int j=1;j<=s2.size();j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j]=dp[i-1][j-1]+s2[j-1];
			}
			else{
				if(dp[i-1][j].size()>dp[i][j-1].size())dp[i][j]=dp[i-1][j];
				else dp[i][j]=dp[i][j-1];
			}
		}
	}
	for(int i=1;i<=s1.size();i++){
		for(int j=1;j<=s2.size();j++){
			if(dp[i][j].size()>cmp){
				cmp=dp[i][j].size();
				ans=dp[i][j];
			}
		}
	}
	cout<<cmp<<'\n'<<ans;
}
