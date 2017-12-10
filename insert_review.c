#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char logged_in_name[20];

int teacher_select();

void insert_filecheck(FILE *fp)
{
    char str[100], local_name[20];
    int i = 0;

    if(!fp)
    {
        printf("Sorry!File opening failed.\n");
        exit(1);
    }

    while(logged_in_name[i] != '\n' && logged_in_name[i] != '\0')
    {
        local_name[i] = logged_in_name[i];
        i++;
    }

    local_name[i] = '\0';

    printf("\tType your review(between 50 cherecter): ");
    fflush(stdin);
    gets(str);
    fprintf(fp, "%s: %s", local_name, str);
    fprintf(fp, "%c", '\n');

}

void insert_review(char *name)
{
    FILE *fp;
    int selected_teacher = teacher_select();

    if(selected_teacher == 1)
    {
        printf("\nReview inserting for(Mahabub Alom Sir) \n");
        fp = fopen("Data_File\\ReviewT1.txt", "a");
        insert_filecheck(fp);
        fclose(fp);
        printf("\nThank you!Review inserted successfully.\n");
    }
    if(selected_teacher == 2)
    {
        printf("\nReview inserting for(Milon Biswas sir) \n");
        fp = fopen("Data_File\\ReviewT2.txt", "a");
        insert_filecheck(fp);
        fclose(fp);
        printf("\nThank you!Review inserted successfully.\n");
    }
    if(selected_teacher == 3)
    {
        printf("\nReview inserting for(Shamim Reza sir) \n");
        fp = fopen("Data_File\\ReviewT3.txt", "a");
        insert_filecheck(fp);
        fclose(fp);
        printf("\nThank you!Review inserted successfully.\n");
    }
}
