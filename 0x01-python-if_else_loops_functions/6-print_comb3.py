#!/usr/bin/python3

for tens in range(10):
    for ones in range(tens + 1, 10):
        if tens < 9:
            print("{:d}{:d}, ".format(tens, ones), end="")
        else:
            print("{:d}{:d}".format(tens, ones))

print()

