#include <bits/stdc++.h>
using namespace std;
const int mx=100005;
int a[mx];
int temp[mx];
long long ans=0;
void merge_sort(int l,int r)
{
  if (l>=r) return;
  int m=(l+r)>>1;
  merge_sort(l,m);
  merge_sort(m+1,r);
  int i=l,j=m+1,k=l;
  while (i<=m&&j<=r)
  {
    if (a[i]<=a[j])
    {
      temp[k++]=a[i++];
    }
    else
    {
      temp[k++]=a[j++];
      ans+=(long long)(m-i+1);
    }
  }
  while (i<=m) temp[k++]=a[i++];
  while (j<=r) temp[k++]=a[j++];
  for (i=l; i<=r; i++)
  {
    a[i]=temp[i];
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  for (int i=0; i<n; i++)
  {
    cin>>a[i];
  }
  merge_sort(0,n-1);
  cout<<ans<<"\n";
  return 0;
}
