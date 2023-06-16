#include <assert.h>

void test_limit()
{
    assert(fibonacci(0)==1);
    assert(fibonacci(1)==2);
    assert(fibonacci(10)==13);
    assert(fibonacci(11)==13);
    assert(fibonacci(12)==13);
    assert(fibonacci(2)!=10);
}

void test_all()
{
    test_limit();
}