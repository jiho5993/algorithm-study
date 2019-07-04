#include <bits/stdc++.h>
using namespace std;
int main(){
	int N,v,num[201]={};
	cin>>N;
	for(int i=0;i<N;i++){
		int x;
		cin>>x;
		num[x+100]++;
	}
	cin>>v;
	cout<<num[v+100];
}
