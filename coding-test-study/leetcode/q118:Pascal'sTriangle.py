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
        
