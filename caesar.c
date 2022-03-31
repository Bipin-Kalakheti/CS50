#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int tl, j = 0, k, m;
    //saves the second argument passed in b
    string b = argv[1];
    //Ensures the amount of command line arguments passed is only 2.
    if (argc == 2)
    {

        for (int i = 0; i < strlen(argv[1]); i++)
        {
            //Runs the statement inside conditions if anything except for digit is passed as 2nd argument.
            if (isdigit(b[i]) == 0)
            {
                printf("./caeser key\n");
                return 1;
            }
        }
        //after ensuring the argument is digit, then it is saved in k variable as a integar
        k = atoi(b);
        string text = get_string("plaintext: ");
        //strlen provides the length of function
        tl = strlen(text);
        int s[tl], d[tl];
        for (int i = 0; i < tl; i++)
        {
            //isalpha checks if the character in text[i] is alphabet or not
            if (isalpha(text[i]))
            {
                s[j] = (int) text[i];
                //isupper checks if the character in text[i] is capital or not
                if (isupper(text[i]))
                {
                    s[j] = s[j] - 65;
                    d[j] = ((s[j] + k) % 26) + 65;
                }
                //if the character in text[i] is lower than below statements run
                else
                {
                    s[j] = s[j] - 97;
                    d[j] = ((s[j] + k) % 26) + 97;
                }
            }
            //if the character in text[i] is anything other than alphabet then it is saved as it is
            else
            {
                d[j] = text[i];
            }
            j++;
        }
        printf("ciphertext: ");
        //prints the ciphered character saved in d[i]
        for (int i = 0; i < tl; i++)
        {
            printf("%c", (char) d[i]);
        }
        printf("\n");
        return 0;
    }
    //if more than 2 arguments are passed in command then below statements run
    else
    {
        printf("./caeser key\n");
        return 1;
    }
}