#include "strings.h"

using namespace strings;

int main ()
{
  setlocale(LC_ALL, "Russian");
  
  /*String str6{10};
  str6.print ();
  
  String str7{"Hello"};
  str7.print();
  
  String str1 = "Hello";
  std::cout << str1 << std::endl;
  String str2 = "World";
  std::cout << str2 << std::endl;

  str1 += str2;
  std::cout << str1 << std::endl;*/
  
  String str1;
  std::cout << "Введите строку: ";
  std::cin >> str1;
  std::cout << "Ваша строка: " << str1 << std::endl;
  
  return 0;
}

