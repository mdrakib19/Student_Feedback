#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char logged_in_name[20];
char logged_in_id[20];
int login_status;
int reg_status;

void user_login();
int teacher_select();
void logout();

void ratting_check(int n)
{
    FILE *ratt_fp;
    char ratt_name[20], temp;
    int ratt_num, ratt_sum = 0, len, count = 0;
    double avg_ratt = 0.00;

    if(n == 1)
    {
        printf("\nShowing ratting for (Mahabub Alom sir): \n");
        printf("--------------------------------------\n\n");

        ratt_fp = fopen("Data_File\\rattingT1.txt", "r");
    }

    else if(n == 2)
    {
        printf("\nShowing review for (Milon Biswas sir): \n");
        printf("--------------------------------------\n\n");

        ratt_fp = fopen("Data_File\\rattingT2.txt", "r");
    }

    else
    {
        printf("\nShowing review for (Shamim Reza sir): \n");
        printf("-------------------------------------\n\n");

        ratt_fp = fopen("Data_File\\rattingT3.txt", "r");
    }


    if(!ratt_fp)
    {
        perror("\n\nFile opening failed!");
        exit(1);
    }

    printf("\nGiven Name\t\tRatting(out of 10)");
    printf("\n-----------             ------------------");
    while(1)
    {
        fgets(ratt_name, 20, ratt_fp);
        fscanf(ratt_fp, "%d", &ratt_num);

        if(fscanf(ratt_fp, "%c", &temp) == EOF)
            break;


        ratt_name[strlen(ratt_name) - 1] = '\0';

        printf("\n%s", ratt_name);
        len = 20 - strlen(ratt_name);
        while(len--)
        {
            printf(" ");
        }
        printf("\t\t%d", ratt_num);
        ratt_sum += ratt_num;
        count++;
    }

    if(ratt_sum > 0)
        avg_ratt = (double)ratt_sum / (double)count;

    printf("\n\n>>> Average ratting(Out of 10): ");
    printf("%0.2lf <<<", avg_ratt);

    fclose(ratt_fp);
}

int check_ratted(int n)
{
    FILE *ratted_fp;
    char file_id[12], local_logged_id[20];
    int i = 0;

    while(logged_in_id[i] != '\n' && logged_in_id[i] != '\0')
    {
        local_logged_id[i] = logged_in_id[i];
        i++;
    }

    if(n == 1)
    {
        ratted_fp = fopen("Data_File\\ratted_idT1.txt", "r");
    }

    if(n == 2)
    {
        ratted_fp = fopen("Data_File\\ratted_idT2.txt", "r");
    }

    if(n == 3)
    {
        ratted_fp = fopen("Data_File\\ratted_idT3.txt", "r");
    }

    if(!ratted_fp)
    {
        perror("File opening_failed");
        exit(1);
    }

    while(fscanf(ratted_fp, "%s", file_id) != EOF)
    {
        //printf("\nLogged in id: %s\tFile id: %s\n", logged_in_id, file_id);
        if(!strcmp(local_logged_id, file_id))
        {
            printf("\n\nSorry!This ID already used for this teacher ratting");
            printf("\n---------------------------------------------------");
            fclose(ratted_fp);
            return 1;
        }
    }

    fclose(ratted_fp);
    return 0;
}

void input_ratting(int n)
{
    FILE *ratt_fp, *ratted_id_fp;
    int ratt_num;
    double temp_ratt_no;

    if(n == 1)
    {
        printf("\nInput ratting for (Mahabub Alom sir): \n");
        printf("--------------------------------------\n");

        ratt_fp = fopen("Data_File\\rattingT1.txt", "a+");
        ratted_id_fp = fopen("Data_File\\ratted_idT1.txt", "a+");
    }

    else if(n == 2)
    {
        printf("\nInput ratting for (Milon Biswas sir): \n");
        printf("--------------------------------------\n");

        ratt_fp = fopen("Data_File\\rattingT2.txt", "a+");
        ratted_id_fp = fopen("Data_File\\ratted_idT2.txt", "a+");
    }

    else
    {
        printf("\nInput ratting for (Shamim Reza sir): \n");
        printf("-------------------------------------");

        ratt_fp = fopen("Data_File\\rattingT3.txt", "a+");
        ratted_id_fp = fopen("Data_File\\ratted_idT3.txt", "a+");
    }


    if(!ratt_fp)
    {
        perror("\n\nFile opening failed!");
        exit(1);
    }

    if(!ratted_id_fp)
    {
        perror("\n\nFile opening failed!");
        exit(1);
    }

    if(check_ratted(n))
    {
        fclose(ratted_id_fp);
        fclose(ratt_fp);
        return ;
    }

    while(1)
    {
        printf("\n\nRatting(Only int 0 to 10): ");
        scanf("%lf", &temp_ratt_no);

        if(temp_ratt_no >= 0.00 && temp_ratt_no <= 10.00)
            break;
    }

    ratt_num = (int)temp_ratt_no;

    fprintf(ratt_fp, "%s", logged_in_name);
    fprintf(ratt_fp, "%d\n", ratt_num);
    fprintf(ratted_id_fp, "%s\n", logged_in_id);

    printf("\n\nRatting added Successfully");
    printf("\n---------------------------");

    fclose(ratt_fp);
    fclose(ratted_id_fp);
}

void ratting()
{
    int menu_input, tech_select;

    printf("\nRatting: ");
    printf("\n-------");

    while(1)
    {
        printf("\n\n1.Check ratting\n2.Input ratting\n0.Main menu\n\n>_");
        scanf("%d", &menu_input);

        if(menu_input == 0)
        {
            return ;
        }

        if(menu_input == 1)
        {
            printf("\n\nCheck ratting");
            printf("\n-------------");

            tech_select = teacher_select();

            if(tech_select)
            {
                ratting_check(tech_select);
            }

            else
            {
                return ;
            }
        }

        else if(menu_input == 2)
        {
            printf("\n\nInput ratting");
            printf("\n-------------");

            if(login_status == 0)
                user_login();

            else
            {
                printf("\n\nContinue as: %s", logged_in_name);
                logout();
            }

            if(login_status == 0 && reg_status == 0)
                return ;

            if(strlen(logged_in_name))
            {
                tech_select = teacher_select();

                if(tech_select)
                {
                    input_ratting(tech_select);
                }

                else
                {
                    return ;
                }
            }
        }

        else if(menu_input != 1 && menu_input != 2)
        {
            printf("\n\nWrong input!");
        }
    }
}
