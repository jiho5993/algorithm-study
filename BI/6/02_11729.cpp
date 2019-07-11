#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
void hanoi(int n,int start,int end){
	if(n>1){
		int who=6-start-end;
		hanoi(n-1,start,who);
		printf("%d %d\n",start,end);
		hanoi(n-1,who,end);
	}
	else printf("%d %d\n",start,end);
} 
int main(){
	int k;
	scanf("%d",&k);
	printf("%d\n",(1<<k)-1);
	hanoi(k,1,3);
}
