//The prime factors of 13195 are 5, 7, 13 and 29.
//What is the largest prime factor of the number 600851475143 ?

#include <iostream>

using namespace std;

int nextPrime(int n);

int main()
{
    long long n = 600851475143;

    long long lPrimeFactor = 0;

    while(n != 1)
    {
        for(long long i = 2; i <= n; i++)
        {
            if(n % i == 0)
            {
                n = n / i;

                if(i > lPrimeFactor)
                    lPrimeFactor = i;

                i = n;
            }
        }
    }

    cout << "The largest prime factor in " << n << " is: " << endl;
    cout << lPrimeFactor << endl;

    return 0;
}
