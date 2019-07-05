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
	stack<pii> s;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int h;
		cin>>h;
		while(!s.empty()&&s.top().first<h)s.pop();
		if(s.empty()||s.top().first<h)printf("0 ");
		else printf("%d ",s.top().second);
		s.push(mp(h,i));
	}
}
