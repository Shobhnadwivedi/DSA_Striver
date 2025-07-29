from typing import List

class Solution1:

    def factorialTrueSolution(self, n):
        fac = 1  # initialize the factorial to 1
        x = 2  # initialize x to 2
        ans = []  # create an empty list to store the factorial numbers
        while fac <= n:  # iterate until the factorial is less than or equal to N
            ans.append(fac)  # add the factorial to the list
            fac *= x  # calculate the next factorial by multiplying it with x
            x += 1  # increase the value of x by 1 for the next iteration
        return ans  # return the list of factorial numbers
    


class Solution2:
    fac = 1
    k=2
    def factorialOPTIMALSolution(self, n,v1=[]):
        if(self.fac>n):
            return v1
        
        v1.append(self.fac)
        self.fac *= self.k 
        self.k+=1
        
        return self.factorialOPTIMALSolution(n, v1)

        

'''
When you define v1=[] in the function signature, Python creates that list once and reuses it across function calls.

So if you call the function multiple times (e.g., for different n), old results remain in v1.

🔁 Example:

s = Solution()
s.factorialNumbers(2)  # Output: [1, 2]
s.factorialNumbers(2)  # Output: [1, 1, 2]
'''    
        
        
        
res= Solution2()
print(res.factorialOPTIMALSolution(2))