#include <iostream>
#include "/Users/raoul/C++ Projects/Lab1/includes/cel_mai_mic_fibonacci.h"
#include "/Users/raoul/C++ Projects/Lab1/tests/tests_cel_mai_mic_fibonacci.h"
using namespace std;

int main()
{
    test_all();
    int n=0,m=0;
    cout<<"n=";
    cin>>n;
    m=fibonacci(n);
    cout<<m;
}