#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n,arr[10001]={};
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr[x]++;
	}
	for(int i=1;i<=10000;i++){
		for(int j=0;j<arr[i];j++)cout<<i<<'\n';
	}
}
