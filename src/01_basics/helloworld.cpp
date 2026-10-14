#include <iostream>
#include <limits>

int main()
{
/*
  std::cout << "Enter number or something:";
 
  int x{};
  std::cin >> x;

  int y {};
  std::cin >> y;

  std::cout << "Your number(s)" << x << " " << y << '\n';
  */

  // learncpp.com section 1.5 question 2
  //Ask the user for 3 numbers, output should look like that:
  // Enter three numbers: 6 7 8
  // You entered 6, 7, and 8.
  //
  std::cout << "Enter three numbers: ";

  int x {};
  int y {};
  int z {};
  std::cin >> x >> y >> z;

  std::cout << "You entered " << x << ", " <<  y << ", and " << z << ".\n"; 

  int t;
  std::cout << t << '\n';

  return 0;
}
