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
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int size=0,j;
		string vps;
		cin>>vps;
		for(j=0;j<vps.size();j++){
			if(vps[j]=='(')size++;
			else{
				if(size==0)break;
				size--;
			}
		}
		if(!size&&j==vps.size())cout<<"YES\n";
		else cout<<"NO\n";
	}
}
