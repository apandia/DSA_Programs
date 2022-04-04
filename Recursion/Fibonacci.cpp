#include <iostream>

using namespace std;

//In each level number of calls made = 1+2+4+8... (GP). So
//TC - O(2^N)
//SC - O(N)
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
