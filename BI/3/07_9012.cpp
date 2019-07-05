#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int t,j;
	cin>>t;
	for(int i=0;i<t;i++){
		stack<int> s;
		string vps;
		cin>>vps;
		for(j=0;j<vps.size();j++){
			if(vps[j]=='(')s.push(1);
			else{
				if(s.empty())break;
				s.pop();
			}
		}
		if(s.empty()&&j==vps.size())cout<<"YES\n";
		else cout<<"NO\n";
	}
}
