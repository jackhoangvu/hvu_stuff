#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  string s; cin>>s;
  int c1=0,c2=0;
  for(char c:s){
    if(c=='A') c1++;
    else c2++;
  }
  if(c1==c2) cout<<"Friendship"<<"\n";
  else if(c1<c2) cout<<"Danik"<<"\n";
  else cout<<"Anton"<<"\n";
  return 0;
}
