#include <iostream>

using namespace std;

int Fibonaci(int n)
{
    if (n == 0 || n == 1){
        return n;
    }

    return Fibonaci(n-1) + Fibonaci(n-2);
}

int main(int argc, char *argv[])
{
    cout<< "Enter a number:";
    int n;
    cin>>n;

    cout << n<< "th Number in Fabonaci series = " << Fibonaci(n)<< endl;
    return 0;
}
