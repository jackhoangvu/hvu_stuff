#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m; cin>>n>>m;
  vector<long long> a(n),b(m);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  for (int i=0; i<m; i++){
    cin>>b[i];
  }
  sort(b.begin(),b.begin()+m);
  long long mx=-1e9;
  for(int x=0; x<n; x++){
    long long best=LLONG_MAX;
    auto it=lower_bound(b.begin(),b.end(),a[x]);
    if(it!=b.end()){
      long long d=a[x]-*it;
      best=min(best, d<0?-d:d);
    }
    if(it!=b.begin()){
      it--;
      long long d=a[x]-*it;
      best=min(best, d<0?-d:d);
    }
    mx=max(mx,best);
  }
  cout<<mx<<"\n";
  return 0;
}
