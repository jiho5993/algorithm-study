#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int video[65][65];
void press(int y,int x,int l){
	int check=video[y][x],divide=0;
	for(int i=y;i<y+l;i++){
		for(int j=x;j<x+l;j++){
			if(video[i][j]!=check)divide=1;
		}
	}
	if(divide){
		printf("(");
		press(y,x,l/2);
		press(y,x+l/2,l/2);
		press(y+l/2,x,l/2);
		press(y+l/2,x+l/2,l/2);
		printf(")");
	}
	else printf("%d",check);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%1d",&video[i][j]);
		}
	}
	press(0,0,n);
}
