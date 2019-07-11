#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
bool visited[200001];
int n,k,cnt[200001],save[400001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	queue<int> q;
	q.push(n);
	visited[n]=true;
	while(!q.empty()){
		int curr=q.front();
		q.pop();
		if(curr==k){
			cout<<cnt[curr]<<'\n';
			int tmp=k,arr[200001]={tmp,},j=1;
			while(tmp!=n){
				if(tmp+1<=200000&&save[tmp]==tmp+1)tmp++;	
				else if(1<=tmp&&tmp-1<=200000&&save[tmp]==tmp-1)tmp--;
				else if(0<tmp&&tmp*2<=200000&&tmp%2==0&&save[tmp]==tmp/2)tmp/=2;
				arr[j++]=tmp;
			}
			for(int i=j-1;i>=0;i--)cout<<arr[i]<<" ";
			break;
		}
		if(0<curr&&curr*2<=200000&&!visited[2*curr]){
			cnt[curr*2]=cnt[curr]+1;
			save[curr*2]=curr;
			visited[curr*2]=true;
			q.push(curr*2);
		}
		if(1<=curr&&curr-1<=200000&&!visited[curr-1]){
			cnt[curr-1]=cnt[curr]+1;
			save[curr-1]=curr;
			visited[curr-1]=true;
			q.push(curr-1);
		}
		if(curr+1<=200000&&!visited[curr+1]){
			cnt[curr+1]=cnt[curr]+1;
			save[curr+1]=curr;
			visited[curr+1]=true;
			q.push(curr+1);
		}
	}
}
