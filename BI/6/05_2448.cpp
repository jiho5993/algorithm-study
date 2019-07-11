#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
char star[3073][6200];
void recursion(int y,int x,int n){
	if(n>3){
		recursion(y,x,n/2);
		recursion(y+n/2,x-n/2,n/2);
		recursion(y+n/2,x+n/2,n/2);
	}
	else{
		int cnt=0;
		for(int i=y;i<y+3;i++){
			for(int j=x+y-i;j<x+i+1-y;j++){
				if(cnt!=2)star[i][j]='*';
				cnt++;
			}
		}
	}
}
int main(){
	int n,cnt=0,tmp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<2*n-1;j++)star[i][j]=' ';
	}
	recursion(0,n-1,n);
	for(int i=0;i<n;i++){
		for(int j=0;j<2*n-1;j++){
			printf("%c",star[i][j]);
		}
		printf("\n");
	}
}
