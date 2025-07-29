from typing import List 

class Solution1:
    def moveZeroes(self, nums: List[int]) -> None:
        
        for k in range(len(nums)) :
            if(nums[k]==0):
                i=k
                break
        else:
            return   # it is very important
       
            
        j=i+1
        while(j< len(nums)):
            if(nums[j] != 0 ):
                #swap elem at i and j
                temp = nums[i]
                nums[i]= nums[j]
                nums[j]= temp

                i+=1
                
            else : j+=1
        


        




  
sol= Solution1()
nums = [1,3,12] 
sol.moveZeroes(nums)

print(nums)
        