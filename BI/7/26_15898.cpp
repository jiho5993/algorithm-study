#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 987654321;
const ll mod = 1000000007;
const double PI = acos(-1);
int n,material[10][4][4][4],mat_score[5][5],ans=-INF;
char color[10][4][4][4],mat_color[5][5];
bool check[10];
void es_table(vector<pii> &selection,vector<int> &arrange){
	if(arrange.size()==3){
		//scoring and color setting
		map<char,int> m;
		m['R']=0,m['B']=0,m['G']=0,m['Y']=0;
		for(int i=0;i<5;i++)fill(mat_color[i],mat_color[i]+5,'W');
		for(int i=0;i<5;i++)fill(mat_score[i],mat_score[i]+5,0);
		for(int i=0;i<3;i++){
			int sy=arrange[i]/2,sx=arrange[i]%2;
			int type=selection[i].first,rotate=selection[i].second;
			for(int j=0;j<4;j++){
				for(int k=0;k<4;k++){
					if(mat_score[j+sy][k+sx]+material[type][j][k][rotate]>9)mat_score[j+sy][k+sx]=9;
					else if(mat_score[j+sy][k+sx]+material[type][j][k][rotate]<0)mat_score[j+sy][k+sx]=0;
					else mat_score[j+sy][k+sx]+=material[type][j][k][rotate];
					if(color[type][j][k][rotate]!='W')mat_color[j+sy][k+sx]=color[type][j][k][rotate];
				}
			}
		}
		//cal
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				if(mat_color[i][j]!='W'){
					m[mat_color[i][j]]+=mat_score[i][j];
				}	
			}
		}
		ans=max(ans,7*m['R']+5*m['B']+3*m['G']+2*m['Y']);
		return;
	}
	for(int i=0;i<4;i++){
		arrange.pb(i);
		es_table(selection,arrange);
		arrange.pop_back();
	}
}
void es_material(vector<pii> &v){
	if(v.size()==3){
		vector<int> init;
		es_table(v,init);
		return;	
	}
	for(int i=0;i<n;i++){
		if(!check[i]){
			for(int j=0;j<4;j++){
				check[i]=true;
				v.pb(mp(i,j));
				es_material(v);
				v.pop_back();
				check[i]=false;
			}
		}
	}
}
int main(){
	vector<pii> start;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				scanf("%d",&material[i][j][k][0]);
			}
		}
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				material[i][j][k][1]=material[i][3-k][j][0];
				material[i][j][k][2]=material[i][3-j][3-k][0];
				material[i][j][k][3]=material[i][k][3-j][0];
			}
		}
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				scanf(" %c",&color[i][j][k][0]);	
			}
		}
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				color[i][j][k][1]=color[i][3-k][j][0];
				color[i][j][k][2]=color[i][3-j][3-k][0];
				color[i][j][k][3]=color[i][k][3-j][0];
			}
		}
	}
	es_material(start);
	printf("%d",ans);
}
