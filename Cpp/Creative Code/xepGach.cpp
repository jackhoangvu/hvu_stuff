#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<long long> a, b;
bool check(long long X){
  int k= 0;
  for (int i=0; i<n; ++i){
    if (a[i]< X) {
      long long t= X- a[i];
      while (k< m && b[k]< t) k++;
      if (k== m) return false;
      k++;
    }
  }
  return true;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  a.resize(n);
  b.resize(m);
  cin>>a[0];
  long long c=a[0];
  for (int i=1; i<n; ++i){
    cin>>a[i];
    c= min(c, a[i]);
  }
  long long t= 0;
  for (int i=0; i<m; ++i){
    cin>>b[i];
    t= max(t, b[i]);
  }
  long long l= 0;
  long long r= 2e18;
  long long ans= l;
  while (l<= r) {
    long long k= l+ (r-l) / 2;
    if (check(k)){
      ans= k;
      l= k +1;
    } else {
      r= k -1;
    }
  }
  cout<< ans<< "\n";
  return 0;
}
