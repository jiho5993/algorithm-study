#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
deque<int> hor_dice(3,0),ver_dice(4,0);
int n,m,y,x,k,mat[21][21],dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
void roll_right(){
	hor_dice.push_front(ver_dice.back());
	ver_dice.pop_back();
	ver_dice.pb(hor_dice.back());
	hor_dice.pop_back();
	ver_dice[1]=hor_dice[1];
}
void roll_left(){
	hor_dice.pb(ver_dice.back());
	ver_dice.pop_back();
	ver_dice.pb(hor_dice.front());
	hor_dice.pop_front();
	ver_dice[1]=hor_dice[1];
}
void roll_up(){
	ver_dice.pb(ver_dice.front());
	ver_dice.pop_front();
	hor_dice[1]=ver_dice[1];
}
void roll_down(){
	ver_dice.push_front(ver_dice.back());
	ver_dice.pop_back();
	hor_dice[1]=ver_dice[1];
}

int main(){	
	scanf("%d %d %d %d %d",&n,&m,&y,&x,&k);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	for(int i=0;i<k;i++){
		int move,yy,xx;
		scanf("%d",&move);
		yy=y+dir[move-1][0],xx=x+dir[move-1][1];
		if(yy<0||xx<0||yy>=n||xx>=m)continue;
		if(move==1)roll_right();
		else if(move==2)roll_left();
		else if(move==3)roll_up();
		else roll_down();
		if(!mat[yy][xx])mat[yy][xx]=ver_dice[3];
		else {
			ver_dice[3]=mat[yy][xx];
			mat[yy][xx]=0;
		}
		y=yy,x=xx;
		printf("%d\n",hor_dice[1]);
	}
}
