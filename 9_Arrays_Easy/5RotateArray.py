from typing import List

'''
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
'''
# BRUTE FORCE =      T.C = O(2n)
#                    S.C = O(n)
class Solution1:
    def rotate( self, nums: List[int], k: int)-> None:
        n =len(nums)
        temp=[None]*n
        
        for i in range(n):
            temp[(i+k)%n] = nums[i]

        for i in range(n):
            nums[i] = temp[i]

# BETTER SOL     =     T.C = O()
#                =     S.C = O( K )   K = no. of steps to shift     = check in striver notes for left and right


# OPTIMAL SOL =     T.C = O()
#                   S.C = O(1)
class Solution3:

    def reverse(self, nums: List[int], start: int , end: int)-> None :
        # left pointer = start   &      right pointer = end-1
        l=start
        r= end-1
        while(l<=r):
            # swap l and r waley number
            temp = nums[l]
            nums[l]= nums[r]
            nums[r]= temp

            l+=1
            r-=1
    


    def rotate( self, nums: List[int], k: int)-> None:
        n=len(nums)
        # for left
        self.reverse(nums, 0, k)             # for right  = (nums, 0, n-k)  
        self.reverse(nums,k, n)              #              (nums, n-k , n) 

        self.reverse(nums , 0,n)


        
        

nums=[1,2,3,4,5,6,7]

sol= Solution3()
sol.rotate(nums,3)
print(nums)