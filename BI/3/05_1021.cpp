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
	deque<int> dq;
	int n,m,curr=1,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)dq.push_back(i);
	for(int i=0;i<m;i++){
		int pick,count=0,len=dq.size();
		cin>>pick;
		while(dq.front()!=pick){
			int tmp=dq.front();
			dq.pop_front();
			dq.push_back(tmp);
			count++;
		}
		dq.pop_front();
		ans+=min(count,len-count);
	}
	cout<<ans;
}
