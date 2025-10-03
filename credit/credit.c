#include <cs50.h>
#include <stdio.h>

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

int get_first_n_digits(long number, int n)
{
    long divisor = 1;
    for (int i = 0; i < get_length(number) - n; i++)
    {
        divisor *= 10;
    }
    return number / divisor;
}

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
            sum += digit / 10 + digit % 10;
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

bool is_amex(long number)
{
    return get_length(number) == 15 && (get_first_n_digits(number, 2) == 34 || get_first_n_digits(number, 2) == 37);
}

bool is_mastercard(long number)
{
    int first_two = get_first_n_digits(number, 2);
    return get_length(number) == 16 && (first_two >= 51 && first_two <= 55);
}

bool is_visa(long number)
{
    int length = get_length(number);
    int first = get_first_n_digits(number, 1);
    return (length == 13 || length == 16) && first == 4;
}

int main(void)
{
    long number = get_long("Number: ");

    if (!check_luhn(number))
    {
        printf("INVALID\n");
        return 0;
    }

    if (is_amex(number))
    {
        printf("AMEX\n");
    }
    else if (is_mastercard(number))
    {
        printf("MASTERCARD\n");
    }
    else if (is_visa(number))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
