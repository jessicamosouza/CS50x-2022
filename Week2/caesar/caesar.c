#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int get_key(int argc, string argv);
string get_plaintext(void);
string get_cipher(string plaintext, int key);

int main(int argc, string argv[])
{
    int key = get_key(argc, argv[1]);
    if (key == false)
    {
        return 1;
    }

    string plaintext = get_plaintext();

    string ciphertext = get_cipher(plaintext, key);

    // Print the Ciphertext
    printf("%s\n", ciphertext);
}

int get_key(int count, string k)
{
    // Make sure program was run with just one command-line argument
    if (count != 2)
    {
        printf("Usage: ./caesar key\n");
        return false;
    }
    else
    {
        // Make sure every character in argv[1] is a digit
        for (int i = 0; i < strlen(k); i++)
        {
            if (isalpha(k[i]))
            {
                printf("Usage: ./caesar key\n");
                return false;
            }
        }

        // Convert argv[1] from a `string` to an `int`
        return atoi(k);
    }
}

string get_plaintext(void)
{
    // Prompt user for plaintext
    string plaintext = get_string("plaintext:  ");

    return plaintext;
}

string get_cipher(string plaintext, int key)
{
    // For each character in the plaintext:
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        // Rotate the character if it's a letter
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                plaintext[i] = ((plaintext[i] - 'A') + key) % 26;
                plaintext[i] = plaintext[i] + 'A';
            }
            else
            {
                plaintext[i] = ((plaintext[i] - 'a') + key) % 26;
                plaintext[i] = plaintext[i] + 'a';
            }
        }
    }

    return plaintext;
}