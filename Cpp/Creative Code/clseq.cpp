#include<bits/stdc++.h>

using namespace std;

int n,a[100005];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  sort(a,a+n);
  long long s=0;
  long long ans=0;
  for(int i=0; i<n; i++){
    ans+=1LL*a[i]*i-s;
    s+=a[i];
  }
  cout<<ans*2;
  return 0;
}
