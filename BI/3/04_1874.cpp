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
	stack<int> s;
	char order[200005];
	int n,curr=1,k=0,fail=0;
	cin>>n;	
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		while(s.empty()||s.top()<x){
			s.push(curr++);
			order[k++]='+';
		}
		if(!s.empty()&&s.top()==x){
			order[k++]='-';
			s.pop();
		}
		else fail=1;
	}
	if(!fail){
		for(int i=0;i<k;i++){
			cout<<order[i]<<'\n';
		}
	}
	else cout<<"NO";
}
