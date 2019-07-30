#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll INF = 9876543210;
const ll mod = 1000000007;
const double PI = acos(-1);
char word[21];
int l,c; 
void es(vector<int> &curr){
	if(curr.size()==l){
		int vowel_cnt=0,con_cnt=0;
		for(int i=0;i<l;i++){
			char now=word[curr[i]];
			if(now=='a'||now=='e'||now=='i'||now=='o'||now=='u')vowel_cnt++;
			else con_cnt++;
		}
		if(vowel_cnt>=1&&con_cnt>=2){
			for(int i=0;i<l;i++){
				printf("%c",word[curr[i]]);
			}
			printf("\n");
		}
		return;
	}
	int go=curr.empty()?0:curr[curr.size()-1]+1;
	for(int i=go;i<c;i++){
		curr.pb(i);
		es(curr);
		curr.pop_back();
	}
}
int main(){
	scanf("%d %d",&l,&c);
	for(int i=0;i<c;i++){
		scanf(" %c",&word[i]);
	}
	sort(word,word+c);
	vector<int> init;
	es(init);
	return 0;
}
