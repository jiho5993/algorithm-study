#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
ll mult(ll a, ll b,ll c){
	if(b==0)return 1;
	if(b%2==0){
		int div_mult=mult(a,b/2,c);
		return (div_mult%c*div_mult%c)%c;
	}
	else return (a%c*mult(a,b-1,c)%c)%c;
}
int main(){
	ll a,b,c;
	scanf("%lld %lld %lld",&a,&b,&c);
	printf("%lld",mult(a,b,c));
}
