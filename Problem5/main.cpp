// 2520 is the smallest number that can be divided
// by each of the numbers from 1 to 10 without any remainder.

// What is the smallest positive number that
// is evenly divisible by all of the numbers from 1 to 20?

#include <iostream>

using namespace std;

int main()
{
    bool evenlyDivisible = false;

    int n = 20;

    while(!evenlyDivisible)
    {
        evenlyDivisible = true;
        // Every number is evenly divisible by 1
        for(int i = 2; i <= 20; i++)
        {
            if(n % i != 0)
            {
                evenlyDivisible = false;
                i = 20;
            }
        }

        n++;
    }

    cout << "The first number evenly divisible by 1-20 is:" << endl;
    cout << (n-1) << endl;

    return 0;
}
