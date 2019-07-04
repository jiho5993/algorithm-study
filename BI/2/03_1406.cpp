#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	string s;
	list<char> linked_list;
	cin>>s>>N;
	for(auto k:s)linked_list.push_back(k);
	auto cursor=linked_list.end();
	for(int i=0;i<N;i++){
		char order;
		scanf(" %c",&order);
		if(order=='L'&&cursor!=linked_list.begin())cursor--;
		else if(order=='D'&&cursor!=linked_list.end())cursor++;
		else if(order=='B'&&cursor!=linked_list.begin()){
			cursor--;
			cursor=linked_list.erase(cursor);
		}
		else if(order=='P'){
			char who;
			scanf(" %c",&who);
			linked_list.insert(cursor,who);
		}
	}
	for(auto it:linked_list)printf("%c",it);
}
