class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        //LL solution
        int s = nums[0];
        int f = nums[0];
        do{
            s = nums[s];
            f = nums[nums[f]];
        } while(s!=f);
            
        f = nums[0];
        while(s!=f){
            f = nums[f];
            s = nums[s];
        }
        return s;
        
    }
};