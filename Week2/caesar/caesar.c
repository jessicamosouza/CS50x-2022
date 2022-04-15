#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool check_key(int argc, string argv);
string get_cipher(string plaintext, int key);
char char_cypher(char a, int key, char letter);

int main(int argc, string argv[])
{
    bool key_check = check_key(argc, argv[1]);
    if (key_check == false)
    {
        return 1;
    }

    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    string plaintext = get_string("plaintext:  ");

    string ciphertext = get_cipher(plaintext, key);

    // Print the Ciphertext
    printf("%s\n", ciphertext);
}

bool check_key(int count, string k)
{
    // Make sure program was run with just one command-line argument
    if (count != 2)
    {
        printf("Usage: ./caesar key\n");
        return false;
    }

    // Make sure every character in argv[1] is a digit
    for (int i = 0; i < strlen(k); i++)
    {
        if (isalpha(k[i]))
        {
            printf("Usage: ./caesar key\n");
            return false;
        }
    }
    return true;
}

string get_cipher(string plaintext, int key)
{
    // For each character in the plaintext:
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        // Rotate the character if it's a letter
        if (!isalpha(plaintext[i]))
        {
            continue;
        }

        if (isupper(plaintext[i]))
        {
            plaintext[i] = char_cypher('A', key, plaintext[i]);
        }
        else
        {
            plaintext[i] = char_cypher('a', key, plaintext[i]);
        }
    }

    return plaintext;
}

char char_cypher(char a, int key, char letter)
{
    letter = ((letter - a) + key) % 26;
    letter = letter + a;

    return letter;
}
