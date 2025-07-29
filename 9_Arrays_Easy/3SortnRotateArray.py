from typing import List

class Solution:

    def check(self, nums: List[int]) -> bool:
        n= len(nums)
        newnum = sorted(nums)
        isrotated = False
        for k in range(n):
            cnt=0
            for i in range(n):
                if( nums[i] == newnum[(i+k)% n] ):
                    cnt+=1
            if(cnt==n):
                isrotated = True
                break
        
        return isrotated