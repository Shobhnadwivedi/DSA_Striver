from typing import List


class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        listp = []
        listn = []
        temp=[]
        for i in range(len(nums)):
            if(nums[i]>=0):
                listp.append(nums[i])

            else:
                listn.append(nums[i])
        
        for i in range(len(nums)//2):
            temp.append(listp[i])
            temp.append(listn[i])

        return temp


class Solution2:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        pos=0
        neg=1
        i=0
        while(i<len(nums)):
            if(nums[i]<0):
                if(nums[neg]<0):
                    nums[i],nums[neg] = nums[neg],nums[i]

                    neg+=2
                else:
                    nums[i],nums[neg] = nums[neg],nums[i]

                    neg+=2
                    i+=2
            else:
                i+=2


    
    


sol= Solution()
nums= [-3,-2,4,5,-1,6]
sol.rearrangeArray(nums)
print(nums)