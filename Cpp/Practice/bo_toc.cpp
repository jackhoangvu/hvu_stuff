#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  map<int,int> cnt;
  for (int i=0; i<n; i++){
    long long x; cin>>x;
    cnt[x]++;
  }
  long long sum=0;
  for(auto x:cnt){
    sum+=(x.second/x.first);
  }
  cout<<sum<<"\n";
  return 0;
}
