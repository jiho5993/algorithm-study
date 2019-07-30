#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int n,m,arr[10];
bool checked[10001];
void re(vector<int> &nums){
	if(nums.size()==m){
		for(int i=0;i<nums.size();i++)printf("%d ",arr[nums[i]]);
		printf("\n");
		return;
	}
	int go=nums.empty()?0:nums.size();
	for(int i=0;i<n;i++){
		if(!checked[arr[i]]){
			nums.pb(i);
			checked[arr[i]]=true;
			re(nums);
			checked[arr[i]]=false;
			nums.pop_back();
		}
		
	}
}
int main(){	
	vector<int> init;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",&arr[i]);
	sort(arr,arr+n);
	re(init);
}
