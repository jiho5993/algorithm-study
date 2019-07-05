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
	int N,deck[20001]={},frt=0,bak=0,size=0;
	cin>>N;
	for(int i=0;i<N;i++){
		string order;
		cin>>order;
		if(order=="push_front"){
			int x,tmp;
			cin>>x;
			tmp=deck[frt];
			for(int j=frt+1;j<=bak;j++){
				int tmp2=deck[j];
				deck[j]=tmp;
				tmp=tmp2;
			}
			size++;
			bak++;
			deck[frt]=x;
		}
		else if(order=="push_back"){
			int x;
			cin>>x;
			deck[bak++]=x;
			size++;
		}
		else if(order=="pop_front"){
			if(size==0)cout<<"-1\n";
			else{
				cout<<deck[frt++]<<'\n';
				size--;
			}
		}
		else if(order=="pop_back"){
			if(size==0)cout<<"-1\n";
			else{
				cout<<deck[bak-1]<<'\n';
				bak--;
				size--;
			}
		}
		else if(order=="size")cout<<size<<'\n';
		else if(order=="back"){
			if(size>0)cout<<deck[bak-1]<<'\n';
			else cout<<"-1\n";
		}
		else if(order=="front"){
			if(size>0)cout<<deck[frt]<<'\n';
			else cout<<"-1\n";
		}
		else{
			if(size==0)cout<<"1\n";
			else cout<<"0\n";
		}
	}
}
