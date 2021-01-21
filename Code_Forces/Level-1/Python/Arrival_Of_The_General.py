n = int(input())
arr = list(map(int, input().split()))
minVal, maxVal = min(arr), max(arr)
found = 0
for i in range(n):
	if(arr[i] == minVal):
		pos_min = i
	if(arr[i] == maxVal and not found):
		pos_max = i
		found = 1
if(pos_max > pos_min):
	print(pos_max+(n-pos_min-1)-1)
else:
	print(pos_max+(n-pos_min-1))
