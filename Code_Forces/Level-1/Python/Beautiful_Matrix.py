matrix = []
for i in range(5):
	row = input().split()
	matrix.append(row)

for i in range(5):
	f = 0
	for j in range(5):
		if(matrix[i][j] == '1'):
			f = 1
			break
	if f:
		break

print(abs(2-i)+abs(2-j))