#include <bits/stdc++.h>
using namespace std;
int c[3];
string ans;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; int a[21]; cin>>n;
  for (int i=0; i<n; i++){
    cin>>a[i];
    if(i%3==1) c[1]+=a[i];
    else if(i%3==0) c[0]+=a[i];
    else c[2]+=a[i];
  }
  int ans=max(max(c[1],c[2]),c[0]);
  if(ans==c[0]) cout<<"chest";
  else if(ans==c[1]) cout<<"biceps";
  else cout<<"back";
  return 0;
}
