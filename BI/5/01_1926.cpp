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
	bool visited[501][501]={};
	int n,m,mat[501][501],max_area=0,picture=0,dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mat[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!visited[i][j]&&mat[i][j]){
				queue<pii> q;
				int cnt=0;
				q.push(mp(i,j));
				visited[i][j]=true;
				while(!q.empty()){
					int y=q.front().first,x=q.front().second;
					q.pop();
					cnt++;
					for(int k=0;k<4;k++){
						int yy=y+dir[k][0],xx=x+dir[k][1];
						if(visited[yy][xx]||!mat[yy][xx])continue;
						if(0<=yy&&yy<n&&0<=xx&&xx<m&&mat[i][j]){
							visited[yy][xx]=true;
							q.push(mp(yy,xx));
						}
					}
				}
				max_area=max(max_area,cnt);
				picture++;
			}
			
		}
	}
	cout<<picture<<'\n'<<max_area;
}
