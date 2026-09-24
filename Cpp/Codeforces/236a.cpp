#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s; cin>>s;
  int freq[26]={0}, ans=0;
  for(char c:s){
    if(freq[c-'a']==0) {ans++; freq[c-'a']++;}
    else freq[c-'a']++;
  }
  cout<<(ans%2==0?"CHAT WITH HER!":"IGNORE HIM!");
  return 0;
}
