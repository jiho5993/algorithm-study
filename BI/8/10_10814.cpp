#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
pair<int,pair<int,string> >p[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int age;
		string s;
		cin>>age>>s;
		p[i]=mp(age,mp(i,s));
	}
	sort(p,p+n);
	for(int i=0;i<n;i++){
		cout<<p[i].first<<" "<<p[i].second.second<<'\n';
	}
}
