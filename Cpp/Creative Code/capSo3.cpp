#include <bits/stdc++.h>

using namespace std;
int n, a[1000005];
long long c[3];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >>n;
  for(int i=0; i<n; ++i){
    cin >>a[i];
    c[a[i]% 3]++;
  }
  cout << c[0]*(c[0]-1)/2 + c[1] * c[2];
  return 0;
}
