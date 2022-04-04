#include <iostream>
#include <vector>

using namespace std;

bool isSorted(int arr[], int n)
{
    if (n == 0 || n == 1){
        return true;
    }

    if((arr[0] < arr[1]) && isSorted(arr+1, n-1)){
        return true;
    }

    return false;
}

bool isSorted(vector<int>& arr, int index)
{
    if (index == arr.size() - 1){
        return true;
    }

    if((arr[index] < arr[index+1]) && isSorted(arr, index+1)){
        return true;
    }

    return false;
}

int main(int argc, char *argv[])
{
    int arr[] = {1,2,3,4,9,8,7};
    int size = sizeof(arr)/sizeof(int);

    if(isSorted(arr, size)){
        cout << "The array is sorted "<< endl;
    }else {
        cout << "The array is not sorted "<< endl;
    }

    vector<int> arr2 = {1,2,3,4,8};

    if(isSorted(arr2,0)){
        cout << "The vector is sorted "<< endl;
    }else {
        cout << "The vector is not sorted "<< endl;
    }


    return 0;
}
