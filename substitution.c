#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>


int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int tl, kl;
        string key = argv[1];
        //strlen provides the length of function
        kl = strlen(key);
        char  z[kl];
        //checks whther there are 26 character in key or not
        if (kl != 26)
        {
            printf("Key should contain 26 characters.\n");
            return 1;
        }
        //This loop confirms that all the character in keys are alphabet and different from each other.
        for (int i = 0; i < kl; i++)
        {
            //Checks whether the character in key are alphabet or not
            if (isalpha(key[i]) == 0)
            {
                printf("Enter only alphabetical value\n");
                return 1;
            }
            key[i] = tolower(key[i]);
            z[i] = key[i];
            //checks duplication of character in key
            for (int k = i; k < 25; k++)
            {
                if (z[i] == tolower(key[k + 1]))
                {
                    printf("Enter One letter only once\n");
                    return 1;
                }
            }

        }
        //ask user for plain text input
        string text = get_string("plaintext: ");
        tl = strlen(text);
        int s[tl], d[tl];
        printf("ciphertext: ");
        //This loops converts plaintext into ciphertext.
        for (int i = 0; i < tl; i++)
        {
            //isalpha checks if the character in text[i] is alphabet or not
            if (isalpha(text[i]))
            {
                s[i] = (int) text[i];
                //isupper checks if the character in text[i] is capital or not
                if (isupper(text[i]))
                {
                    s[i] = s[i] - 65;
                    d[i] = toupper(z[s[i]]);
                }
                //if the character in text[i] is lower than below statements run
                else
                {
                    s[i] = s[i] - 97;
                    d[i] = z[s[i]];
                }
            }
            //if the character in text[i] is anything other than alphabet then it is saved as it is
            else
            {
                d[i] = text[i];
            }
            printf("%c", (char) d[i]);
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("./caeser key\n");
        return 1;
    }


}