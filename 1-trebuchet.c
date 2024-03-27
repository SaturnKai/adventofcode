#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

// Second half solution: 54644

#define MAX_BUFFER_LENGTH 256  // maximum line length
#define MAX_DIGIT_LENGTH 2     // maximum digit size (always 2 in this case)

// function for decoding a line
uint8_t decode_line(char* line) {

    // define two digits
    char digit1 = -1, digit2 = -1;

    // iterate through each character in line
    for (uint32_t i = 0; i < strlen(line); i++) {

        // check if the character is a valid digit
        char c = line[i];
        if (!isdigit(c))
            continue;

        // if the first digit isn't set, set it and the second one
        if (digit1 == -1) {
            digit1 = c;
            digit2 = c;
        }
        else
            digit2 = c; // otherwise, only set the second one

    }

    // define decoded string
    char decoded[MAX_DIGIT_LENGTH];

    // concat both digits together by serializing them into the string
    sprintf(decoded, "%c%c", digit1, digit2);

    // return the decoded string converted back into a number
    return atoi(decoded);
}

int main(int argc, char** argv) {

    // open input file from command line
    FILE* infile = fopen(argv[1], "r");

    // define total
    unsigned int total = 0;

    // read each line of file into buffer
    char buffer[MAX_BUFFER_LENGTH];
    while (fgets(buffer, MAX_BUFFER_LENGTH, infile)) {

        // decode line and add onto the total
        uint8_t result = decode_line(buffer);
        total += result;
    }

    // print total
    printf("Total: %d\n", total);

    // close file and return success
    fclose(infile);
    return 0;
}