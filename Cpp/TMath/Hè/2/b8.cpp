#include <bits/stdc++.h>

using namespace std;
vector<long long> vt;
void pr(long long n){
  if(n<=1) return;
  long long mx=sqrt(n);
  for(int i=1; i<=mx; i++){
    if(n%i==0){
      vt.push_back(i);
      if(i*i!=n) vt.push_back(n/i);
    }
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  pr(n);
  sort(vt.begin(),vt.begin()+vt.size());
  for (int i=0; i<vt.size(); i++){
    cout<<vt[i]<<" ";
  }
  return 0;
}
