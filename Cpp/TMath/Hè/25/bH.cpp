#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,d; cin>>n>>d;
  vector<int> a(n);
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  //k=3->a[i] a[i+1] a[i+2]
  sort(a.begin(),a.end());
  long long cnt=0;
  if(n<3) {cout<<0; return 0;}
  if(n==3){
    if(a[2]-a[0]<=d){cout<<1<<"\n";}
    else{cout<<0<<"\n";}
    return 0;
  }
  int j=0;
  for(int i=0; i<n; i++){
    while(j+1<n and a[j+1]-a[i]<=d) j++;
    long long k=j-i;
    cnt+=k*(k-1)/2;
  }
  cout<<cnt;
  return 0;
}
