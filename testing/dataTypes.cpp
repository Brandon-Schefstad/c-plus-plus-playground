#include <iostream>

using namespace std;

int main(){
  double price = 99.99;
  float interestRate = 3.67f;
  long fileSize = 90000000L ;
  char letter = 'a';
  bool isValide = false;


  // Can also use 'auto' on some, suffixes help make sure they are cast correctly 
  int number = 0xFF; // <- 255 in hex
  int number1{};
  cout << number1; // Will print 0 


  // Narrowing -> Will not compile
  // int number3 = 1'000'000;
  // short another{number3};
  // cout << another;
  return 0;
}