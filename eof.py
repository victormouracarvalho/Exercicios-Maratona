
def hexadecimalToDecimal(hexval):
 
    # Finding length
    length = len(hexval)
 
    # Initialize base value to 1,
    # i.e. 16*0
    base = 1
    dec_val = 0
 
    # Extracting characters as digits
    # from last character
    for i in range(length - 1, -1, -1):
 
        # If character lies in '0'-'9',
        # converting it to integral 0-9
        # by subtracting 48 from ASCII value
        if hexval[i] >= '0' and hexval[i] <= '9':
            dec_val += (ord(hexval[i]) - 48) * base
 
            # Incrementing base by power
            base = base * 16
 
        # If character lies in 'A'-'F',converting
        # it to integral 10-15 by subtracting 55
        # from ASCII value
        elif hexval[i] >= 'A' and hexval[i] <= 'F':
            dec_val += (ord(hexval[i]) - 55) * base
 
            # Incrementing base by power
            base = base * 16
 
    return dec_val


if __name__ == '__main__': 
    while True:
        try:
            a = input()
            print(hexadecimalToDecimal(a))
        except EOFError:
            break
