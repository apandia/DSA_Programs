//Floyd's Cycle Detection Algorithm
//TC: O(n)
//SC: O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0];
        int slow = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];            
        }while(slow != fast);
        
        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};
