// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

// What is the 10 001st prime number?

#include <iostream>

using namespace std;

int nextPrime(int n);

int main()
{
    int n = 0;
    for(int i = 0; i < 10001; i++)
    {
        n = nextPrime(n);

    }

    cout << "The 10001th prime is: " << endl;
    cout << n << endl;

    return 0;
}

int nextPrime(int n)
{
    bool isPrime = false;
    n++;
    if(n == 1)
    {
        isPrime = false;
        return 2;
    }

    if(n == 2)
    {
        isPrime = true;
        return 2;
    }

    while(!isPrime)
    {
        isPrime = true;

        for(int i = 2; i <= n / 2; i++)
        {
            if(n % i == 0)
            {
                isPrime = false;
                i = n;
            }
        }

        n++;
    }

    return n-1;
}
