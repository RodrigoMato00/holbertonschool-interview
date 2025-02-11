#!/usr/bin/python3
"""
Given a number n, write a method that calculates
the fewest number of operations needed
to result in exactly n H characters in the file

Example
n = 9
H => Copy All => Paste => HH => Paste =>HHH => Copy All =>
Paste => HHHHHH => Paste => HHHHHHHHH
Number of operations: 6
"""


def minOperations(n):
    """
    Minimum Operation
    """

    if n <= 1:
        return 0

    number = n
    div = 2
    nop = 0

    while number > 1:

        if number % div == 0:
            number = number/div
            nop = nop + div

        else:
            div += 1

    return nop
