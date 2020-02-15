// A palindromic number reads the same both ways.
// The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

// Find the largest palindrome made from the product of two 3-digit numbers.

#include <iostream>
#include <vector>

using namespace std;
bool isPalindrome(int n);

int numBuf[6];
int numBufSize = 0;
int main()
{
    int largestPalindrome = 0;
    int mulBuffer;
    for(int i = 100; i < 999; i++)
    {
        for(int j = i; j < 999; j++)
        {
            mulBuffer = i*j;
            if(isPalindrome(mulBuffer) && largestPalindrome < mulBuffer)
            {
                largestPalindrome = mulBuffer;
            }
        }
    }

    cout << "The largest palindrome product of two three-digit numbers is:" << endl;
    cout << largestPalindrome << endl;

    return 0;
}

bool isPalindrome(int n)
{
    numBufSize = 0;
    do
    {
        numBuf[numBufSize++] = n % 10;
        n = n / 10;
    }
    while(n / 10 > 0);
    numBuf[numBufSize++] = n % 10;

    if(numBufSize % 2 != 0)
        return false;

    for(int i = 0; i < numBufSize / 2; i++)
    {
        if(numBuf[i] != numBuf[numBufSize - 1 - i])
        {
            return false;
        }
    }

    return true;
}
