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
	int n,k,cnt[200001]={};
	scanf("%d %d",&n,&k);
	queue<int> q;
	q.push(n);
	visited[n]=true;
	while(!q.empty()){
		int curr=q.front();
		q.pop();
		if(curr==k)return !printf("%d",cnt[curr]);
		if(0<curr&&curr*2<=100000&&!visited[2*curr]){
			cnt[curr*2]=cnt[curr];
			visited[curr*2]=true;
			q.push(curr*2);
		}
		if(1<=curr&&curr-1<=100000&&!visited[curr-1]){
			cnt[curr-1]=cnt[curr]+1;
			visited[curr-1]=true;
			q.push(curr-1);
		}
		if(curr+1<=100000&&!visited[curr+1]){
			cnt[curr+1]=cnt[curr]+1;
			visited[curr+1]=true;
			q.push(curr+1);
		}
	}
}
