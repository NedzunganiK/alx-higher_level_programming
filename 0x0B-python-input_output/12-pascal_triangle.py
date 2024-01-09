#!/usr/bin/python3
"""Defines a Pascal's Triangle function."""

def generate_pascals_triangle(n):
    """Generate Pascal's Triangle of size n.

    Returns a list of lists of integers representing the triangle.
    """
    if n <= 0:
        return []

    triangle = [[1]]
    while len(triangle) < n:
        row = [1]
        for i in range(len(triangle[-1]) - 1):
            row.append(triangle[-1][i] + triangle[-1][i + 1])
        row.append(1)
        triangle.append(row)

    return triangle


