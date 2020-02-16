#ifndef HUGEINT_H
#define HUGEINT_H

#define DEFAULT_CAPACITY 20

#include <string>

using namespace std;

class HugeInt
{
public:
    HugeInt();
    HugeInt(size_t _capacity);
    HugeInt(const string &number);
    HugeInt(char *_data, size_t _capacity, size_t _size);
    ~HugeInt();

    HugeInt operator+(const HugeInt& other);
    HugeInt operator+=(const HugeInt& other);

    string ToString();
private:
    size_t capacity{0};
    char* data{nullptr};
    size_t size{0};

};

#endif // HUGEINT_H
