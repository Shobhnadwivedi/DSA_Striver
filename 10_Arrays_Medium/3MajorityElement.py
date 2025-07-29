from typing import List
#   BETTER SOLUTION 
class Solution:
    def majorityElement(self, nums: List[int] )-> int:
        h_dict={}

        for elem in nums:
            if(elem  in h_dict):
                h_dict[elem]+=1
            else:
                h_dict[elem]=1 
        
        return max(h_dict, key= h_dict.get)
    

sol = Solution()
arr = [2,2,1,1,8,0,0,1,2,2]
print(sol.majorityElement(arr))
