from typing import List


class Solution:
    def removeduplicates(self, nums: List[int]) -> int:
        n=len(nums) 
        j=nums[0]     
        i=1
        while(i<len(nums)):
            if(nums[i]!=j):
                j= nums[i]
                i+=1   
            else:
                nums.pop(i)
        
        k = len(nums)
        for i in range(n-k):
            nums.append(0)
        return k
    
            
            
        
         
    
arr = [-1,0,0,1,1,2,3,3,3]
sol =Solution()
sol.removeduplicates(arr)
print(arr)



