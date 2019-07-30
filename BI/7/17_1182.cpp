#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 987654321;
const ll mod = 1000000007;
const double PI = acos(-1);
int n,s,cnt,arr[21];
void es(vector<int> &numbers,int sum){
	if(sum==s)cnt++;
	else if(sum==INF)sum=0;
	int start=numbers.empty()?0:numbers[numbers.size()-1]+1;
	for(int i=start;i<n;i++){
		numbers.pb(i);
		es(numbers,sum+arr[i]);
		numbers.pop_back();
	}
}
int main(){
	vector<int> go;
	scanf("%d %d",&n,&s);
	for(int i=0;i<n;i++)scanf("%d",&arr[i]);
	es(go,INF);
	printf("%d",cnt);
}
