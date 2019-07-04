#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int a[26]={}; 
	cin>>s;
	for(int i=0;i<s.size();i++){
		a[s[i]-'a']++;
	}
	for(int i=0;i<26;i++){
		cout<<a[i]<<' ';
	}
}
