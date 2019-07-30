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
	int cnt[10]={},num;
	scanf("%d",&num);
	string s=to_string(num);
	for(int i=0;i<s.size();i++){
		int unit_num=s[i]-'0'
		int add=stoi(s.substr(i+1));
		cnt[unit_num]+=add;
		for(int j=0;j<unit_num;j++){
				
		}
		
	}
	for(int i=0;i<=9;i++)printf("%d ",cnt[i]);
}

