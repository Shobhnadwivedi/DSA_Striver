from typing import List               #    The error "List" is not defined in Python means that Python does not recognize List as a valid type because it is not imported. This usually happens when using type hints with List in functions or class attributes without importing it from the typing module.
                                      #    List is part of the typing module in Python (before Python 3.9).

                                      #    You must import it before using it in type hints.


#    1.                               Two Sum   
''' 
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
'''

#   A. BRUTE FORCE METHOD = iterating through array  =  T.C = O(N^2)

class Solution1:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n=len(nums)
        for i in range(n):
            for j in range(i+1,n):
                if (nums[i]+nums[j]==target):
                    return [i,j]


nums=[20,7,11,2]
target = 9
sol1= Solution1()
print(sol1.twoSum(nums,target))

#       B. SAME AS BRUTE FORCE METHOD = iterating through array (but thoda alag approach)   =   T.C = O(N^2)
class Solution2:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n=len(nums)
        for i in range(n):
            m = target-nums[i]
            if ((m in nums) and( nums.index(m) != i)) :         # 1st  sirf   if (m in nums):   wali condition = to nums =[3,4,2] mein answer [0,0] aa raha tha instead of [1,2] for target = 6
                return [i,nums.index(m)]                        # 2nd   if ((m in nums) and (m != num[i])) :   wali condition =  nums=[3,3] was giving error. bcuz second wala 3 was equal to num , to instead of [0,1] output aa raha tha NULL

nums=[3,4,2]
target = 6
sol2= Solution2()
print(sol2.twoSum(nums,target))



#       C. ARRAY & HASH =   T.C = O(N) 
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        h_dict={}
        for i in range(n):                      
            complement = target-nums[i]
            if (complement in h_dict):
                return [i,h_dict[complement]]  # if compl. is in the hash dictionary already , then return the indices
            else:
                h_dict[nums[i]] = i        #  key(element of nums array) = value(uska index)   store this pair
