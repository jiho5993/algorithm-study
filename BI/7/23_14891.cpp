#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
deque<int> gear[4];
bool checked[4];
void rotate(int type,int direction){
	if(type<3&&gear[type][2]!=gear[type+1][6]&&!checked[type+1]){//¿À¸¥ÂÊ
		checked[type+1]=true;
	    rotate(type+1,-direction);
	    checked[type+1]=false;
	}
	if(type>0&&gear[type][6]!=gear[type-1][2]&&!checked[type-1]){//¿ÞÂÊ 
		checked[type-1]=true;
		rotate(type-1,-direction);
		checked[type-1]=false;
	}
	if(direction==1){
		gear[type].push_front(gear[type].back());
		gear[type].pop_back();
	}
	else{
		gear[type].push_back(gear[type].front());
		gear[type].pop_front();
	}
	
}
int main(){
	for(int i=0;i<4;i++){
		for(int j=0;j<8;j++){
			int x;
			scanf("%1d",&x);
			gear[i].pb(x);
		}
	}
	int k,ans=0;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int t,d;
		scanf("%d %d",&t,&d);
		checked[t-1]=true;
		rotate(t-1,d);
		checked[t-1]=false;
	}
	ans=gear[0][0]+2*gear[1][0]+4*gear[2][0]+8*gear[3][0];
	printf("%d",ans);
}
