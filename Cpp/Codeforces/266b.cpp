#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,t; cin>>n>>t;
  string s; cin>>s;
  vector<int> num;
  for(char c:s){
    if(c=='B') num.push_back(1);
    else num.push_back(0);
  }
  while(t--){
    for(int i=0; i<num.size()-1; i++){
      if(num[i]==1&&num[i+1]==0){num[i]=0; num[i+1]=1;i++;}
    }
  }
  for (int i=0; i<num.size(); i++){
    cout<<(num[i]==1?"B":"G");
  }
  return 0;
}
