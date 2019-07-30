#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int lotto[14],n;
bool check[54];
void es(vector<int> &num){
	if(num.size()==6){
		for(int i=0;i<6;i++){
			printf("%d ",lotto[num[i]]);
		}
		printf("\n");
		return;
	}
	int go=num.empty()?0:num[num.size()-1]+1;
	for(int i=go;i<n;i++){
		if(!check[lotto[i]]){
			check[lotto[i]]=true;
			num.pb(i);
			es(num);
			num.pop_back();
			check[lotto[i]]=false;
		}
	}
}
int main(){
	while(1){
		scanf("%d",&n);
		if(!n)break;
		vector<int> init;
		memset(lotto,0,sizeof(lotto));
		memset(check,false,sizeof(check));
		for(int i=0;i<n;i++){
			scanf("%d",&lotto[i]);
		}
		es(init);
		printf("\n");
	} 
}
