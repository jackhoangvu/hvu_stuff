#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k; cin>>n>>k;
  string s; cin>>s;
  bool sa=false,sb=false;
  vector<char> ch;
  for(char c:s){
    if(c=='a'){
      if(sa==false){
        ch.push_back(c); sa=true;
      }
    }
    else if(c=='b'){
      if(sb==false){
        ch.push_back(c); sb=true;
      }
    }
  }
  // for(char c:ch) cout<<c<<" ";
  int ans=0;
  for(char c:ch){
    int l=0,j=0;
    for(int r=0; r<n; r++){
      if(s[r]!=c) j++;
      while(j>k){
        if(s[l]!=c) j--;
        l++;
      }
      ans=max(ans,r-l+1);
    }
  }
  cout<<ans;
  return 0;
}
