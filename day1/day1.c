#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 13
#define BUFFER_SIZE 150000

int main(int argc, char const *argv[])
{
    FILE *file;

    file = fopen("inputDay1.txt", "r");
    if (file == NULL)    {
        printf("Could not open file!");
        return 1;
    }

    //allocate memory for more than enough chars
    // 13*10000 = 130,000 + \n = 140,000 + padding = 150,000
    char* buffer = malloc(150000 * sizeof(char));
    if (buffer == NULL)    {
        printf("Not enough memory!\n");
        return 2;
    }

    //Initialize to 0 sans null terminator
    for (int i; i < sizeof(buffer - 2); i++)    {
        buffer[i] = '0';
        //Condition when the element before last is reached to add the
        //null terminator to the next element, which is the last
        if(buffer[i] == sizeof(buffer - 2)) {
            buffer[i+1] = '\n';
        }
    }
    
    //Load in all the characters from txt file
    char ch;
    int counter = 0;

    while ((ch  = fgetc(file)) != EOF)  {
        if (counter < BUFFER_SIZE - 1) {
            buffer[counter++] = ch;
        }
    }
    buffer[counter] ='\n'; //Null-terminate the array

    //Print it all out in rows as has been formatted
    int bar = 0;
    int line = 0;
    while (bar < BUFFER_SIZE)
    {
        if(line == 13)  {
            printf("\n");
            line = 0;
        }
        else{
            printf("%c", buffer[bar]);
            bar++;
        }
    }

    //close input stream file
    fclose(file);
    
    return 0;
}
