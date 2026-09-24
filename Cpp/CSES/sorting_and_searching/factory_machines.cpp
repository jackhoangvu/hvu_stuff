#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n,t; cin>>n>>t;
  vector<long long> a(n);
  long long mi=INT32_MAX;
  for (int i=0; i<n; i++){
    cin>>a[i];
    mi=min(mi,a[i]);
  }

  long long l=0, r=mi*t, best=0;
  while(l<=r){
    long long mid=l+(r-l)/2;
    long long cur=0;
    for (int i=0; i<n; i++){
      cur+=(mid/a[i]);
      if(cur>=t) break;
    }
    if(cur>=t) {
      r=mid-1;
      best=mid;
    }
    else{
      l=mid+1;
    }
  }
  cout<<best;
  return 0;
}
