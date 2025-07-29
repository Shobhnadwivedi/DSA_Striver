from typing import List


#  Time Limit Exceeded
class Solution1:
    def findUnion(self,a,b):
        temp=[]
        for i in range(len(a)):
            if(a[i] not in temp):
                temp.append(a[i])

        for i in range(len(b)):
            if(b[i] not in temp):
                temp.append(b[i])
        temp.sort()
        return temp
    

    

a=[-8,8]
b=[-8,-7,8]
sol= Solution1()
res=sol.findUnion(a,b)
print(res)