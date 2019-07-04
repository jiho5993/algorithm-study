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
	int f1[26]={},f2[26]={},ans=0;
	string s1,s2;
	cin>>s1>>s2;
	for(int i=0;i<s1.size();i++)f1[s1[i]-'a']++;
	for(int i=0;i<s2.size();i++)f2[s2[i]-'a']++;
	for(int i=0;i<26;i++)ans+=abs(f1[i]-f2[i]);
	cout<<ans;
}
