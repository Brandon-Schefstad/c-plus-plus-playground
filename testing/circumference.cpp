#include <iostream>
#include <cmath>

using namespace std;

int main (){
  cout << "Enter a radius";
  int  radius;
  cin >> radius;

  const double pi = 3.14;

  cout << "Circumference: " << pi*radius*2;

}