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
	int N,stk[20001]={},ptr=0,size=0;
	cin>>N;
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		if(s=="push"){
			int num;
			cin>>num;
			stk[ptr++]=num;
			size++;
		}
		else if(s=="top"){
			if(size==0)cout<<"-1\n";
			else cout<<stk[ptr-1]<<'\n';
		}
		else if(s=="size")cout<<size<<'\n';
		else if(s=="pop"){
			if(size==0)cout<<"-1\n";
			else {
				cout<<stk[ptr-1]<<'\n';
				ptr--;
				size--;
			}
		}
		else{
			if(size==0)cout<<"1\n";
			else cout<<"0\n";
		}
	}
}
