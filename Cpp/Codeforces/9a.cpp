#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int y,w; cin>>y>>w;
  int ma= max(y,w);
  if(ma==1) {cout<<"1/1"; return 0;}
  if(ma==2) {cout<<"5/6"; return 0;}
  if(ma==3) {cout<<"2/3"; return 0;}
  if(ma==4) {cout<<"1/2"; return 0;}
  if(ma==5) {cout<<"1/3"; return 0;}
  if(ma==6) {cout<<"1/6"; return 0;}
  return 0;
}
