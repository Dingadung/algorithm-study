'''
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
'''

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        arr = [[1]]

        
        for i in range(1, numRows) :
            brr = [1]
            for j in range(1, i) :
                brr.append(arr[i-1][j-1] + arr[i-1][j])

            brr.append(1)
            arr.append(brr)
        
        return arr
        
