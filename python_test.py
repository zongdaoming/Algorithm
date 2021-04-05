# _*_ coding: utf-8 _*_
# @author  :   naive dormin
# @time    :   2021/04/05 20:57:28

class Solution(object):
    def __init__(self):
        super(Solution, self).__init__()

    def printMatrix(self, matrix):
        outlist = [];
        while 1:
            outlist.extend(matrix[0])
            if len(matrix)>1:
                matrix = matrix[1::]
            else:
                break
        matrix = [[row[i] for row in matrix] for i in range(len(matrix[0])-1, -1,-1)]
        return outlist
        
matrix = [[1,2,3],
          [4,5,6],
          [7,8,9]]
matrix = [[row[i] for row in matrix] for i in range(len(matrix[0])-1, -1,-1)]
print(matrix)

for index in range(10,-1,-1):
    print(index)
# [] 前闭后开
# 10
# 9
# 8
# 7
# 6
# 5
# 4
# 3
# 2
# 1
# 0