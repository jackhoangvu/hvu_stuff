#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s; cin>>s;
  vector<int> n;
  for(char c:s){
    if(c!='+') n.push_back(c-'0');
  }
  sort(n.begin(),n.end());
  for(int i=0; i<n.size(); i++){
    cout<<n[i];
    if(i!=n.size()-1) cout<<"+";
  }
  return 0;
}
