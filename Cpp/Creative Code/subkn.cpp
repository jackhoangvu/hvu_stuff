#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<long long> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  int cnt=0;
  map<long long,int> p;
  int l=0,mx=0;
  for (int r=0; r<n; r++){
    auto it=p.find(a[r]);
    if (it!=p.end()&&it->second>=l){
      l=it->second+1;
    }
    p[a[r]]=r;
    int cur=r-l+1;
    if (cur> mx){
      mx=cur;
      cnt=1;
    }
    else if(cur==mx){
      cnt++;
    }
  }
  cout<<mx<<"\n"<<cnt;
  return 0;
}
