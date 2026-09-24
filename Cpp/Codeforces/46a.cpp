#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,c=0; cin>>n;
  //10
  //2 4 7 1 6 2 9 7 6
  for(int i=1; i<n; ++i){
    c=(c+i)%n;
    cout<<c+1<<" ";
  }
  return 0;
}
