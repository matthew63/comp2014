  GNU nano 8.1                                                                                                                 practicalTaskOne.cpp
#include <iostream>
#include <string>
using namespace std;

void testDefaultArg(int day = 1, string month= "Jan", int year = 2023)

 {
cout << "Today is " << day <<" "
<< month << " " << year << endl;
 }

 int main ()

 {
 testDefaultArg();
 testDefaultArg(10);
 testDefaultArg(10, "Jul");
 testDefaultArg(10, "Jul", 2023);
 }

