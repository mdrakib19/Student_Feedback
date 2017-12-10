#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Global variable for login logout
int login_status = 0;
char logged_in_name[20];
int reg_status = 0;
char logged_in_id[20];

/// Function prototype
void welcome();
int teacher_select();
int selection();
void review_filecheck(FILE *fp);
void display();
void insert_filecheck(FILE *fp);
void insert_review();
void menu_check();
int user_reg();
void reg_filecheck(FILE *fp);
void user_login();
void logout();
void ratting();

int main()
{
    int selected, user_menu, name_len;

    welcome();

    while(1)
    {
        if(reg_status == 0)
            selected = selection();

        if(selected == 1)
        {
            display();
        }

        else if(selected == 2)
        {
            printf("\n\nInsert review's: ");
            printf("\n---------------- ");

            if(login_status)
            {
                printf("\n\nLogin Successful: %s", logged_in_name);
                printf("\n-----------------");
                name_len = strlen(logged_in_name);
                while(name_len--)
                {
                    printf("-");
                }

                printf("\n\nContinue as: %s", logged_in_name);

                logout();

                if(login_status)
                {
                    user_menu = 1;
                }
            }

            else if(login_status != 1)
            {
                printf("\n\n1.User login\n2.User registration\n0.Main menu\n\n>_");
                scanf("%d", &user_menu);
            }

            while(1)
            {
                if(user_menu == 0)
                {
                    reg_status = 0;
                    break;
                }

                if(user_menu == 1)
                {
                    if(login_status == 0)
                        user_login();

                    if(strlen(logged_in_name))
                    {
                        insert_review(logged_in_name);
                        reg_status = 0;
                    }
                    break;
                }

                else if(user_menu == 2)
                {
                    getchar();
                    reg_status = user_reg();
                    break;
                }

                else
                {
                    printf("\n\nWrong input!");
                    printf("\n\n1.User login\n2.User registration\n0.Main menu\n\n>_");
                    scanf("%d", &user_menu);
                }
            }
        }

        else if(selected == 3)
        {
            ratting();
        }
    }

    return 0;
}
