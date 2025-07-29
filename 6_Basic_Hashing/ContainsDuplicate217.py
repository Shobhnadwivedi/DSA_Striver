from typing import List

#       LEETCODE = Easy           217.       CONTAINS DUPLICATE


#  A.    
class Solution1:
    def containsDuplicate(self, nums: List[int]) -> bool:
        h_dict={}

        for elem in nums:
            if elem in h_dict:
                h_dict[elem]+=1
            else:
                h_dict[elem]=1
        
        for values in h_dict.values():
            if values>=2:
                return True
        return False
    

#  B.  OPTIMIZED SOLUTION
class Solution2:
    def containsDuplicate(self, nums: List[int]) -> bool:
        seen = set()
        for elem in nums:
            if (elem in seen):
                return True
            else:
                seen.add(elem)
        return False
    

nums = [1,2,3,4]
sol=Solution2()
print(sol.containsDuplicate(nums))

# QUESTIONS TO THINK OVER
'''
why we used set here instead of an array/list. explain

explain the mechanism behind why Checking if num is in seen(a set) is O(1) (instead of O(N) in a list).

why we didn't use a dictionary instead of a set
'''