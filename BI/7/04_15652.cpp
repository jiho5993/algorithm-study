#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int n,m;
void re(vector<int> &nums){
	if(nums.size()==m){
		for(int i=0;i<nums.size();i++)printf("%d ",nums[i]);
		printf("\n");
		return;
	}
	int go=nums.empty()?1:nums[nums.size()-1];
	for(int i=go;i<=n;i++){
		nums.pb(i);
		re(nums);
		nums.pop_back();
	}
}
int main(){	
	vector<int> init;
	scanf("%d %d",&n,&m);
	re(init);
}
