class Solution:
    def printName(self,n,cnt=0):
        if cnt==n:
            return
        print("Shobhna", end=' ')
        cnt +=1
        self.printName(n,cnt)

sol = Solution()
sol.printName(4)