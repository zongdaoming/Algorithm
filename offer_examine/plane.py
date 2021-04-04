# import sys

# N = int(sys.stdin.readline().strip())

# point = [];

# for i in range(N):
#     point.append(list(map(int, sys.stdin.readline().strip().split())))

# point.sort(key=lambda k: k[1], reverse=True)

# res = []

# res.append(point[0])

# # 迭代
# for i in range(1,len(point)):
#     if point[i][0]>res[-1][0]:
#         res.append(point[i])
#     else:
#         continue

# res.sort(key=lambda k: k[0])

# for i in res:
#     print(i[0],i[1])




