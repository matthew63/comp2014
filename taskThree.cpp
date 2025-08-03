  GNU nano 8.1                                                                                                                     taskThree.cpp
#include<iostream>
using namespace std;

void sort(int& a, int& b, int& c)
{

    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);

}

int main()

{

int a = 322;
int b = 45;
int c = 160;


    sort(a, b, c);

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;

    return 0;
}
