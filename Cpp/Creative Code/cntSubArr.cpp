#include <bits/stdc++.h>
using namespace std;
long long n, k, ans, len;
int a[1000005];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  for (int i = 1;i <= n;i++) cin>>a[i];
  cin>>k;
  for (int i = 1;i <= n;i++){
    if (a[i]==k){
      ans+=len * (len+1) /2;
      len =0;
    } else{
      len++;
    }
  }
  ans+=len * (len+1) / 2;
  cout <<ans;
  return 0;
}
