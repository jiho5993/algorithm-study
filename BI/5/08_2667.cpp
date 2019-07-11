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
	bool visited[30][30]={};
	int n,mat[30][30],house[901],k=0,dir[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%1d",&mat[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!visited[i][j]&&mat[i][j]){
				int area=1;
				visited[i][j]=true;
				queue<pii>q;
				q.push(mp(i,j));
				while(!q.empty()){
					int y=q.front().first,x=q.front().second;
					q.pop();
					for(int l=0;l<4;l++){
						int yy=y+dir[l][0],xx=x+dir[l][1];
						if(0<=yy&&yy<n&&0<=xx&&xx<n&&!visited[yy][xx]&&mat[yy][xx]){
							visited[yy][xx]=true;
							q.push(mp(yy,xx));
							area++;
						}
					}
				}
				house[k++]=area;
			}
		}
	}
	sort(house,house+k);
	printf("%d\n",k);
	for(int i=0;i<k;i++)printf("%d\n",house[i]);
}
