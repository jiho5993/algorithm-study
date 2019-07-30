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
	int n;
	pair<int,int> p[100001];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&p[i].first,&p[i].second);
	}
	sort(p,p+n);
	for(int i=0;i<n;i++){
		printf("%d %d\n",p[i].first,p[i].second);
	}
}
