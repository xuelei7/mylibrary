#include <bits/stdc++.h>
using namespace std;

int main(){
  //input
  double Deg, Dis;

  //output
  string Dir;
  int W;

  cin >> Deg >> Dis;

  Deg /= 10;
  Dis /= 60;

  if (Deg < 11.25) Dir = "N";
  else if (Deg < 33.75) Dir = "NNE";
  else if (Deg < 56.25) Dir = "NE";
  else if (Deg < 78.75) Dir = "ENE";
  else if (Deg < 101.25) Dir = "E";
  else if (Deg < 123.75) Dir = "ESE";
  else if (Deg < 146.25) Dir = "SE";
  else if (Deg < 168.75) Dir = "SSE";
  else if (Deg < 191.25) Dir = "S";
  else if (Deg < 213.75) Dir = "SSW";
  else if (Deg < 236.25) Dir = "SW";
  else if (Deg < 258.75) Dir = "WSW";
  else if (Deg < 281.25) Dir = "W";
  else if (Deg < 303.75) Dir = "WNW";
  else if (Deg < 326.25) Dir = "NW";
  else if (Deg < 348.75) Dir = "NNW";
  else Dir = "N";

  if (Dis < 0.25) W = 0;
  else if (Dis < 1.55) W = 1 ;
  else if (Dis < 3.35) W = 2;
  else if (Dis < 5.45) W = 3;
  else if (Dis < 7.95) W = 4;
  else if (Dis < 10.75) W = 5;
  else if (Dis < 13.85) W = 6;
  else if (Dis < 17.15) W = 7;
  else if (Dis < 20.75) W = 8;
  else if (Dis < 24.45) W = 9;
  else if (Dis < 28.45) W = 10;
  else if (Dis < 32.65) W = 11;
  else W = 12;

  if (W == 0) cout << "C 0" << endl;
  else cout << Dir << " " << W << endl;
  return 0;
}
