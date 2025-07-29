class Solution:
    # Function to count the frequency of all elements from 1 to N in the array.
    def frequencyCount(self, arr):
        n= len(arr)
        h_arr=[0]*n                    
        for i in range(n):
            h_arr[arr[i]-1]=  h_arr[arr[i]-1] + 1
        return h_arr
            
#  when using  :   h_arr=(0)*n   instead of square brackets - Typeerror = 'int' object is not subscriptable.
'''
This error in Python occurs when you try to use indexing ([]) on an integer, which is not allowed because 
integers are not iterable.In Python, subscriptable objects are those that support indexing using square brackets ([]). Examples of subscriptable objects include:

Lists (list): my_list[0]

Strings (str): my_str[0]

Dictionaries (dict): my_dict["key"]

Tuples (tuple): my_tuple[0]
'''