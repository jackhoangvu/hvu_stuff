#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n; cin>>n;
  long long m=(1<<n);
  vector<string> vt;
  for (int i=0; i<m; i++){
    string s="";
    for (int j=n-1; j>=0; j--){
      if((i>>j)&1) s+='1';
      else s+='0';
    }
    vt.push_back(s);
  }
  vector<bool> ok(m+1,true);
  for (int p=0; p<m; p++){
    string x=vt[p];
    for (int i=0; i<x.length()-1; i++){
      if(x[i]=='1'&&x[i+1]=='1'){
        ok[p]=false;
        break;
      }
    }
  }
  long long cnt=0;
  for (int i=0; i<m; i++){
    if(ok[i]){
      cnt++;
    }
  }
  cout<<cnt<<"\n";
  for (int i=0; i<m; i++){
    if(ok[i]){
      cout<<vt[i]<<"\n";
    }
  }
}
