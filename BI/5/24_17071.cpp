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
	bool visited[200001]={};
	int n,k,cnt[200001]={},go=0,chk=0;
	scanf("%d %d",&n,&k);
	queue<pair<pii,int> >q;
	q.push(mp(mp(n,0),chk));
	visited[n]=true;
	while(!q.empty()){
		int curr=q.front().first.first,accel=q.front().first.second;
		int limit=q.front().second;
		q.pop();
		cout<<curr<<"\n";
		if(limit>500000)return !printf("-1");
		if(curr==k)return !printf("%d",cnt[curr]);		
		if(1<=curr-accel&&curr-1-accel<=500000&&!visited[curr-1-accel]){
			cnt[curr-1-accel]=cnt[curr]+1;
			visited[curr-1-accel]=true;
			q.push(mp(mp(curr-1-accel,accel+1),limit+accel));
		}
		if(accel<=curr+1&&curr+1-accel<=500000&&!visited[curr+1-accel]){
			cnt[curr+1-accel]=cnt[curr]+1;
			visited[curr+1-accel]=true;
			q.push(mp(mp(curr+1-accel,accel+1),limit+accel));
		}
		if(accel<=curr*2&&curr*2-accel<=500000&&!visited[2*curr-accel]){
			cnt[curr*2-accel]=cnt[curr]+1;
			visited[curr*2-accel]=true;
			q.push(mp(mp(curr*2-accel,accel+1),limit+accel));
		}
	}
}
