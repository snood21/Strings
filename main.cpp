#include "strings.h"

using namespace strings;

int main ()
{
  setlocale(LC_ALL, "Russian");
  String str1 = "Hello";
  std::cout << str1 << std::endl;
  String str2 = "World";
  std::cout << str2 << std::endl;

  str1 += str2;
  std::cout << str1 << std::endl;

  std::cout << delimiter << std::endl;
  String str3;
  str3 = str1 + str2;
  std::cout << delimiter << std::endl;
  std::cout << str3 << std::endl;

  return 0;
}

