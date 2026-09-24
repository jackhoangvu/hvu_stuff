#include <bits/stdc++.h>

using namespace std;
string solve(int d, string m) {
  for (char& c:m) c=toupper(c);
  if (m=="MAR") return (d>=21)?"Aries":"Pisces";
  if (m=="APR") return (d>=21)?"Taurus":"Aries";
  if (m=="MAY") return (d>=21)?"Gemini":"Taurus";
  if (m=="JUN") return (d>=21)?"Cancer":"Gemini";
  if (m=="JUL") return (d>=23)?"Leo":"Cancer";
  if (m=="AUG") return (d>=23)?"Virgo":"Leo";
  if (m=="SEP") return (d>=23)?"Libra":"Virgo";
  if (m=="OCT") return (d>=23)?"Scorpio":"Libra";
  if (m=="NOV") return (d>=23)?"Sagittarius":"Scorpio";
  if (m=="DEC") return (d>=22)?"Capricorn":"Sagittarius";
  if (m=="JAN") return (d>=20)?"Aquarius":"Capricorn";
  if (m=="FEB") return (d>=20)?"Pisces":"Aquarius";
  return "";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin>>t;
  while(t--){
    int d; cin>>d;
    string m; cin>>m;
    cout<<solve(d,m)<<"\n";
  }
  return 0;
}
