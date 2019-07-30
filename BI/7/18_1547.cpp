#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int cup[4]={0,1,0,0};
void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int main(){
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		if(cup[x]||cup[y])swap(cup+x,cup+y);
	}
	for(int i=1;i<=3;i++){
		if(cup[i])printf("%d",i);
	}
}
