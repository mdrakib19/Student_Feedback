#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int teacher_select();

void review_filecheck(FILE *fp)
{
    char str[1000], ch;
    int i = 0;

    if(!fp)
    {
        printf("Sorry!File opening failed\n");
        exit(1);
    }

    while(1)
    {
        ch = fgetc(fp);
        if(ch == EOF)
            break;
        str[i] = ch;
        i++;
    }

    str[i] = '\0';

    printf("%s\n", str);

    if(i == 0)
        printf("No review for showing.\n");
}

void display()
{
    FILE *fp;
    int selected_teacher;

    printf("\n\nDisplay review:");
    printf("\n---------------");

    selected_teacher = teacher_select();

    if(selected_teacher == 1)
    {
        printf("\nShowing review for (Mahabub Alom sir): \n");
        printf("--------------------------------------\n\n");
        fp = fopen("Data_File\\ReviewT1.txt", "r");
        review_filecheck(fp);
        fclose(fp);

    }

    else if(selected_teacher == 2)
    {
        printf("\nShowing review for (Milon Biswas sir): \n");
        printf("--------------------------------------\n\n");
        fp = fopen("Data_File\\ReviewT2.txt", "r");
        review_filecheck(fp);
        fclose(fp);
    }

    else if(selected_teacher == 3)
    {
        printf("\nShowing review for (Shamim Reza sir): \n");
        printf("-------------------------------------\n\n");
        fp = fopen("Data_File\\ReviewT3.txt", "r");
        review_filecheck(fp);
        fclose(fp);
    }

    else
        return ;
}
