#include <iostream>

using namespace std;

//In each level number of calls made = 1+2+4+8... (GP).
//Firt call for (n-1) and (n-2) will be made say we call them as l1(n-1) and l2(n-2)
//In next level again opeation with -1 and -2 will be made for l1 and l2 it means (n-1-1 and n-1-2) for l1 and (n-2-1) and (n-2-2) for l2 making 4 callls.
/*
                f(5)                    1   (2^0)
              /      \
            f(4)     f(3)               2   (2^1)
           /   \    /   \
         f(3) f(2) f(2) f(1)            4   (2^2)   etc....                      
*/

//TC - O(2^N)
//SC - O(N)
int Fibonaci(int n)
{
    if (n == 0 || n == 1){
        return n;
    }

    return Fibonaci(n-1) + Fibonaci(n-2);
}

//TODO: Fabonacci Iteratiove approach will have TC: O(N)

int main(int argc, char *argv[])
{
    cout<< "Enter a number:";
    int n;
    cin>>n;

    cout << n<< "th Number in Fabonaci series = " << Fibonaci(n)<< endl;
    return 0;
}
