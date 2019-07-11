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
	int n,mat[101][101],max_height=0,max_region=0,dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};	
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>mat[i][j];
			max_height=max(mat[i][j],max_height);
		}
	}
	for(int i=0;i<max_height;i++){
		int sink_height=i,cnt=0;
		bool visited[101][101]={};
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(!visited[j][k]&&mat[j][k]>sink_height){
					queue<pii>q;
					visited[j][k]=true;
					q.push(mp(j,k));
					while(!q.empty()){
						int y=q.front().first,x=q.front().second;
						q.pop();
						for(int l=0;l<4;l++){
							int yy=y+dir[l][0],xx=x+dir[l][1];
							if(yy<0||xx<0||yy>=n||xx>=n||visited[yy][xx])continue;
							if(mat[yy][xx]>sink_height){
								visited[yy][xx]=true;
								q.push(mp(yy,xx));
							}
						}
					}
					cnt++;
				}
			}
		}
		max_region=max(max_region,cnt);
	}
	cout<<max_region;
}
