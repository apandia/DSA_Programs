#include <iostream>

using namespace std;

//TC = O(2^n)
void towerOfHanoi(int n, string from, string helper, string to)
{
    if(n == 0) return;

    towerOfHanoi(n-1, from, to, helper);

    cout<<from<<" -> "<<to<<endl;

    towerOfHanoi(n-1, helper, from, to);
}

int main(int argc, char *argv[])
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    towerOfHanoi(n, "A", "B", "C");

    return 0;
}
