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
	int n,w,l,curr_w=0,ans=0;
	scanf("%d %d %d",&n,&w,&l);
	queue<int> bridge;
	for(int i=0;i<n;i++){
		int truck;
		scanf("%d",&truck);
		while(1){
			if(bridge.empty()){
				bridge.push(truck);
				curr_w+=truck;
				ans++;
				break;
			}
			else{
				if(bridge.size()==w){
					curr_w-=bridge.front();
					bridge.pop();
				}
				else if(curr_w+truck>l){
					bridge.push(0);
					ans++;
				}
				else{
					bridge.push(truck);
					curr_w+=truck;
					ans++;
					break;
				}
			}
		}
	}
	printf("%d",ans+w);
}
