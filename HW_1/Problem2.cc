 #include <iostream>
using namespace std;

double knots_to_mpm (int knots)
{
    return knots * 6076.0 / 5280.0 *60.0;
}


int main()
{
    int integer;
    cout << "Please input an integer: ";
    cin >> integer;
    cout << integer << " knots = " << knots_to_mpm(integer) << " miles per minute";
    return 0;
}
