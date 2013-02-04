import dynamic_bitset

def B(x):
	s = ''
	for i in range(len(x)):
		s = str(int(x[i])) + s
	return s
	

a = dynamic_bitset.dynamic_bitset(5,4)
b = dynamic_bitset.dynamic_bitset("00001")

a |= b

a.swap(b)

print B(a)
print B(b)

