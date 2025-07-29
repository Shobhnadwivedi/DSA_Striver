#  Program to take input of an array .....then precalculate it in hash array...
# take input of queries and return the no. of times they appear in the array.

arr=[]
n = int(input('No. of elements in array : '))
for i in range(n):
    arr.append(int(input(f'Element no. {i+1}: ')))
print(arr)

# PRE defining
h_arr =[0]*(max(arr)+1)
print(h_arr)

for elem in arr:
    h_arr[int(elem)] += 1

print(h_arr)

# Fetching
query = []
q = int(input('No. of queries : '))
for i in range (q):
    query.append(int(input(f'Query no. {i+1} : ')))
    if query[i] not in arr:
        print(f'{query[i]} : 0 times')
    else:
        print(f'{query[i]} : {h_arr[query[i]]} times')


#     ARRAY LIMIT IN C++
'''

'''