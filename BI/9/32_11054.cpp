#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int n,lis[1001],lds[1001],a[1001],ans=1;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		lis[i]=1;
		for(int j=0;j<i;j++){
			if(a[j]<a[i])lis[i]=max(lis[i],lis[j]+1);
		}
	}
	for(int i=n-1;i>=0;i--){
		lds[i]=1;
		for(int j=n-1;j>i;j--){
			if(a[i]>a[j])lds[i]=max(lds[i],lds[j]+1);
		}
	}
	for(int i=0;i<n;i++)ans=max(ans,lis[i]+lds[i]-1);
	printf("%d",ans);
}
