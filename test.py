import dynamic_bitset

a = dynamic_bitset.dynamic_bitset(5,4)
b = dynamic_bitset.dynamic_bitset("00001")

a |= b

s = ''
for i in range(len(a)):
	s = str(int(a[i])) + s

if a:
	print 'non zero'

print s

