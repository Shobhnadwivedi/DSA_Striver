from typing import List

class Solution:

    def check(self, nums: List[int]) -> bool:
        n= len(nums)
        newnum = sorted(nums)   # makes a copy of nums which is sorted and doesn't affects the original list
                                #  newnum = nums
                                #  newnum.sort()         =  these two lines affects the original list bcuz newnum is just another name for nums
        final_cnt= 0
        for k in range(n):
            cnt=0
            for i in range(n):
                if( nums[i] == newnum[(i+k)% n] ):
                    cnt+=1
            if(cnt==len(nums)):
                final_cnt+=1
        if(final_cnt>0):
            return True
        else: 
            return False
        
    
nums = [2,1,3,4]
sol = Solution()

print(sol.check(nums))