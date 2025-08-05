#include <iostream>
#include <cmath>
using namespace std;

void getUserInputs(double &width, double &distance, double &underwaterCost, double &landCost) 
{
    cout << "Enter the width of the river (in km): ";
    cin >> width;

    cout << "Enter the distance downstream to the factory (in km): ";
    cin >> distance;

    cout << "Enter the cost per meter underwater: ";
    cin >> underwaterCost;

    cout << "Enter the cost per meter over land: ";
    cin >> landCost;
}


double calculateUnderwaterDistance(double width_m, double x_m)
{
    return sqrt((width_m * width_m) + (x_m * x_m));
}


double calculateTotalCost(double x, double width_m, double distance_m, double underwaterCost, double landCost)
{
    double underwaterLength = calculateUnderwaterDistance(width_m, x);
    double landLength = distance_m - x;
    return (underwaterLength * underwaterCost) + (landLength * landCost);
}


void findCheapestCablePath(double width, double distance, double underwaterCost, double landCost) 
{
    double width_m = width * 1000;       // convert to meters
    double distance_m = distance * 1000; // convert to meters

    double minCost = 1e9;  // a huge number to start with
    double bestX = 0;

    for (int x = 0; x <= distance_m; x++)
        {
        double cost = calculateTotalCost(x, width_m, distance_m, underwaterCost, landCost);

        if (cost < minCost) {
            minCost = cost;
            bestX = x;
        }
    }

    double bestUnderwater = calculateUnderwaterDistance(width_m, bestX);
    double bestLand = distance_m - bestX;

    cout << "\n🏆 Best path found:\n";
    cout << "• Underwater length: " << bestUnderwater << " meters\n";
    cout << "• Overland length: " << bestLand << " meters\n";
    cout << "• Total cost: $" << minCost << endl;
}


int main()
{
    double width, distance, underwaterCost, landCost;

    getUserInputs(width, distance, underwaterCost, landCost);
    findCheapestCablePath(width, distance, underwaterCost, landCost);

    return 0;
}
