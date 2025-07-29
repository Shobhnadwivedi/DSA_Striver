#              ASCII CODE - 
'''
0      =  NULL
32     =  Space
48-57  =  0-9
65-90  =  A-Z
97-122 =  a-z
'''
#   We use ord(char) - ord('a') to convert 'a' to 0, 'b' to 1, … 'z' to 25.




s = input('String : ')
print(s)
# Pre computing
h_arr= [0]*127
for char in s:
    h_arr[ord(char)] +=1
print(h_arr)

# Fetching
query=[]
q = int(input('Total no. of queries : '))
for i in range(q):
    i= int(input(f'Element no. {i+1} : '))
    query.append(i)
    print(h_arr[ord(i)])

