#include <iostream>

using namespace std;

int Factorial(int n)
{
    if (n == 0){
        return 1;
    }

    return n * Factorial(n-1);
}

int main(int argc, char *argv[])
{
    cout<< "Enter a number:";
    int n;
    cin>>n;

    cout << "Factorial of " << n << " = "<<Factorial(n)<< endl;
    return 0;
}
