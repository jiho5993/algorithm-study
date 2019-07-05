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
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		int n,rev=0,err=0;
		deque<int> dq;
		string p;
		getchar();
		cin>>p;
		scanf("%d",&n);
		scanf(" [");
		for(int j=0;j<n;j++){
			int x;
			if(j==n-1)scanf("%d]",&x);
			else if(j<n-1)scanf("%d,",&x);
			dq.push_back(x);
		}
		for(int j=0;j<p.size();j++){
			if(p[j]=='R')rev++;
			else if(!dq.empty()){
				if(rev%2==0)dq.pop_front();
				else dq.pop_back();
			}
			else err=1;
		}
		if(!err){
			cout<<"[";
				while(!dq.empty()){
					if(rev%2==0){
						cout<<dq.front();
						dq.pop_front();
					}
					else{
						cout<<dq.back();
						dq.pop_back();
					}
					if(!dq.empty())cout<<",";
				}
			cout<<"]\n";
		}
		else cout<<"error\n";
	}
}
