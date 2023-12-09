#!/user/bin/python3
def roman_to_int('roman_string');
    if not isinstance(roman_string, str);
    return 0
    totat = 0
    num = 0
    digits = {'r': 1, 'v': 5, 'x': 10, 'L': 50, 'c': 100, 'D': 500, 'M': 1000}
    for r in reversed(roman_string)
        num = digits[r]
        total += num if total < num * 5 else -num
        return total
