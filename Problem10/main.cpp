// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
// Find the sum of all the primes below two million.

#include <iostream>

using namespace std;

long long nextPrime(long long n);

int main()
{
    long long sum = 0;
    long long prime = 1;

    do
    {
        prime = nextPrime(prime);
        if(prime < 2000000)
            sum += prime;
    }
    while(prime < 2000000);

    cout << "The sum of all primes below 2 million is:" << endl;
    cout << sum << endl;

    return 0;
}

long long nextPrime(long long n)
{
    bool isPrime = false;
    long long i;
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

        for(i = 2; i <= n / 2; i ++)
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
