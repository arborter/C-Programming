#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Index for Alphabet
// we don't need an array of the alphabet because we are dealing with ASCII values which the computer alredy understands
// ALPHABET[] = {0, 1, 2, 3,... 25}

// Prototype function which will be run later
// The protoype takes the arg. in CLI

//string cipher_text(string argv[1]);

// Main function which takes input and prints cipher text

int main(int argc, string argv[])
{
    // there are 2 args necessary: 0 = argc, 1 = string argv[],
    if (argc != 2)
    {
        printf("./caesar + key \n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit((argv[1][i])))
        {
            printf("Usage: ./caesar + integer");
            return 1;
        }
    }
    // Key inputted as the second position of index
    // this is initially a string and must be converted to an int
    int k = atoi(argv[1]);
    string plaintext = get_string("Plain Text: ");
    printf("ciphertext: ");

    // Loop which sets condition based on key
    // This loop is for UPPERCASE
    for (int j = 0; j < strlen(plaintext); j++)
    {
        if (isupper(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 65 + k) % 26 + 65);
        }
        else if(islower(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 97 + k) % 26 + 97);
        }
        else
        {
            printf("%c", plaintext[j]);
        }
    }
    printf("\n");
}