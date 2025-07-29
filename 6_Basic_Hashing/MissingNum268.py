from typing import List

class Solution1:
    def missingNumber(self, nums: List[int]) -> int:
        n=len(nums)
        all_nums= set()
        for elem in nums:
            all_nums.add(elem)
        for i in range(n+1):
            if i not in all_nums:
                return i


nums = [3,0,1]           
sol = Solution1()
print(sol.missingNumber(nums))