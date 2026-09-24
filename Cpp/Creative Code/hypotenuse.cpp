#include <iostream>
#include <math.h>

int main()
{
  int a, b;
  std::cout << "What's the first length?: " << '\n';
  std::cin >> a;

  std::cout << "What's the second length?: " << '\n';
  std::cin >> b;

  double c = std::sqrt(pow(a, 2) + pow(b, 2));

  std::cout << c;

  return 0;
}