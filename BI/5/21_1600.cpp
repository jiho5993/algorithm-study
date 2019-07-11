#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 987654321;
const ll mod = 1000000007;
const double PI = acos(-1);
int horse[8][2]={{-2,-1},{-2,1},{1,2},{-1,2},{2,1},{2,-1},{1,-2},{-1,-2}};
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int k,w,h,mat[201][201],cnt[201][201][31],min_value=INF;
bool visited[201][201][31];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	queue<pair<pii,int> >q;
	cin>>k>>w>>h;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>mat[i][j];
		}
	}
	visited[0][0][0]=true;
	q.push(mp(mp(0,0),0));
	while(!q.empty()){
		int y=q.front().first.first,x=q.front().first.second,move_count=q.front().second;
		q.pop();
		if(y==h-1&&x==w-1){
			for(int i=0;i<=k;i++){
				if(cnt[h-1][w-1][i])min_value=min(min_value,cnt[h-1][w-1][i]);	
			}
			break;
		}
		for(int i=0;i<4;i++){
			int yy=y+dir[i][0],xx=x+dir[i][1];
			if(xx<0||yy<0||xx>=w||yy>=h||visited[yy][xx][move_count]||mat[yy][xx])continue;
			visited[yy][xx][move_count]=true;
			cnt[yy][xx][move_count]=cnt[y][x][move_count]+1;
			q.push(mp(mp(yy,xx),move_count));
		}
		if(move_count<k){
			for(int i=0;i<8;i++){
				int hy=y+horse[i][0],hx=x+horse[i][1];
				if(hx<0||hy<0||hx>=w||hy>=h||visited[hy][hx][move_count+1]||mat[hy][hx])continue;
				visited[hy][hx][move_count+1]=true;
				cnt[hy][hx][move_count+1]=cnt[y][x][move_count]+1;
				q.push(mp(mp(hy,hx),move_count+1));
			}
		}
	}
	if(min_value==INF)cout<<"-1";
	else cout<<min_value;
}
