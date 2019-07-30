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
	int n,arr[1000001];
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&arr[i]);
	sort(arr,arr+n);
	for(int i=0;i<n;i++)printf("%d\n",arr[i]);
}
