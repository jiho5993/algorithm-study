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
	int size=0,ans=0;
	string stick;
	cin>>stick;
	for(int i=0;i<stick.size();i++){
		if(stick[i]=='(')size++;
		else{
			size--;
			if(i>0&&stick[i-1]==')')ans++;
			else ans+=size;
		}
	}
	cout<<ans;
}
