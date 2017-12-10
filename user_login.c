#include <stdio.h>
#include <string.h>

char user_name[20];
char logged_in_name[20];
char logged_in_id[20];
int login_status;
int reg_status;

void reg_filecheck(FILE *fp);
int user_reg();

void user_login()
{
    FILE *name_fp, *id_fp, *pass_fp;
    char name[20], f_name[20], id[15], f_id[15], pass[15], f_pass[15];
    int name_length, id_length, pass_length, try_again, name_len;

    printf("\n\n---<<<User Login Form>>>---\n");
    printf("----------------------------\n");

    name_fp = fopen("Data_File\\user_name.txt", "r");
    reg_filecheck(name_fp);
    id_fp = fopen("Data_File\\user_id.txt", "r");
    reg_filecheck(id_fp);
    pass_fp = fopen("Data_File\\user_pass.txt", "r");
    reg_filecheck(pass_fp);

    fflush(stdin);
    printf("\nUser     name: ");
    gets(name);
    name_length = strlen(name);
    name[name_length] = '\n';
    name[name_length + 1] = '\0';
    printf("University id: ");
    gets(id);
    id_length = strlen(id);
    id[id_length] = '\n';
    id[id_length + 1] = '\0';
    printf("user password: ");
    gets(pass);
    pass_length = strlen(pass);
    pass[pass_length] = '\n';
    pass[pass_length + 1] = '\0';

    while(1)
    {
        fgets(f_name, 20, name_fp);
        fgets(f_id, 15, id_fp);
        fgets(f_pass, 15, pass_fp);

        if((strcmp(name, f_name) == 0) && (strcmp(id, f_id) == 0) && (strcmp(pass, f_pass) == 0))
        {
            printf("\n\nLogin Successful: %s", name);
            printf("-----------------");
            name_len = strlen(name);
            while(name_len--)
            {
                printf("-");
            }
            strcpy(logged_in_name, name);
            strcpy(logged_in_id, id);
            //printf("\nLogged in id in login: %s\n", logged_in_id);
            login_status = 1;
            break;
        }

        else if(feof(id_fp))
        {
            printf("\n\nInvalid User login. \n");

            printf("\n\n1.Login\n2.Register\n0.Main menu\n\n>_");

            scanf("%d", &try_again);

            while(try_again != 0 && try_again != 1 && try_again != 2)
            {
                printf("\n\nWrong input! Try again.\n\n\t\t_");
                scanf("%d", &try_again);
            }

            if(try_again == 1)
            {
                printf("\n\n---<<<User Login Form>>>---\n");
                printf("----------------------------\n");
                getchar();
                printf("\nUser     name: ");
                gets(name);
                name_length = strlen(name);
                name[name_length] = '\n';
                name[name_length + 1] = '\0';
                printf("University id: ");
                gets(id);
                id_length = strlen(id);
                id[id_length] = '\n';
                id[id_length + 1] = '\0';
                printf("user password: ");
                gets(pass);
                pass_length = strlen(pass);
                pass[pass_length] = '\n';
                pass[pass_length + 1] = '\0';

                fseek(name_fp, SEEK_CUR - 1, 0);
                fseek(id_fp, SEEK_CUR - 1, 0);
                fseek(pass_fp, SEEK_CUR - 1, 0);
            }

            else if(try_again == 0)
            {
                fclose(name_fp);
                fclose(id_fp);
                fclose(pass_fp);

                strcpy(logged_in_name, "\0");

                return ;
            }

            else
            {
                fclose(name_fp);
                fclose(id_fp);
                fclose(pass_fp);
                getchar();
                reg_status = user_reg();
                strcpy(logged_in_name, "\0");
                return ;
            }
        }

    }
    fclose(name_fp);
    fclose(id_fp);
    fclose(pass_fp);

    return ;
}
