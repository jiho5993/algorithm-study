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
	int t;
	ll p[101]={0,1,1,1,2};
	for(int i=5;i<=100;i++)p[i]=p[i-1]+p[i-5];
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int n;
		scanf("%d",&n);
		printf("%lld\n",p[n]);
	}
}
