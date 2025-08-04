#include <iostream>
#include <cmath>
using namespace std;

// 🧸 Step 1: Ask the user to give us the ingredients
void getUserInputs(double &width, double &distance, double &underwaterCost, double &landCost) {
    cout << "Enter the width of the river (in km): ";
    cin >> width;

    cout << "Enter the distance downstream to the factory (in km): ";
    cin >> distance;

    cout << "Enter the cost per meter underwater: ";
    cin >> underwaterCost;

    cout << "Enter the cost per meter over land: ";
    cin >> landCost;
}

// 🧸 Step 2: Use triangle math to calculate underwater distance
double calculateUnderwaterDistance(double width_m, double x_m) {
    return sqrt((width_m * width_m) + (x_m * x_m));
}

// 🧸 Step 3: Calculate cost for a specific x (where x is how far along the river we go underwater)
double calculateTotalCost(double x, double width_m, double distance_m, double underwaterCost, double landCost) {
    double underwaterLength = calculateUnderwaterDistance(width_m, x);
    double landLength = distance_m - x;
    return (underwaterLength * underwaterCost) + (landLength * landCost);
}

// 🧸 Step 4: Try every possible landing spot along the river
void findCheapestCablePath(double width, double distance, double underwaterCost, double landCost) {
    double width_m = width * 1000;       // convert to meters
    double distance_m = distance * 1000; // convert to meters

    double minCost = 1e9;  // a huge number to start with
    double bestX = 0;

    for (int x = 0; x <= distance_m; x++) {
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

// 🧸 Step 5: Run it all in main!
int main() {
    double width, distance, underwaterCost, landCost;

    getUserInputs(width, distance, underwaterCost, landCost);
    findCheapestCablePath(width, distance, underwaterCost, landCost);

    return 0;
}
