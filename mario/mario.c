#include <cs50.h>
#include <stdio.h>

// for output of #
void print_hashes(int count)
{
    for (int i = 1; i <= count; i++)
    {
        printf("#");
    }
}

int main(void)
{
    int height;

    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= height - i; j++)
        {
            printf(" ");
        }
        print_hashes(i);
        printf("  ");
        print_hashes(i);

        printf("\n");
    }
}
