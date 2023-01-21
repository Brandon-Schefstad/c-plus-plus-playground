#include <iostream>
#include <cstdLib>
#include <ctime>

using namespace std;

int main (){
  cout << "How Many Faces on the Die? ";
  int faces;
  cin >> faces;
  srand(time(nullptr));
  short first = (rand() % faces - 1 + 1) + 1;
  short second = (rand() % faces - 1 + 1) + 1;
  cout << first << "," << second;
  return 0;
}