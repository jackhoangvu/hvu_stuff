#include <bits/stdc++.h>

using namespace std;
int n;
int a[100005];
long long f(int k){
  vector<long long> b(n);
  for(long long i=0; i<n; i++){
    b[i]=a[i]+(i+1)*k;
  }
  sort(b.begin(),b.end());
  long long s=0;
  for(int i=0; i<k; i++){
    s+=b[i];
  }
  return s;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long s;
  cin>>n>>s;
  for (int i=0; i<n; i++){
    cin>>a[i];
  }
  int l=0,r=n;
  while(l<=r){
    int mid=l+(r-l)/2;
    // cout<<mid<<" ";
    if(f(mid)<=s){
      l=mid+1;
    }
    else{
      r=mid-1;
    }
  }
  cout<<l-1<<" "<<f(l-1);
}
