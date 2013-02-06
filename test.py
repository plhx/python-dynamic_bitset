import dynamic_bitset

a = dynamic_bitset.dynamic_bitset(5,4)
b = dynamic_bitset.dynamic_bitset(5)

a |= b

a.resize(8,True)

print dynamic_bitset.npos
print a,b

