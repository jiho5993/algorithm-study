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
	int n,m,mat[301][301],melt[301][301]={},dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}},year=0;	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mat[i][j];
		}
	}
	while(1){
		bool not_divided=true;
		int div_count=0;
		bool visited[301][301]={};
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(!visited[i][j]&&mat[i][j]>0){
					not_divided=false;
					queue<pii>q;
					queue<pair<pii,int> >melt_queue;
					visited[i][j]=true;
					q.push(mp(i,j));
					while(!q.empty()){
						int y=q.front().first,x=q.front().second,sea=0;
						q.pop();
						for(int k=0;k<4;k++){
							int yy=y+dir[k][0],xx=x+dir[k][1];
							if(yy<0||xx<0||yy>=n||xx>=m||visited[yy][xx])continue;
							if(mat[yy][xx]<=0)sea++;
							else{
								visited[yy][xx]=true;
								q.push(mp(yy,xx));
							}
						}
						melt_queue.push(mp(mp(y,x),sea));
					}
					while(!melt_queue.empty()){
						int my=melt_queue.front().first.first,mx=melt_queue.front().first.second;
						int melt_count=melt_queue.front().second;
						melt_queue.pop();
						mat[my][mx]-=melt_count;
					}
					div_count++;
				}
			}
		}
		if(div_count>1){
			cout<<year;
			break;
		}
		if(not_divided){
			cout<<"0";
			break;
		}
		year++;
	}
}
