#include <bits/stdc++.h>
using namespace std;
long long n; int k;
bool sang(int n){
  if (n< 2) return false;
  for (int i= 2; i*i<=n;++i)
    if (n%i==0) return false;
  return true;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  long long x=0,s=n *(n+1)/ 2;
  for (int r = 2; r<k; ++r){
    if (sang(r) and r<=n){
      long long a = (n-r)/k + 1;
      if (n<r){
        a=0;
      }
      x += a*r + k*a*(a-1)/2;
    }
  }
  cout << x << "\n"<< s-x;
  return 0;
}
