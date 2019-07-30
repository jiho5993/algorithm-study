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
	deque<char> mat[6];
	int ans=0,dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
	for(int i=0;i<12;i++){
		for(int j=0;j<6;j++){
			char block;
			scanf(" %c",&block);
			mat[j].pb(block);
		}
	}
	while(1){
		bool visited[6][12]={},boom=false;
		bool down[6][12]={};
		for(int i=0;i<6;i++){
			for(int j=0;j<12;j++){
				if(mat[i][j]!='.'){
					int boom_count=0;
					queue<pii> q;
					vector<pii> save; 
					q.push(mp(i,j));
					visited[i][j]=true;
					while(!q.empty()){
						int y=q.front().first,x=q.front().second;
						q.pop();
						save.pb(mp(y,x));
						boom_count++;
						for(int k=0;k<4;k++){
							int yy=y+dir[k][0],xx=x+dir[k][1];
							if(yy>5||xx>11||yy<0||xx<0||visited[yy][xx])continue;
							if(mat[yy][xx]==mat[y][x]){
								visited[yy][xx]=true;
								q.push(mp(yy,xx));
							}
						}
					}
					if(boom_count>=4){
						for(int k=0;k<save.size();k++){
							int y=save[k].first,x=save[k].second;
							down[y][x]=true;
						}
						boom=true;
					}
					save.clear();
				}
			}
		}
		if(!boom)break;
		for(int i=0;i<6;i++){
			for(int j=0;j<12;j++){
				if(down[i][j]){
					mat[i].erase(mat[i].begin()+j);
					mat[i].push_front('.');
				}
			}
		}
		ans++;
	}
	printf("%d",ans);
}
