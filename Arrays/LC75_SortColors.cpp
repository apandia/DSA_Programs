#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*Dutch National Flag Algorithm (Three-way partitioning)

1. If A[mid] == 0, swap A[mid] and A[low] and increment low and mid pointers by 1.
2. If A[mid] == 1, increment the mid pointer by 1.
3. If A[mid] == 2, swap A[high] and A[mid] and increment mid by 1 and decrement high by 1.
                   But for below problem, we dont need to increment mid by 1
*/
//IMP Point - sort the array in one pass

//TC: O(N)
//SC: O(1)

class Solution {
    public:

    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size()-1;

        while(mid <= high){
            switch(nums[mid]){
            case 0:
                swap(nums[low++], nums[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(nums[mid], nums[high--]);
                break;
            }
        }
    }
};

int main()
{
    Solution obj;

    //vector<int> input{2,0,2,1,1,0};
    vector<int> input{1,2,0}; //Test case will fail if we have mid++ for case 2


    obj.sortColors(input);

    for (auto num: input){
        cout<<num<<" ";
    }
    cout<<endl;
}
