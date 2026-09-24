#include<bits/stdc++.h>
using namespace std;
long long d[200005];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s; cin>>s;
  int sz=s.length();
  int m; cin>>m;
  vector<int>a(m);
  while(m--){
    int k; cin>>k;
    if(s.size()>=k) d[s.size()-k]++;
  }
  long long sum=0;
  for(int i=0; i*2<s.size(); i++){
    sum+=d[i];
    if(sum%2==1) swap(s[i],s[s.size()-i-1]);
  }
  cout<<s;
  return 0;
}
