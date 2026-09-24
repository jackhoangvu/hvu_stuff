#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  vector<int> v=a;
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  long long ans=LLONG_MAX;
  long long cnt1=binary_search(v.begin(),v.end(),1)?1:0;
  ans=min(ans,(long long)n+1-2*cnt1);
  long long cnt=0;
  for(int x:v){
    cnt++;
    long long cost=(long long)n+x-2*cnt;
    ans=min(ans,cost);
  }
  cout<<ans<<"\n";
}
