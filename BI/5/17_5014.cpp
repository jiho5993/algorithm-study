#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
int cnt[1000001];
int main(){
	queue<int> q;
	int f,s,g,u,d;
	scanf("%d %d %d %d %d",&f,&s,&g,&u,&d);
	q.push(s);
	cnt[s]=1;
	while(!q.empty()){
		int curr=q.front();
		q.pop();
		if(curr==g)return !printf("%d",!cnt[g]?0:cnt[g]-1);
		if(curr+u<=f&&!cnt[curr+u]){
			cnt[curr+u]=cnt[curr]+1;
			q.push(curr+u);
		}
		if(d<curr&&curr-d<=f&&!cnt[curr-d]){
			cnt[curr-d]=cnt[curr]+1;
			q.push(curr-d);
		}
	}
	printf("use the stairs");
}
