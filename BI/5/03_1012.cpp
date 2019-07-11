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
	int t,dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>t;
	for(int i=0;i<t;i++){
		bool visited[51][51]={};
		int m,n,k,farm[51][51]={},insect=0;
		cin>>m>>n>>k;
		for(int j=0;j<k;j++){
			int x,y;
			cin>>x>>y;
			farm[y][x]=1;
		}
		for(int j=0;j<n;j++){
			for(int l=0;l<m;l++){
				if(!visited[j][l]&&farm[j][l]){
					visited[j][l]=true;
					queue<pii> q;
					q.push(mp(j,l));
					while(!q.empty()){
						int y=q.front().first,x=q.front().second;
						q.pop();
						for(int u=0;u<4;u++){
							int yy=y+dir[u][0],xx=x+dir[u][1];
							if(yy<0||yy>n||xx<0||xx>m||visited[yy][xx]||!farm[yy][xx])continue;
							visited[yy][xx]=true;
							q.push(mp(yy,xx));
						}
					}
					insect++;
				}
			}
		}
		cout<<insect<<'\n';
	}
}c
