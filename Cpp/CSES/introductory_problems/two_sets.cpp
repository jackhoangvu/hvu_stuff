#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  long long sum=n*(n+1)/2;
  if(sum%2!=0) {cout<<"NO"; return 0;}
  if(n%4==1||n%4==2) {cout<<"NO"; return 0;}
  if(n==3) {cout<<"YES\n"<<"2\n1 2\n1\n3"; return 0;}
  if(n==4){cout<<"YES\n"<<"2\n1 4\n2\n2 3"; return 0;}
  if(n%4==3){
    vector<int> div1={1,2}, div2={3},def;
    for (int i=4; i<=n; i++) def.push_back(i);
    for (int i=0; i<def.size()/4; i++){
      int ma=def[i]+def[def.size()-1-i];; //sum of the "last" and "end" elements that can group, like 4 5 6 7-> [4 7], [5, 6]
      div1.push_back(def[2*i]);//4
      div2.push_back(def[2*i+1]);//5
      div2.push_back(def[def.size()-1-2*i-1]);//7
      div1.push_back(def[def.size()-1-2*i]);//6
    }
    // 4 5 6 7 8 9 10 11
    //i =0 -> [4,11], [5,10]
    cout<<"YES\n";
    cout<<div1.size()<<"\n";
    for (int i=0; i<div1.size(); i++) cout<<div1[i]<<" ";
    cout<<"\n";
    cout<<div2.size()<<"\n";
    for (int i=0; i<div2.size(); i++) cout<<div2[i]<<" ";
  }
  else if(n%4==0){
    vector<int> div1, div2,def;
    for (int i=1; i<=n; i++) def.push_back(i);
    for (int i=0; i<def.size()/4; i++){
      int ma=def[i]+def[n-i-1];
      div1.push_back(def[2*i]);
      div2.push_back(def[2*i+1]);
      div2.push_back(def[def.size()-1-2*i-1]);
      div1.push_back(def[def.size()-1-2*i]);
    }
    cout<<"YES\n";
    cout<<div1.size()<<"\n";
    for (int i=0; i<div1.size(); i++) cout<<div1[i]<<" ";
    cout<<"\n";
    cout<<div2.size()<<"\n";
    for (int i=0; i<div2.size(); i++) cout<<div2[i]<<" ";
  }
  return 0;
}
