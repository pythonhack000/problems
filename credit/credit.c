#include <cs50.h>
#include <stdio.h>

bool check_luhn(long number)
{
    int sum = 0;
    bool alternate = false;

    while (number > 0)
    {
        int digit = number % 10;

        if (alternate)
        {
            digit *= 2;
            sum += (digit / 10) + (digit % 10);
        }
        else
        {
            sum += digit;
        }

        alternate = !alternate;
        number /= 10;
    }

    return (sum % 10 == 0);
}

int get_length(long number)
{
    int length = 0;
    while (number > 0)
    {
        length++;
        number /= 10;
    }
    return length;
}

int get_first_two_digits(long number)
{
    while (number >= 100)
    {
        number /= 10;
    }
    return number;
}

int main(void)
{
    long number = get_long("Number: ");

    if (!check_luhn(number))
    {
        printf("INVALID\n");
        return 0;
    }

    int length = get_length(number);
    int first_two = get_first_two_digits(number);

    if (length == 15 && (first_two == 34 || first_two == 37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && (first_two >= 51 && first_two <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && (first_two / 10 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
