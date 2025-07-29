from typing import List               #    The error "List" is not defined in Python means that Python does not recognize List as a valid type because it is not imported. This usually happens when using type hints with List in functions or class attributes without importing it from the typing module.
                                      #    List is part of the typing module in Python (before Python 3.9).

                                      #    You must import it before using it in type hints.


#       LEETCODE             169.       Majority Element
'''
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that 
the majority element always exists in the array.
Example 1:
            Input: nums = [3,2,3]
            Output: 3
Example 2:
            Input: nums = [2,2,1,1,1,2,2]
            Output: 2
'''
#    A.   Hashing using Arrays (not dictionary)  =  Memory Limit Exceeded  on submitting this solution      =  for arrays/lists like nums =
#                                                                                                              [1000000000,1000000000,-1000000000,-1000000000,-1000000000]
class Solution1:
    def majorityElement(self, nums: List[int]) -> int:
        h_arr =[0]*(max(nums)+1)

        for elem in nums:                 #  updating frequency in h_arr 
            h_arr[int(elem)] += 1

        return h_arr.index(max(h_arr))     # jo maximum element h h_arr mein, uska index reutun karo



#   B.    hashing using dictionary
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        h_dict={}

        for elem in nums:
            if elem in h_dict:
                h_dict[elem]+=1
            else:
                h_dict[elem]=1
        
        return max(h_dict, key=h_dict.get)            

'''     The max() function finds the maximum element from the dictionary's keys.
        The key=freq_dict.get tells max() to compare the values instead of the keys.
        It effectively returns the key whose value is the highest.

        How It Works Internally
            max() iterates over all the keys: 'a', 'b', 'c', 'd'.
            It fetches the corresponding values using freq_dict.get(key):
            'a' → 10
            'b' → 25
            'c' → 5
            'd' → 30

The maximum value is 30, so the key 'd' is returned.

'''