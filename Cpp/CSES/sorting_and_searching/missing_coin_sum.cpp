#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<int> a(n+1);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  long long tar=1;
  for (int i=0; i<n; i++){
    if(a[i]<=tar) tar+=a[i];
    else{
      cout<<tar<<"\n";
      return 0;
    }
  }
  tar+=a[n];
  cout<<tar;
  return 0;
}
