#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  int x; cin>>x;
  long long sum=0;
  for (int i=0; i<n; i++){
    long long y; cin>>y;
    if(x%y==0) sum+=y;
  }
  cout<<sum;
  return 0;
}
