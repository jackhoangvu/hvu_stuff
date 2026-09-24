#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int h,w; cin>>h>>w;
  long long ans=LLONG_MAX;
  for(int i=1; i<w; i++){
    long long s1=i*h, s2=((w-i)*h)/2,s3=(w-i)*h-s2;
    ans=min(ans,(max({s1,s2,s3})-min({s1,s2,s3})));
  }
  for(int i=1; i<h; i++){
    long long s1=i*w, s2=((h-i)*w)/2,s3=(h-i)*w-s2;
    ans=min(ans,(max({s1,s2,s3})-min({s1,s2,s3})));
  }

  if(w>=3){
    long long s1=w/3*h, s2=(w/3+(w%3>=1))*h,s3=(w/3+(w%3==2))*h;
    ans=min(ans,max({s1,s2,s3})-min({s1,s2,s3}));
  }
  if(h>=3){
    long long s1=h/3*w, s2=(h/3+(h%3>=1))*w,s3=(h/3+(h%3==2))*w;
    ans=min(ans,max({s1,s2,s3})-min({s1,s2,s3}));
  }

  cout<<ans<<"\n";
  return 0;
}
