#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  vector<string> st;
  while(cin>>s){
    st.push_back(s);
    if(cin.peek()=='\n') break;
  }
  cout<<st.size()<<"\n";
  for(auto x:st){
    cout<<x<<"\n";
  }
  return 0;
}
