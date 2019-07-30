#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int ans,n;
bool ver[17],acr_left[34],acr_right[34];
void N_Queen(int y){
	if(y==n){
		ans++;
		return;
	}
	for(int j=0;j<n;j++){
		if(ver[j]||acr_left[y-j+n]||acr_right[y+j])continue;
		ver[j]=acr_left[y-j+n]=acr_right[y+j]=true;
		N_Queen(y+1);
		ver[j]=acr_left[y-j+n]=acr_right[y+j]=false;
	}
}

int main(){
	scanf("%d",&n);
	N_Queen(0);
	printf("%d",ans);
}
