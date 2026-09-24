#include <bits/stdc++.h>
using namespace std;
int L,R, ans;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >>L>> R;
  vector<int> S(R+1, 0);
  for (int i=1; i<= R/2; ++i)
  {
    for (int j= 2*i; j<=R; j+= i) S[j] += i;
  }
  for (int a=L; a <=R; ++a)
    if (S[a]> a && S[a]<=R)
      if (S[S[a]]== a) ans++;
  cout<< ans;
  return 0;
}
