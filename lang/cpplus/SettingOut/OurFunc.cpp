// OurFunc.cpp -- defining your own function

#include <iostream>

void simon(int); // function prototype for simon()

int main(void)
{
    using namespace std;
    simon(3); // call the simon() function
    cout << "Pick an integer: ";
    int count;
    cin >> count;
    simon(count);
    cout << "Done!" << endl;
    return 0;
}

void simon(int n) // define the simon() function
{
    using namespace std;
    cout << "Simon says touch your toes " << n << " times." << endl;
} // void functions don't need return statements
