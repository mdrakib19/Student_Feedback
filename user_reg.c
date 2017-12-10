#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int reg_status;
int input_status = 0;

void reg_filecheck(FILE *fp)
{
    if(!fp)
    {
        printf("\nSorry!File opening failed.\n");
        exit(1);
    }
}

int input_check(char* input)
{
    int len;

    len = strlen(input);

    while(len--)
    {
        if(input[len] == ' ')
        {
            input_status = 1;
            return 1;
        }
    }

    return 0;
}

int user_reg()
{
    FILE *name_fp, *id_fp, *pass_fp;
    char name[20], pass[12], id[12], f_id[12], ch;
    int reg_inp_check;

    printf("\n\nUser registration: ");
    printf("\n\n---<<<User registration Form>>>---\n");
    printf("----------------------------------\n");

    printf("\nUser name (without space   03 to 20): ");
    gets(name);
    input_check(name);

    printf("University Id(without space 11 char): ");
    gets(id);
    input_check(id);

    printf("User Password(without space 6 to 11): ");
    gets(pass);
    input_check(pass);

    while((strlen(name) < 3 || strlen(name) > 20) || (strlen(pass) < 6 || strlen(pass) > 11) || (strlen(id) != 11) || (input_status == 1))
    {
        printf("\nRegistration failed!");
        input_status = 0;

        printf("\n\n1.Try again\n0.Main menu\n\n>_");

        scanf("%d", &reg_inp_check);

        while(1)
        {
            if(reg_inp_check == 0)
            return 0;

            if(reg_inp_check == 1)
            {
                printf("\n\n---<<<User registration Form>>>---\n");
                printf("----------------------------------\n");

                getchar();
                printf("\nUser name (without space   03 to 20): ");
                gets(name);
                input_check(name);

                printf("University Id(without space 3 to 20): ");
                gets(id);
                input_check(id);

                printf("User Password(without space 6 to 11): ");
                gets(pass);
                input_check(pass);
                break;
            }
            else
            {
                printf("\n\nWrong input!");
                printf("\n\n1.Try again\n0.Main menu\n\n>_");

                scanf("%d", &reg_inp_check);
            }
        }
    }

    name_fp = fopen("Data_File//user_name.txt", "a+");
    reg_filecheck(name_fp);

    id_fp = fopen("Data_File//user_id.txt", "a+");
    reg_filecheck(id_fp);

    pass_fp = fopen("Data_File//user_pass.txt", "a+");
    reg_filecheck(pass_fp);

    while(1)
    {
        fgets(f_id, 12, id_fp);
        ch = fgetc(id_fp);

        if(!strcmp(f_id, id))
        {
            printf("\n\nSorry!This Id already registered please login.");
            return 1;
        }

        else if(f_id != id && ch == EOF)
        {
            fputs(name, name_fp);
            fputs(id, id_fp);
            fputs(pass, pass_fp);

            fputc('\n', name_fp);
            fputc('\n', id_fp);
            fputc('\n', pass_fp);

            printf("\n\nThank you!Registration successful.");
            printf("\n----------------------------------");

            fclose(name_fp);
            fclose(id_fp);
            fclose(pass_fp);
            return 1;
        }
    }
}
