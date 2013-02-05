import dynamic_bitset

a = dynamic_bitset.dynamic_bitset(5,4)
b = dynamic_bitset.dynamic_bitset("00001")

a |= b

a.swap(b)

print a,b

help(dynamic_bitset)

