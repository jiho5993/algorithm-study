#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int n,ans;
bool check_left[31];
vector<pii>cross[31];
void es(int num,int count){
	if(num>=2*n){
		ans=max(ans,count);
		return;
	}
	if(cross[num].empty())return es(num+1,count);
	else{
		bool fail=true;
		for(int i=0;i<cross[num].size();i++){
			int y=cross[num][i].first,x=cross[num][i].second;
			if(check_left[x-y+n])continue;
			check_left[x-y+n]=true;
			fail=false;
			es(num+1,count+1);
			check_left[x-y+n]=false;
		}
		if(fail)return es(num+1,count);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int chess;
			scanf("%d",&chess);
			if(chess)cross[i+j].pb(mp(i,j));
		}
	}
	es(0,0);
	printf("%d",ans);
}
/*
10
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
*/
