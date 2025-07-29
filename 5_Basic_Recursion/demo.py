


def factorialNumbers( n):
        v1=[]
        cnt = 1
        sum=1
        while(cnt<=n):
            sum*= cnt
            cnt+=1
            if(sum<n): 
                v1.append(sum)
        
        return v1
            


print(factorialNumbers(220))

class Solution:
    def fib(self, n: int) -> int:
        if(n==0):
            return 0
        if(n==1):
            return 1
        return self.fib(n-1) + self.fib(n-2)
    
resss= Solution()
print(resss.fib(7))
         