#include "hugeint.h"

HugeInt::HugeInt()
    : capacity{DEFAULT_CAPACITY}, data{new char[DEFAULT_CAPACITY]{0}}, size{0}
{
}

HugeInt::HugeInt(size_t _capacity)
    : capacity{_capacity}, size{0}
{
    data = new char[capacity]{0};
}

HugeInt::HugeInt(const string& number)
{
    if(number.length() > DEFAULT_CAPACITY)
        capacity = number.length();
    else
        capacity = DEFAULT_CAPACITY;

    data = new char[capacity];

    size = number.length();

    for(size_t i = 0; i < size; i++)
    {
        data[i] = number[i]-'0';
    }
}

HugeInt::HugeInt(char *_data, size_t _capacity, size_t _size)
    : capacity{_capacity}, data{_data}, size{_size}
{

}

HugeInt::~HugeInt()
{
    delete[] data;
    data = nullptr;
}

HugeInt HugeInt::operator+(const HugeInt& other)
{
    bool thisLargest = size >= other.size ? true : false;

    int bufferSize = (thisLargest ? size : other.size)+1;

    char* buffer = new char[bufferSize];

    if(thisLargest)
    {
        int counter = other.size-1;
        for(int i = bufferSize-1; i >= 0; i--)
        {
            buffer[i] = counter >= 0 ? other.data[counter--] : 0;
        }

        counter = size-1;

        for(int i = bufferSize-1; i >= 1; i--)
        {
            buffer[i] += counter >= 0 ? data[counter--] : 0;

            while(buffer[i] > 9)
            {
                buffer[i-1] += 1;
                buffer[i] -= 10;
            }
        }
    }
    else
    {
        int counter = size - 1;
        for(int i = bufferSize-1; i >= 0; i--)
        {
            buffer[i] = counter >= 0 ? data[counter--] : 0;
        }

        counter = other.size - 1;

        for(int i = bufferSize-1; i >= 0; i--)
        {
            buffer[i] += counter >= 0 ? other.data[counter--] : 0;

            while(buffer[i] > 9)
            {
                buffer[i-1] += 1;
                buffer[i] -= 10;
            }
        }
    }

    int leadingStart = 0;

    if(buffer[0] == 0)
    {
        while(buffer[leadingStart] == 0)
        {
            leadingStart++;
        }

        for(int i = 0; i < bufferSize-leadingStart; i++)
        {
            buffer[i] = buffer[i+leadingStart];
        }

        bufferSize -= leadingStart;
    }

    return HugeInt(buffer, bufferSize+leadingStart, bufferSize);
}

HugeInt HugeInt::operator+=(const HugeInt& other)
{
    return HugeInt();
}

string HugeInt::ToString()
{
    string str;

    for(size_t i = 0; i < size; i++)
    {
        str += data[i]+'0';
    }

    return str;
}
