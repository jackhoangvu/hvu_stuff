#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i=0; i<n; ++i)
  {
    int x;
    cin>> x;
    for(int i = 2; i*i <=x; ++i)
      if (x%i == 0){
        cout<<i<<" ";
        while(x%i == 0) x = x/i;
      }
    if(x >= 2) cout<<x;
    cout<<"\n";
  }
  return 0;
}
