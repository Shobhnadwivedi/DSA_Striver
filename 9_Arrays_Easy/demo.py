from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n= len(nums)
        i=0
        j=1
        while(j< len(nums)):
            if(nums[j]==nums[i]):
                j+=1
            else:
                nums[i+1]=nums[j]
                i+=1
        return i+1

    

arr = [-1,0,0,1,1,2,3,3,3]
sol =Solution()
res = sol.removeDuplicates(arr)
print(res)