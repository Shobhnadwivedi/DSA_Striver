from typing import List


#  
'''
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
Example 1:
        Input: nums = [1,2,3,1], k = 3
        Output: true
Example 2:
        Input: nums = [1,2,3,1,2,3], k = 2
        Output: false
'''


class Solution2:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        h_dict={}
        for elem in nums:
        
            if elem in h_dict and (abs(h_dict[elem] - nums.index(elem)) <= k) :
                return True
            
            h_dict[elem]=nums.index(elem)

        return False
    
    
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        h_dict={}
        for i, elem in enumerate(nums):                                                   #   Using enumerate() ensures we track the actual index i instead of using nums.index(elem).

      
            if elem in h_dict and (abs(h_dict[elem] - nums.index(elem)) <= k) :            # check these two conditions
                return True
            h_dict[elem]=1                       # storing the key:value pair
        return False
    
nums= [1,2,3,1,2,3]
k=2
sol= Solution()
res =sol.containsNearbyDuplicate(nums,k)
print(res)