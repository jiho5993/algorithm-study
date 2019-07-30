#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
char mat[5][5];
int ans,dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int optimized[5][5];
void backtrack(vector<int>&v,int other){
	if(other>=4)return;
	if(v.size()==7){
		int princess=0;
		queue<pii> q;
		q.push(mp(v[0]/5,v[0]%5));
		optimized[v[0]/5][v[0]%5]-=2;
		while(!q.empty()){
			int y=q.front().first,x=q.front().second;
			q.pop();
			princess++;
			for(int i=0;i<4;i++){
				int yy=y+dir[i][0],xx=x+dir[i][1];
				if(yy<0||xx<0||yy>4||xx>4||optimized[yy][xx]!=1)continue;
				optimized[yy][xx]-=2;
				q.push(mp(yy,xx));
			}
		}
		optimized[v[0]/5][v[0]%5]+=2;
		for(int i=1;i<7;i++){
			if(optimized[v[i]/5][v[i]%5]==-1)optimized[v[i]/5][v[i]%5]+=2;
		}
		if(princess!=7)return;
		ans++;
	}
	else{
		int go=v.empty()?0:v[v.size()-1]+1;
		for(int i=go;i<25;i++){
			v.pb(i);
			optimized[i/5][i%5]++;
			int check=mat[i/5][i%5]=='Y'?1:0;
			backtrack(v,other+check);
			v.pop_back();
			optimized[i/5][i%5]--;
		}
	}
}
int main(){
	vector<int> go;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			scanf(" %c",&mat[i][j]);
		}
	}
	backtrack(go,0);
	printf("%d",ans);
}
