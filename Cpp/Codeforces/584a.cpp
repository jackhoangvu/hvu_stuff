#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,t; cin>>n>>t;
  string s="";
  if(t%10==0){
    if(n==1) {cout<<"-1"; return 0;}
    else{
      cout<<"1";
      for (int i=0; i<n-1; i++){
        cout<<"0";
      }
    }
  }
  else{
    for (int i=0; i<n; i++){
      cout<<t;
    }
  }
  cout<<s;
  return 0;
}
