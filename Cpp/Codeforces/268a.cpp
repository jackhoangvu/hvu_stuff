#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, h[31],a[31];
  cin>>n;
  for (int i=0; i<n; i++){
    cin>>h[i]>>a[i];
  }
  int cnt=0;
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      if(h[i]==a[j]&&(i!=j)) cnt++;
    }
  }
  cout<<cnt;
  return 0;
}
