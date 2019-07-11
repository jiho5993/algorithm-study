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
	bool visited[101][101]={};
	int m,n,k,mat[101][101]={},dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}},ans=0,area[10001];
	cin>>m>>n>>k;
	for(int i=0;i<k;i++){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		for(int j=y1;j<y2;j++){
			for(int k=x1;k<x2;k++){
				mat[j][k]=1;
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(!mat[i][j]&&!visited[i][j]){
				int cnt=0;
				visited[i][j]=true;
				queue<pii> q;
				q.push(mp(i,j));
				while(!q.empty()){
					int y=q.front().first,x=q.front().second;
					q.pop();
					cnt++;
					for(int k=0;k<4;k++){
						int yy=y+dir[k][0],xx=x+dir[k][1];
						if(0<=yy&&yy<m&&0<=xx&&xx<n&&!visited[yy][xx]&&!mat[yy][xx]){
							visited[yy][xx]=true;
							q.push(mp(yy,xx));
						}
					}
				}
				area[ans++]=cnt;
			}
		}
	}
	cout<<ans<<'\n';
	sort(area,area+ans);
	for(int i=0;i<ans;i++)cout<<area[i]<<" ";
}
