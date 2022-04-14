#include <cs50.h>
#include <stdio.h>
#include <math.h>

/** 
 * Write a program that prompts the user for a credit card
 * number and then reports (via printf) 
 * whether it is a valid American Express, MasterCard, or Visa
 * card number, 
 * per the definitions of each’s format herein.
 * 
 * How to validate the card:
 * 
 * 1) Luhn’s algorithm (Checksum)
 *      a) Multiply every other digit by 2, starting with 
 *         the number’s second-to-last digit, and then add
 *         those products’ digits together.
 *      b) Add the sum to the sum of the digits that weren’t
 *         multiplied by 2.
 *      c) If the total’s last digit is 0 (or, put more
 *         formally, if the total modulo 10 is congruent to 
 *         0), the number is valid!
 * 
 * 2) Check card's length and starting digits:
 *      AMEX:  Starts with 34 or 37 and has 15 digits.
 *      MASTERCARD: Starts with 51, 52, 53, 54, or 55 and has 
 *                  16 digits;
 *      VISA: Starts with 4 and has 13 or 16 digits.
 * 
 * 3)Print witch card is or if is a invalid card.
 * 
 * 
 **/

int get_first_two(long first_2);
int get_checksum(long card_number);
int get_digit(int i, long card_number);
int get_lenght(long card_number);

int main(void)
{
    long card_number = get_long("Number: ");
    int first_2 = get_first_two(card_number);
    int checksum = get_checksum(card_number);
    int lenght = get_lenght(card_number);
    
    /* first_2 is 34 or 37 and has 15 digits and checksum % 10 == 0 */
    if ((first_2 == 34 || first_2 == 37) && (lenght == 15) && (checksum % 10 == 0))
    {
        printf("AMEX\n");
    }
    /* first_2 is 51, 52, 53, 54, or 55 and has 16 digits and checksum % 10 == 0 */
    else if ((first_2 >= 51 && first_2 <= 55) && (lenght == 16) && (checksum % 10 == 0))
    {
        printf("MASTERCARD\n");
    }
    /* first_2 is 4 and has 13 or 16 digits and checksum % 10 == 0*/
    else if ((first_2 / 10 == 4) && (lenght == 13 || lenght == 16) && (checksum % 10 == 0))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int get_first_two(long first_2)
{
    while (first_2 >= 100)
    {
        first_2 /= 10; 
    }
    
    return (int)first_2;
}

int get_lenght(long card_number)
{
    int lenght = 0;

    while (card_number > 1)
    {
        card_number /= 10;
        lenght++;
    }

    return lenght;
}

int get_checksum(long card_number)
{
    int checksum = 0;

    for (int i = 0; i < 16; i++)
    {
        
        if (i % 2 != 0) 
        {
            checksum += get_digit(i, card_number);  
        }
        else
        {
            checksum += card_number % 10;
        }

        card_number /= 10;
    }

    return checksum;
}

int get_digit(int i, long card_number) 
{
    int digit = (card_number % 10) * 2;

    if (digit >= 10)
    {
        digit = (digit % 10) + (digit / 10); 
    }

    return digit;  
}

