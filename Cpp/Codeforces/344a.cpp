#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a[100005]; cin>>n;
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  int cur=1,groups=1;
  for (int i=1; i<n; i++){
    if(a[i]==a[i-1]) cur++;
    else{
      cur=1;
      groups++;
    }
  }
  cout<<groups;
  return 0;
}
