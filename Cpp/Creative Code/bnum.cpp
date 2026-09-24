#include <bits/stdc++.h>
using namespace std;
long long n, s,n2;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  n2= n;
  while(n>0){
    int d = n %10;
    s += d*d;
    n = n/10;
  }
  long long max_=max(s,2LL);
  vector<bool> p(max_+1, true);
  p[0] = p[1] = false;
  for (int k=2; k*k <= max_; k++)
  {
    if (p[k])
    {
      for (int i=k*k; i<=max_; i+=k) p[i] = false;
    }
  }
  if (p[s]) cout << "1";
  else cout << "-1";
  cout <<"\n"<< s;
  return 0;
}
