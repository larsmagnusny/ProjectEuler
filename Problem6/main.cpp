// The sum of the squares of the first ten natural numbers is,
// 1^2+2^2+...+10^2=385
// The square of the sum of the first ten natural numbers is,

// (1+2+...+10)2=552=3025
// Hence the difference between the sum of the squares of the first ten natural numbers
// and the square of the sum is 3025−385=2640.

// Find the difference between the sum of the squares of the first
// one hundred natural numbers and the square of the sum.

#include <iostream>

using namespace std;

int main()
{
    int sumSquare = 0;
    int squareSum = 0;
    for(int i = 1; i <= 100; i++)
    {
        sumSquare += i;
        squareSum += i*i;
    }

    sumSquare *= sumSquare;

    cout << "The difference between the sum of the squares of the first one hundret natural numbers and the square of the sum is:" << endl;
    cout << sumSquare - squareSum << endl;

    return 0;
}
