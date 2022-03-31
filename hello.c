#include <stdio.h>
#include <cs50.h>
int main(void)
{
    //Ask for name
    string name = get_string("What is you name?\n");
    //display the name with hello
    printf("Hello, %s!\n", name);
}