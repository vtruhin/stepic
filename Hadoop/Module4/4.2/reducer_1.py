"""
Write reducer, which combines elements of the sets A and B.
At the entrance to the reducer come pairs key / value, where key - element of the set, value - sets the marker (A or B).
-------------------------------------------------------------------------------------------------------
Sample Input: 
1	A
2	A
2	B
3	B
-------------------------------------------------------------------------------------------------------
Sample Output: 
1
2
3
-------------------------------------------------------------------------------------------------------
"""
import sys

last_key = None

for line in sys.stdin:
    key, val = line.strip().split("\t")
    if last_key != key:
        print(key)
    last_key = key