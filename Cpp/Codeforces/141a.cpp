#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string a,b,x; cin>>a>>b>>x;
  int cnt[27]={0};
  int cx[27]={0};
  for(int i=0; i<a.length(); i++){
    char c=a[i];
    cnt[c-'A']++;
  }
  for(int i=0; i<b.length(); i++){
    char c=b[i];
    cnt[c-'A']++;
  }
  for(int i=0; i<x.length(); i++){
    char c=x[i];
    cx[c-'A']++;
  }
  for (int i=0; i<26; i++){
    if(cx[i]!=cnt[i]){
      cout<<"NO";
      return 0;
    }
  }
  cout<<"YES";
  return 0;
}
