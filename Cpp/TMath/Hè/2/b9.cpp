#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  while(t--){
    long long n; cin>>n;
    long long s=sqrt(n);
    if(s*s==n) cout<<"LE\n";
    else cout<<"CHAN\n";
  }
  return 0;
}
// #include <bits/stdc++.h>

// using namespace std;
// long long pr(long long n){
//   if(n==1) return 1;
//   long long cnt=0;
//   long long mx=sqrt(n);
//   for(int i=1; i<=mx; i++){
//     if(n%i==0){
//       cnt++;
//       if(i*i!=n) cnt++;
//     }
//   }
//   return cnt;
// }
// int main()
// {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   int t; cin>>t;
//   while(t--){
//     long long n; cin>>n;
//     cout<<(pr(n)%2==0?"CHAN":"LE")<<"\n";
//   }
//   return 0;
// }
