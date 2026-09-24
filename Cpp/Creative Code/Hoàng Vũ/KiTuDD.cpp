#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("KiTuDD.Inp","r",stdin);
  freopen("KiTuDD.Out","w",stdout);
  int n; cin>>n;
  unordered_map<string,int> freq;
  for (int i=0; i<n; i++){
    string s; cin>>s;
    sort(s.begin(),s.end());
    s.erase(unique(s.begin(),s.end()),s.end());
    freq[s]++;
  }
  long long cnt=0;
  for(auto& x:freq){
    int f=x.second;
    // cnt+=(1LL*(f*(f-1)/2));
    cnt+=((long long)f*(f-1)/2);
  }
  cout<<cnt<<"\n";
  return 0;
}
