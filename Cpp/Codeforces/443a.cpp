#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s; cin>>s;
  string ct="";
  for(char c:s){
    if(c!='{'&&c!='}'&&c!=',') ct+=c;
  }
  cout<<ct;
  return 0;
}
