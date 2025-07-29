class Solution:
    def printNos(self,N):
        if N==0:
            return
        print(N, end=' ')
        N-=1
        self.printNos(N)


sol =Solution()
sol.printNos(5)

