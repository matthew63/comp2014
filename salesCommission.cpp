#include <iostream>
using namespace std;


double getDailySales() 
{
    double dailySales;
    cout << "Enter your daily sales value: ";
    cin >> dailySales;
    return dailySales;
}



double calculateCommission(double dailySales)

{
    if (dailySales <= 999)
        return dailySales * 0.03;
    else if (dailySales <= 2999)
        return dailySales * 0.035;
    else
        return dailySales * 0.045;
}

int main() 
{

    double dailySales = getDailySales();


    double commission = calculateCommission(dailySales);

    
    cout << "Your net commission is:\n$" << commission << "\nThank you.\n";

    return 0;
}
