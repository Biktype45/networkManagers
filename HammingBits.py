CodeSize = int(input("Enter the number of Code bits : "))

code = list(input("Enter the code word : ").split())
code.reverse()
powers_2 = [ 2**i for i in range(10) ] 
red_bits = 0
for i in range(CodeSize):
	if 2**i >= CodeSize+i+1:
		red_bits = i
		break

r_bits = []

for i in range (red_bits):
	r_bits.append('0')

CodeWord = []

total_length = len(code) + len(r_bits)
j,k = 0,0
for i in range (total_length):
	if i+1 in powers_2:
		CodeWord.append(r_bits[j])
		j += 1
	else:
		CodeWord.append(code[k])
		k += 1


l = []
redundant_locations = []
k = 0
redundant_locations = []
for i in powers_2:
	if i > total_length:
		break
	k = i-1
	for j in range(i-1, total_length,i+i):
		l.append(CodeWord[k:k+i])
		k += i+i
	redundant_locations.append(list(l))
	l = []

CodeWord.reverse()
print(CodeWord)
r = []
for i in range(len(redundant_locations)):
	p = 0
	for j in redundant_locations[i]:
		for k in j:
			if int(k) == 1:
				p += 1
	if p%2 == 0:
		r.append('0')
	else:
		r.append('1')

print(r)



