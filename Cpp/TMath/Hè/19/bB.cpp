#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n,k; cin>>n>>k;
  vector<int> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  long long sum=0;
  for (int i=n-k; i<n; i++){
    sum+=a[i];
  }
  cout<<sum;
  return 0;
}
