#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int x,n;
  cin>>x>>n;
  vector<int> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  //[0,8]
  //[0,3],[3,8]-> 3,5
  //[0,3],[3,6],[6,8] -> 3,3,2
  //[0,2],[2,3],[3,6],[6,8] -> 2,1,3,2

  return 0;
}
