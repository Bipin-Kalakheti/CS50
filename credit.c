#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int count = 0, digitstomultiply = 0, normalsum = 0, multiplieddigit = 0, multipliedsum = 0;
    long number, firstdigits, numberafterdividing;

    while (count < 5 || count > 16)
    {
        number = get_long("Number: ");
        firstdigits = number;
        count = 0;
        //do-while loop runs until all the digits in credit card number are counted in Counter variable
        do
        {
            numberafterdividing = number;
            number /= 10;
            count++;
            //conditional for separating,multiplying and adding every other digit
            //Digits are separated,mulitiplied and added for checksum or Luhn's Algorithm
            if (count % 2 == 0)
            {
                digitstomultiply = (numberafterdividing - (number * 10));
                multiplieddigit = digitstomultiply * 2;
                //conditional for checking, separating and adding if there are multiple digits after muliplication
                if (multiplieddigit > 9)
                {
                    multiplieddigit = multiplieddigit % 10 + multiplieddigit / 10;
                }
                multipliedsum = multipliedsum + multiplieddigit;
            }
            //conditional for adding every other digit that was multiplied
            else
            {
                normalsum = normalsum + (numberafterdividing - (number * 10));
            }
            //conditional for separating first 2 digits of credit card number
            if (count > 2)
            {
                firstdigits /= 10;
            }
        }
        while (number != 0);
    }
    //Conditional for Luhn's Algorithm that checks whether the card number is valid or not also known as Checksum.
    if ((normalsum + multipliedsum) % 10 == 0)
    {
        if (count == 15 && (firstdigits == 34 || firstdigits == 37))
        {
            printf("AMEX\n");
        }
        else if (count == 16 && (firstdigits > 50 && firstdigits < 56))
        {
            printf("MASTERCARD\n");
        }
        else if ((count == 13 || count == 16) && (firstdigits > 39 && firstdigits < 50))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}