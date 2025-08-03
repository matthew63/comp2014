  GNU nano 8.1                                                                                                                      taskTwo.cpp
#include<iostream>
using namespace std;

void twoInteger(int numerator, int denominator, int& quotient, int& remainder )
{
   quotient = numerator / denominator;
   remainder = numerator % denominator;
}

int main()
{

int num = 17;
int denom = 5;
int q, r;

twoInteger(num, denom, q, r);

cout << "quotient: " << q << endl;
cout << "remainder: " << r << endl;

return 0;
}



