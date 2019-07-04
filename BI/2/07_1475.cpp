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
	int n[10]={},cnt;
	string s;
	cin>>s;
	for(auto c:s)n[c-'0']++;
	cnt=min(n[6],n[9])+(max(n[6],n[9])-min(n[6],n[9]))/2+(max(n[6],n[9])-min(n[6],n[9]))%2;
	for(int i=0;i<=8;i++){
		if(i!=6)cnt=max(cnt,n[i]);
	}
	printf("%d",cnt);
}
