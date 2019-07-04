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
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		string s;
		cin>>s;	
		list<char> ls;
		auto pt=ls.begin();
		for(int j=0;j<s.size();j++){
			if(s[j]=='<'){
				if(pt!=ls.begin())pt--;
			}
			else if(s[j]=='>'){
				if(pt!=ls.end())pt++;
			}
			else if(s[j]=='-'){
				if(pt!=ls.begin()){
					pt--;
					pt=ls.erase(pt);
				}
			}
			else ls.insert(pt,s[j]);
		}
		for(auto c:ls)cout<<c;
		cout<<'\n';
	}
}
