#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int Z(int n,int r,int c){
	if(n==0)return 0;
	int size=1<<n-1;
	if(r<size&&c<size)return Z(n-1,r,c);
	else if(r>=size&&c>=size)return Z(n-1,r-size,c-size)+3*(1<<2*n-2);
	else if(r<size&&c>=size)return Z(n-1,r,c-size)+(1<<2*n-2);
	else return Z(n-1,r-size,c)+2*(1<<2*n-2);
}
int main(){
	int n,r,c;
	scanf("%d %d %d",&n,&r,&c);
	printf("%d",Z(n,r,c));
}
