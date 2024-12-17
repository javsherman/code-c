#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check for the correct number of arguments
    if (argc != 3) {
        printf("Usage: %s <filename> <key>\n", argv[0]);
        return 1;
    }

    // Extract the filename and key from command-line arguments
    char *filename = argv[1];
    int key = atoi(argv[2]); // Convert the key from string to integer

    // Declare variables
    FILE *file;
    char word[100]; // Array to store each word (assuming max word length is 100)
    int i;          // Index to access characters in a word

    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    // Read words from the file and encrypt them
    while (fscanf(file, "%s", word) != EOF) {
        for (i = 0; word[i] != '\0'; i++) {
            char encrypted_char = word[i] + key; // Encrypt each character
            printf("%c", encrypted_char);       // Print encrypted character
        }
        printf(" \n"); // Separate encrypted words with a space
    }

    // Close the file
    fclose(file);

    return 0;
}
