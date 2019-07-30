#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int n,m,arr[10],check[10001],k;
void re(vector<int> &nums){
	if(nums.size()==m){
		for(int i=0;i<nums.size();i++)printf("%d ",arr[nums[i]]);
		printf("\n");
		return;
	}
	for(int i=0;i<k;i++){
		nums.pb(i);
		re(nums);
		nums.pop_back();
	}
}
int main(){	
	int no[10];
	vector<int> init;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&no[i]);
	}
	for(int i=0;i<n;i++){
		if(!check[no[i]]){
			check[no[i]]=1;
			arr[k++]=no[i];
		}
	}
	sort(arr,arr+k);
	re(init);
}
