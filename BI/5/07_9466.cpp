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
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,adj[100004],ans=0;
		int cycle[100004]={},cnt[100004]={};
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>adj[j];
			if(adj[j]==j)cycle[j]=j;
		}
		for(int j=1;j<=n;j++){
			if(!cycle[j]){
				stack<int> s;
				s.push(j);
				cnt[j]=1;
				cycle[j]=j;
				while(!s.empty()){
					int curr=s.top();s.pop();
					if(j==adj[curr])break;
					if(cycle[adj[curr]]==j){
						ans+=cnt[adj[curr]]-1;
						break;
					}
					if(cycle[adj[curr]]>0){
						ans+=cnt[curr];
						break;
					}
					cycle[adj[curr]]=j;
					cnt[adj[curr]]=cnt[curr]+1;
					s.push(adj[curr]);
				}
			}
		}
		cout<<ans<<'\n';
	}
}
/*
3
3
1 2 3
3
2 1 2
3
2 3 2
     ---
    |   |
1-->2-->3
1   2   3

=> 0 1 1(O)
*/
