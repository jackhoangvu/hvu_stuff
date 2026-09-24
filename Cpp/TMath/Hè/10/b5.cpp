#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  int k; cin>>k;
  vector<int> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  int sum=0;
  int mi=INT32_MAX;
  int l=0;
  for (int r=0; r<n; r++){
    sum+=a[r];
    while(sum>=k){
      mi=min(mi,r-l+1);
      sum-=a[l];
      l++;
    }
  }
  cout<<mi;
  return 0;
}
