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
	pair<int,string>s[20001];
	map<string,int> m;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string t;
		cin>>t;
		s[i]=mp(t.size(),t);
	}
	sort(s,s+n);
	for(int i=0;i<n;i++){
		if(!m[s[i].second]){
			cout<<s[i].second<<'\n';
			m[s[i].second]++;
		}
	}
}
