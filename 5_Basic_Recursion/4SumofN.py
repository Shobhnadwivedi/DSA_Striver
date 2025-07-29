class Solution:

    def sumOFSeries(self, n):
        if n==0:
            return 0
        
        return (n*n*n) + self.sumOFSeries(n-1)


sol = Solution()
print(sol.sumOFSeries(5) )