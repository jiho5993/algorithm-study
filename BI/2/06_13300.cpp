#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 987654321;
const ll mod = 1000000007;
const double PI = acos(-1);
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int N,K,boy[6]={},girl[6]={},room=0;
	cin>>N>>K;
	for(int i=0;i<N;i++){
		int S,Y;
		cin>>S>>Y;
		if(!S)girl[Y-1]++;
		else boy[Y-1]++;
	}
	for(int i=0;i<6;i++){
		if(boy[i]%K!=0)room++;
		if(boy[i]/K>0)room+=boy[i]/K;
		if(girl[i]%K!=0)room++;
		if(girl[i]/K>0)room+=girl[i]/K;
	}
	cout<<room;
}
