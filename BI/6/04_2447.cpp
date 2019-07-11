#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
char arr[6562][6562];
void star(int r,int c,int x){
	if(x==3){
		for(int i=r;i<r+3;i++){
			for(int j=c;j<c+3;j++){
				if(i%3==2&&j%3==2)continue;
				arr[i][j]='*';
			}
		}
	}
	else{
		int div=x/3;
		star(r,c,div);
		star(r,c+div,div);
		star(r,c+2*div,div);
		star(r+div,c,div);
		star(r+div,c+2*div,div);
		star(r+2*div,c,div);
		star(r+2*div,c+div,div);
		star(r+2*div,c+2*div,div);
	}
	
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			arr[i][j]=' ';
		}
	}
	star(1,1,n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%c",arr[i][j]);		
		}
		printf("\n");
	}
}
