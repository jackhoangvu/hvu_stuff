#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a[105]; cin>>n;
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  if(n==1) {cout<<"NO"; return 0;}
  int ans=0;
  sort(a,a+n);
  for (int i=1; i<n; i++){
    if(a[i]>a[0]) {cout<<a[i]; return 0;}
  }
  cout<<"NO";
  return 0;
}
