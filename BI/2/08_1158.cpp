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
	list<int> ls;
	int N,K;
	cin>>N>>K;
	for(int i=1;i<=N;i++)ls.push_back(i);
	auto pt=ls.begin();
	cout<<"<";
	while(N>0){
		if(N>1){
			int cnt=K-1;
			while(cnt>0){
				pt++;
				if(pt==ls.end())pt=ls.begin();
				cnt--;
			}
			cout<<*pt<<", ";
			pt=ls.erase(pt);
			if(pt==ls.end())pt=ls.begin();			
		}
		else cout<<*pt;
		N--;
	}
	cout<<">";
}
