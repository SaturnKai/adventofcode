#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

// Second half solution: 53348

#define MAX_DIGIT_LENGTH 2     // maximum digit size (always 2 in this case)
#define MAX_BUFFER_SIZE   255  // maximum line length
#define NUMBER_WORD_COUNT 9    // amount of number words

// constant for each wrod number
char* NUMBER_WORDS[NUMBER_WORD_COUNT] = {
    "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine"
};

// function for updating first and second digit
void set_digits(char* digit1, char* digit2, char digit) {

    // set the first digit if not set
    if (*digit1 == 0)
        *digit1 = digit;

    // always set the second digit
    *digit2 = digit;

}

// function for checking if texts starts with a word
bool starts_with(char* line, char* word, uint32_t index) {

    // while the pointer is still pointing to the word's content
    while (*word) {

        // check if the current word's character matches the text's
        // current character
        if (*word != line[index])
            return false;

        // increment word pointer and index
        word++;
        index++;
    }

    // starts with word
    return true;
}

// function for decoding a line
uint8_t decode_line(char* line) {

    // first and second digit
    char digit1 = 0, digit2 = 0;

    // loop through each char in line
    for (uint32_t i = 0; i < strlen(line); i++) {

        // get the ascii value for the char
        uint32_t ascii = line[i];

        // check if it's in range for a number
        if (ascii > 48 && ascii < 58)
            set_digits(&digit1, &digit2, line[i]);
        else { // otherwise try to decode word number

            // loop through each word in the list
            for (uint8_t wordIndex = 0; wordIndex < NUMBER_WORD_COUNT; wordIndex++) {

                // set digits if the line starts with the word
                bool result = starts_with(line, NUMBER_WORDS[wordIndex], i);
                if (result)
                    set_digits(&digit1, &digit2, (wordIndex + 1) + '0');

            }
            
        }
    
    }

    // concat both digits together by serializing them into the string
    char decoded[MAX_DIGIT_LENGTH];
    sprintf(decoded, "%c%c", digit1, digit2);

    // return back into a number
    return atoi(decoded);
}

int main(int argc, char** argv) {

    // open input file from command line argument
    FILE* infile = fopen(argv[1], "r");

    // define total and line buffer
    uint32_t total = 0;
    char line[MAX_BUFFER_SIZE];

    // loop through each line in file
    while (fgets(line, MAX_BUFFER_SIZE, infile)) {

        // decode line and add to total
        uint8_t count = decode_line(line);
        total += count;

    }

    // print total
    printf("Total: %d\n", total);

    // close input file and return success
    fclose(infile);
    return 0;
}