#include <iostream>

using namespace std;

int main()
{
    long long i, j;
    long long result = 0;
    long long numDivisors = 0;
    long long maxNumDivisors = 0;
    long long counter = 0;
    bool resultFound = false;
    for(i = 0; !resultFound; i += ++counter)
    {
        numDivisors = 0;
        for(j = 1; j <= i / 2; j++)
        {
            if(i % j == 0)
            {
                numDivisors++;
            }
        }
        numDivisors++;

        if(numDivisors > maxNumDivisors)
        {
            maxNumDivisors = numDivisors;
            result = i;
            cout << i << " " << maxNumDivisors << endl;
        }

        if(maxNumDivisors > 500)
            resultFound = true;
    }
    return 0;
}
