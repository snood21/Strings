#include "strings.h"

namespace strings
{
  //Get
  size_t String::get_size ()const
  {
    return size;
  }

  const char* String::get_str ()const
  {
    return str;
  }

  char* String::get_str ()
  {
    return str;
  }

  //Constructors
  String::String (const size_t size):size(size), str(new char[size] {})
  {
    std::cout.width (WIDTH);
    std::cout << std::left << "DefaultConstructor:" << this << std::endl;
  }

  String::String (const char* str):String(std::strlen (str)+1)
  {
    std::strncpy (this->str, str, size);
    std::cout.width (WIDTH);
    std::cout << std::left << "Constructor:" << this << std::endl;
  }
  String::String (const String& other):String(other.str)
  {
    std::cout.width (WIDTH);
    std::cout << std::left << "CopyConstructor:" << this << std::endl;
  }

  String::String (String&& other):size(other.size), str(other.str)
  {
    other.size = 0;
    other.str = nullptr;
    std::cout.width (WIDTH);
    std::cout << std::left << "MoveConstructor:" << this << std::endl;
  }

  String::~String ()
  {
    delete[] str;
    std::cout.width (WIDTH);
    std::cout << std::left << "Destructor:" << this << std::endl;
  }

  //Operators
  String& String::operator= (const String& other)
  {
    if (this == &other)return *this;
    delete[] this->str;
    this->size = other.size;
    this->str = new char[size]
      {
      };
    std::strncpy (this->str, str, size);
    std::cout.width (WIDTH);
    std::cout << std::left << "CopyAssignment:" << this << std::endl;
    return *this;
  }

  String& String::operator= (String&& other)
  {
    if (this == &other)return *this;
    delete[] this->str;
    this->size = other.size;
    this->str = other.str;
    other.size = 0;
    other.str = nullptr;
    std::cout.width (WIDTH);
    std::cout << std::left << "MoveAssignment:" << this << std::endl;
    return *this;
  }

  String& String::operator+= (const String& other)
  {
    return *this = *this +other;
  }

  const char& String::operator[] (int i) const
  {
    return str[i];
  }

  char& String::operator[] (int i)
  {
    return str[i];
  }

  //Methods
  void String::print ()const
  {
    std::cout << "Size:\t" << size << std::endl;
    std::cout << "Str:\t" << str << std::endl;
  }

  String operator+ (const String& left, const String& right)
  {
    String cat (left.get_size () + right.get_size () - 1);
    for (int i = 0; i < left.get_size (); i++)
      {
        cat[i] = left[i];
      }
    for (int i = 0; i < right.get_size (); i++)
      {
        cat[i + left.get_size () - 1] = right[i];
      }
    return cat;
  }

  std::ostream& operator<< (std::ostream& os, const String& obj)
  {
    return os << obj.get_str ();
  }
}