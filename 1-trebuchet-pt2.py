import sys  # used to gather command line arguments

# Second half solution: 53348

# define a constant of number words
# their index in the list will be their value
NUMBER_WORDS = [
    'one', 'two', 'three', 'four', 'five',
    'six', 'seven', 'eight', 'nine'
]

def decode_line(line: str) -> int:

    # list to store digits
    digits = []

    # character index
    i = 0

    # loop through each character in line
    for c in line:

        # decode if digit
        if c.isdigit():
            digits.append(c)

        # attempt to decode number word
        else:

            # iterate through each number word
            wordIndex = 1
            for word in NUMBER_WORDS:

                # append number word as digit if current line index
                # starts with number word
                if line[i:].startswith(word):
                    digits.append(wordIndex)
                wordIndex += 1

        # increment character index
        i += 1

    # serialize the first and last digit together
    serialized = f'{digits[0]}{digits[len(digits) - 1]}'

    # return as a converted number
    return int(serialized)

# main entrypoint
def main():

    # open input file from command line argument
    infile = open(sys.argv[1], 'r')

    # read and decode each line, add to total
    total = 0
    for line in infile.readlines():
        decoded = decode_line(line)
        total += decoded

    # print total and close input file
    print(f'Total: {total}')
    infile.close()

# run if python script is directly executed
if __name__ == '__main__':
    main()