//TC: O(N^2)
//SC: O(N)
class Solution {
public:
    string getPermutation(int n, int k) {
        //Calculate (n-1)  factorial and add numbers to a vector
        vector<int> numbers;
        int fact = 1;
        for(int i = 1; i < n; i++){
            fact *= i;
            numbers.push_back(i);            
        }
        
        //Now insert the nth number to vevctor
        numbers.push_back(n);
        k = k-1; //0 based indexing considered
        string result;
        while(true){
            result = result + to_string(numbers[k/fact]);
            numbers.erase(numbers.begin() + k/fact);
            if(numbers.size() == 0){
                break;
            }
            k = k % fact; //update the next index
            fact = fact/numbers.size();
        }
        
        return result;        
    }
};
