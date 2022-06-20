#include <iostream>
#include <vector>

using namespace std;

//Find the median of 2 sorted array

//Input Array1 = 7 12 14 15
//Input Array2 = 1 2 3 4 9 11

//Merged Array = 1 2 3 4 7 9 11 12 14 15

//TC: O(n1+n2)
//SC: O(n1+n2)
vector<int> mergeSortedArray(vector<int>& nums1, vector<int>& nums2)
{
    int n1= nums1.size();
    int n2 = nums2.size();

    int i = 0, j = 0, k = 0;
    vector<int> mergedArray(n1+n2);

    while(i < n1 && j < n2)
    {
        if(nums1[i] < nums2[j])
            mergedArray[k++] = nums1[i++];
        else
            mergedArray[k++] = nums2[j++];
    }

    while(i < n1)
        mergedArray[k++] = nums1[i++];

    while(j < n2)
        mergedArray[k++] = nums1[j++];

    return mergedArray;
}

//TC: O(n1+n2)
//SC: O(n1+n2)
void mergeSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int i = nums1.size()-1;
    int j = nums2.size()-1;
    int k = nums1.size()+nums2.size()-1;

    nums1.resize(nums1.size()+nums2.size());

    while(j >= 0)
    {
        if(i >= 0 && nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }

}

int main()
{
    vector<int> arr1 = {7, 12, 14, 15};
    vector<int> arr2 = {1, 2, 3, 4, 9, 11};

    cout<<"Array1 = ";
    for(int val : arr1)
        cout<<val<< " ";
    cout<<endl;

    cout<<"Array2 = ";
    for(int val : arr2)
        cout<<val<< " ";
    cout<<endl;

    cout<<"Merged Array Approach1= ";
    vector<int> mergedArray = mergeSortedArray(arr1, arr2);
    for(auto val : mergedArray)
        cout<<val<<" ";

    cout<<endl;

    cout<<"Merged Array Approach2 = ";
    mergeSortedArrays(arr1, arr2);
    for(auto val : arr1)
        cout<<val<<" ";

    cout<<endl;

    return 0;
}
