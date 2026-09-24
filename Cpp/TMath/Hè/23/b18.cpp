#include<bits/stdc++.h>
using namespace std;
long long po(int p){
  long long ans=1;
  while (p--)ans*=10;
  return ans;
}
long long cnt(long long n){
  if (n<0) return 0;
  if (n<10) return n;
  string s=to_string(n);
  int len=s.length();
  long long sum=9;
  for (int i=2; i<len; i++){
    sum+=9*po(i-2);
  }
  int f=s[0]-'0';
  int e=s.back()-'0';
  long long mid=0;
  if (len>2) mid=stoll(s.substr(1,len-2));
  sum+=(f-1)*po(len-2);
  if(len==2){
    if(e>=f) sum+=1;
    else sum+=mid;
  }
  else sum+=mid;
  if(e>=f) sum+=1;
  return sum;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long l,r;
  cin>>l>>r;
  cout<<cnt(r)-cnt(l-1)<<"\n";
  return 0;
}
