#include <stdio.h>
#include <string.h>

int login_status;
int reg_status;
char logged_in_name[20];
char logged_in_id[20];

void logout()
{
    int check;

    printf("\n1.Yes\n2.No\n\n>_");
    scanf("%d", &check);

    while(check != 1 && check != 2)
    {
        printf("\n\nWrong input!");
        printf("\n1.Yes\n2.No\n");

    }

    if(check == 2)
    {
        login_status = 0;
        reg_status = 0;
        strcpy(logged_in_name, "\0");
        strcpy(logged_in_id, "\0");
    }
}

