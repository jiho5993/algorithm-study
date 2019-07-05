#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    string s; cin >> s;
    stack<char> st;
    int cnt=0;
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '(') st.push(s[i]);
        else {
            st.pop();
            if(s[i-1] == '(') cnt += st.size();
            else cnt++;
        }
    }
    cout << cnt;

    return 0;
}