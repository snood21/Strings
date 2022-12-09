#pragma once

#include <iostream>
#include <cstring>

#define WIDTH 20
#define delimiter "\n--------------------------------------------\n"

namespace strings
{
  class String;
  String operator+(const String& left, const String& right);
  std::ostream& operator<< (std::ostream& os, const String& obj);
  
  class String
  {
    size_t size;
    char* str;
  public:
    //Get
    size_t get_size()const;
    const char* get_str()const;
    char* get_str();
    //Constructors
    explicit String(const size_t size = 80);
    String(const char* str);
    String(const String& other);
    String(String&& other);
    ~String();
    //Operators
    String& operator=(const String& other);
    String& operator=(String&& other);
    String& operator+=(const String& other);
    const char& operator[](int i)const;
    char& operator[](int i);
    //Methods
    void print()const;
  };
}