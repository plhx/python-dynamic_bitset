import dynamic_bitset

a = dynamic_bitset.dynamic_bitset(5,0)
b = dynamic_bitset.dynamic_bitset(5,2)

a |= b
a.reset()

s = ''
for i in range(len(a)):
	s = str(int(a[i])) + s

if a:
	print 'non zero'

print s

