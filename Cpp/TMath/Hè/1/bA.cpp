#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  vector<int> a(n);
  for (int i=1; i<=n; i++){
    cin>>a[i];
  }
  int cnt=0;
  for(int i=1; i<n; i++){
    for(int j=i+1; j<=n; j++){
      if(a[i]>a[j]){swap(a[i],a[j]); cnt++;}
    }
  }
  cout<<cnt<<"\n";
  return 0;
}
