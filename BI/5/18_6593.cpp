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
	int dir[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	while(1){
		int l,r,c,cnt[33][33][33]={},escaped=0;
		char building[33][33][33];
		queue<pair<pii,int> >q;
		cin>>l>>r>>c;
		if(l==0&&r==0&&c==0)break;
		for(int i=0;i<l;i++){
			for(int j=0;j<r;j++){
				for(int k=0;k<c;k++){
					cin>>building[i][j][k];
					if(building[i][j][k]=='S'){
						cnt[i][j][k]=1;
						q.push(mp(mp(i,j),k));
					}
				}
			}
		}
		while(!q.empty()){
			int z=q.front().first.first,y=q.front().first.second,x=q.front().second;
			q.pop();
			if(building[z][y][x]=='E'){
				cout<<"Escaped in "<<cnt[z][y][x]-1<<" minute(s).\n",
				escaped=1;
				break;
			}
			for(int i=0;i<6;i++){
				int zz=z+dir[i][0],yy=y+dir[i][1],xx=x+dir[i][2];
				if(zz<0||yy<0||xx<0||zz>=l||yy>=r||xx>=c||cnt[zz][yy][xx])continue;
				if(building[zz][yy][xx]!='#'){
					cnt[zz][yy][xx]=cnt[z][y][x]+1;
					q.push(mp(mp(zz,yy),xx));
				}
				
			}
		}
		if(!escaped)cout<<"Trapped!"<<'\n';
	}
}
