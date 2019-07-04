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
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size())cout<<"Impossible\n";
		else{
			int a[26]={},no=0;
			for(int i=0;i<s1.size();i++){
				a[s1[i]-'a']++;
				a[s2[i]-'a']--;
			}
			for(int i=0;i<26;i++){
				if(a[i]!=0)no=1;
			}
			if(no)cout<<"Impossible\n";
			else cout<<"Possible\n";
		}
	}
}
