#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, l=0;
  long long ans=0,mod= 1e9+7;
  cin >> n;
  vector<int> x(n);
  for(int i=0; i<n; ++i){
    cin>> x[i];
  }
  vector<int> z(x);
  sort(z.begin(), z.end());
  z.erase(unique(z.begin(), z.end()), z.end());
  for (int i=0; i<n; ++i){
    x[i] = lower_bound(z.begin(),z.end(), x[i])- z.begin();
  }
  vector<int> cnt(z.size(), 0);
  for (int r=0; r<n; ++r){
    cnt[x[r]]++;
    while (cnt[x[r]]> 1){
      cnt[x[l]]--;
      l++;
    }
    ans = (ans+ (r-l+1))% mod;
  }
  cout<<ans<< "\n";
  return 0;
}
