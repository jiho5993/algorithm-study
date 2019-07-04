#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 987654321;
const ll mod = 1000000007;
const double PI = acos(-1);
int main(){
	int a,b,c,num[10]={},curr;
	scanf("%d %d %d",&a,&b,&c);
	curr=a*b*c;
	while(curr>0){
		num[curr%10]++;
		curr/=10;
	}
	for(int i=0;i<=9;i++)printf("%d\n",num[i]);
}
