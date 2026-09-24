#include <bits/stdc++.h>
using namespace std;
int n, a[200005],b[200005];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i=0; i< n; ++i)
  {
    cin>> a[i];
    b[i]= a[i];
  }
  sort(b, b+n);
  for (int i=0; i<n; ++i)
    if(a[i]< b[n]){
      cout << a[i]- b[n]<< ' ';
    }
    else cout << a[i]-b[n-1]<< ' ';
}
