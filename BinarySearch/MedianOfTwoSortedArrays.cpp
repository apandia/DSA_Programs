#include <iostream>
#include <vector>

using namespace std;

//Find the median of 2 sorted array

//Input Array1 = 7 12 14 15
//Input Array2 = 1 2 3 4 9 11
//TODO: Print the merged sorted array

//Output: Median of 2 array = 8

//TC: O(log MIN(n1,n2))     [logarithmic of either n1 or n2, whichever is small and we perform binary search on smaaler arry]
//SC: O(1)                  [no extra space used]

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    if(nums1.size() > nums2.size())
        findMedianSortedArrays(nums2, nums1);

    int n1 = nums1.size();
    int n2 = nums2.size();

    int low = 0;
    int high = n1;

    while(low <= high)
    {
        int divider1 = (low+high)/2;
        int divider2 = (n1+n2+1)/2 - divider1;

        int left1 = divider1 == 0 ? INT_MIN : nums1[divider1-1];
        int left2 = divider2 == 0 ? INT_MIN : nums2[divider2-1];

        int right1 = divider1 == n1 ? INT_MAX : nums1[divider1];
        int right2 = divider2 == n2 ? INT_MAX : nums2[divider2];

        if((left1 <= right2) && (left2 <= right1))
        {
            if((n1+n2)%2 == 0)
            {
                //Even number of element
                return (max(left1, left2) + min (right1, right2)) /2;
            }
            else
            {
                //Odd number of element
                return max(left1, left2);
            }
        }
        else if(left1 > right2)
        {
            high = divider1-1;
        }
        else
        {
            low = divider1+1;
        }
    }
    return 0.0;
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

    cout<<"Median of 2 array = "<<findMedianSortedArrays(arr1, arr2)<<endl;

    return 0;
}
