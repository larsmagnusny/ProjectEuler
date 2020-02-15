//A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

//a2 + b2 = c2
//For example, 32 + 42 = 9 + 16 = 25 = 52.

//There exists exactly one Pythagorean triplet for which a + b + c = 1000.
//Find the product abc.

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c, result = 0;
    bool tripletFound = false;
    for(a = 1; a < 5000 && !tripletFound; a++)
    {
        for(b = a+1; b < 5000 && !tripletFound; b++)
        {
            for(c = b+1; c < 5000 && !tripletFound; c++)
            {
                if(a < b < c && c*c == a*a+b*b)
                {
                    if(a + b + c == 1000)
                    {
                        result = a * b * c;
                        tripletFound = true;
                    }
                }
            }
        }
    }

    cout << "The product of the Pythagorean triplet for which a + b + c = 1000 is: " << endl;
    cout << result << endl;

    return 0;
}

int GetTriplet(int n0, int n1)
{
    return n0*n1;
}
