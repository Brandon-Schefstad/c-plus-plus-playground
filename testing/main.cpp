

#include <iostream>
#include <cmath>
using namespace std;

int main(){
  string userInput;
  cout << "What will you do? Look left | Look right | Look forward " << endl;
  cin >> userInput;
  cout << "\n executing: " << userInput;

  // cout << "Enter A State Tax Rate:";
  // double stateTax;
  // cin >> stateTax;

  // cout << "Enter A State Tax Rate:";
  // double countyTax;
  // cin >> countyTax;

  // const double salesAfterTax = sales - ((sales * stateTax) + (sales * countyTax));

  // cout << "Total Sales: " << sales << endl;
  // cout << "State Tax Owed: " << (sales * stateTax) << endl
  //      << "County Tax Owed " << (sales * countyTax) << endl
  //      << "After Taxes:  " << floor(salesAfterTax) << endl
  //      << "StateTax to 3rd power:  " << pow(stateTax, 3) << endl; 


  // int luckyNums[] = {1,2,3,4,5,6,7,8,9};
  // cout << luckyNums[1];

  return 0;
}

//   std::cout << pie << "<- this is pie"; <- Chaining together