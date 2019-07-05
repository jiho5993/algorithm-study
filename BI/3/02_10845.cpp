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
	int que[20001],N,size=0,frt=0,bak=0;
	cin>>N;
	for(int i=0;i<N;i++){
		string order;
		cin>>order;
		if(order=="push"){
			int num;
			cin>>num;
			que[bak++]=num;
			size++;
		}
		else if(order=="front"){
			if(size>0)cout<<que[frt]<<'\n';
			else cout<<"-1\n";
		}
		else if(order=="back"){
			if(size>0)cout<<que[bak-1]<<'\n';
			else cout<<"-1\n";
		}
		else if(order=="size")cout<<size<<'\n';
		else if(order=="pop"){
			if(size>0){
				cout<<que[frt++]<<'\n';
				size--;
			}
			else cout<<"-1\n";
		}
		else{
			if(size==0)cout<<"1\n";
			else cout<<"0\n";
		}
	}
}
