#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 987654321;
const ll mod = 1000000007;
const double PI = acos(-1);
char lake[1505][1505];
bool visited[1505][1505],melted[1505][1505];
int melt_day[1505][1505],dir[4][2]={{0,1},{-1,0},{0,-1},{1,0}},day;
queue<pii> ice_q,swan_q;
int main(){	
	int r,c,sy=-1,sx=-1,ey,ex;
	scanf("%d %d",&r,&c);
	for(int i=0;i<r;i++){
		scanf(" %s",&lake[i]);
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(lake[i][j]=='X'){
				for(int k=0;k<4;k++){
					int melt_i=i+dir[k][0],melt_j=j+dir[k][1];
					if(melt_i<0||melt_j<0||melt_i>=r||melt_j>=c)continue;
					if(lake[melt_i][melt_j]!='X')melt_day[i][j]=1;
				}
				if(melt_day[i][j]==1){
					ice_q.push(mp(i,j));
					melted[i][j]=true;
				}
			}
			else if(lake[i][j]=='L'){
				if(sy==-1&&sx==-1)sy=i,sx=j;
				else ey=i,ex=j; 
			}
		}
	}
	swan_q.push(mp(sy,sx));
	while(1){
		queue<pii> save_swan,save_ice;
		while(!swan_q.empty()){
			int swan_y=swan_q.front().first,swan_x=swan_q.front().second;
			swan_q.pop();
			if(swan_y==ey&&swan_x==ex)return !printf("%d",day);
			for(int i=0;i<4;i++){
				int yy=swan_y+dir[i][0],xx=swan_x+dir[i][1];
				if(yy<0||xx<0||yy>=r||xx>=c||visited[yy][xx])continue;
				if(lake[yy][xx]!='X'){
					visited[yy][xx]=true;
					swan_q.push(mp(yy,xx));
				}
				else{
					visited[yy][xx]=true;
					save_swan.push(mp(yy,xx));
				}
			}
		}
		while(!save_swan.empty()){
			int ny=save_swan.front().first,nx=save_swan.front().second;
			swan_q.push(mp(ny,nx));
			save_swan.pop();
		}
		while(!ice_q.empty()){
			int ice_y=ice_q.front().first,ice_x=ice_q.front().second;
			lake[ice_y][ice_x]='.';
			ice_q.pop();
			for(int i=0;i<4;i++){
				int yy=ice_y+dir[i][0],xx=ice_x+dir[i][1];
				if(yy<0||xx<0||yy>=r||xx>=c||melted[yy][xx])continue;
				if(lake[yy][xx]=='X'){
					melted[yy][xx]=true;
					save_ice.push(mp(yy,xx));
				}
			}
		}
		while(!save_ice.empty()){
			int ny=save_ice.front().first,nx=save_ice.front().second;
			ice_q.push(mp(ny,nx));
			save_ice.pop();
		}
		day++;
	}
}
