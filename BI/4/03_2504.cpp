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
	int ans=0;
	stack<int> s;
	string vps;
	cin>>vps;
	for(int i=0;i<vps.size();i++){
		if(vps[i]=='(')s.push(0);
		else if(vps[i]=='[')s.push(1);
		else{
			if(s.empty()||(vps[i]==')' && s.top()==1)||(vps[i]==']'&&s.top()==0))return !printf("0");
			s.pop();
		}
	}
	if(!s.empty())return !printf("0");
	for(int i=0;i<vps.size();i++){
		if(vps[i]=='(')s.push(0);
		else if(vps[i]=='[')s.push(1);
		else{
			if(vps[i]==']'){
				int val=0;
				while(!s.empty()&&s.top()>1){
					val+=s.top();
					s.pop();
				}
				s.pop();
				if(!val)s.push(3);
				else s.push(3*val);
			}
			else{
				int val=0;
				while(!s.empty()&&s.top()>1){
					val+=s.top();
					s.pop();
				}
				s.pop();
				if(!val)s.push(2);
				else s.push(2*val);
			}
		}
	}
	while(!s.empty()){
		ans+=s.top();
		s.pop();
	}
	cout<<ans;
}
