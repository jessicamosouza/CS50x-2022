#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>

bool check_key(int count, string k);
string get_cipher(string plaintext, string key);
char char_cypher(char a, string key, char letter);

int main(int argc, string argv[])
{
    bool key_check = check_key(argc, argv[1]);
    if (key_check == false)
    {
        return 1;
    }

    string key = argv[1];

    string plaintext = get_string("plaintext: ");

    string ciphertext = get_cipher(plaintext, argv[1]);

    // Print the Ciphertext
    printf("%s\n", ciphertext);
}

bool check_key(int count, string k)
{
    // Make sure program was run with just one command-line argument
    if (count != 2)
    {
        printf("Usage: ./substitution key\n");
        return false;
    }

    // Key must contain 26 characters
    if (strlen(k) < 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    for (int i = 0; i < strlen(k); i++)
    {
        if (!isalpha(k[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return false;
        }

        for (int j = i + 1; j < strlen(k); j++)
        {
            if (k[i] == k[j] || tolower(k[i]) == k[j] || toupper(k[i]) == k[j])
            {
                printf("Key must not contain repeated characters.\n");
                return false;
            }
        }
    }

    return true;
}

string get_cipher(string plaintext, string key)
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
            plaintext[i] = toupper(char_cypher('A', key, plaintext[i]));
        }
        else
        {
            plaintext[i] = tolower(char_cypher('a', key, plaintext[i]));
        }
    }

    return plaintext;
}

char char_cypher(char a, string key, char letter)
{
    letter = key[letter - a];
    return letter;
}