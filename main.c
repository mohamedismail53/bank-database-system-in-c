#include "bank.h"

int main()
{
    char choice;
    int id_check;
    int id_from;
    int id_to;
    int check1;
    int check2;

    double money_transfer;
    Client_t * head = (void *) 0;


    while(1)
    {
        //options to select from
        printf("please select one of the following options :\n\n1-create a new Client (press 1 to select this option)\n2-edit Client (press 2 to select this option )\n3-delete Client (press 3 to select this option)\n4-print Client data (press 4 to select this option)\n5-cash transfer from Client to another (press 5 t select this option)\n6-exit (press 6 to select this option)\n\nplease enter your choice: ");
        fflush(stdin);
        scanf("%c", &choice);

        switch(choice)
        {
        case '1':
            Create_New_Client(&head);
            break;

        case '2':
            do
            {
                printf("please enter the id of the Client who you need to change its data: ");
                scanf("%i",&id_check);
                check1 = Check_ID(head , id_check);
                if (check1 == -1)
                {
                    printf("please enter valid id \n");
                }
            }while (check1 == -1);

            Edit_Client_Data(head, id_check);
            break;

        case '3':
            do
            {
                printf("please enter the id of the Client who you need to Delete its data: ");
                scanf("%i",&id_check);
                check1 = Check_ID(head , id_check);
                if (check1 == -1)
                {
                    printf("please enter valid id \n");
                }
            }while (check1 == -1);

            Delete_Client(&head, head, id_check);
            break;

        case '4':
            do
            {
                printf("please enter the id of the Client who you need to print its data: ");
                scanf("%i",&id_check);
                check1 = Check_ID(head , id_check);
                if (check1 == -1)
                {
                    printf("please enter valid id \n");
                }
            }while (check1 == -1);

            Print_Client_Data(head, id_check);
            break;

        case '5':
            do
            {
                printf("please enter the id of the Client who the money will transfer from his cash: ");
                scanf("%i",&id_from);
                check1 = Check_ID(head , id_from);
                if (check1 == -1)
                {
                    printf("please enter valid id \n");
                }
            }while (check1 == -1);

            do
            {
                printf("please enter the id of the Client who the money will transfer to his cash: ");
                scanf("%i",&id_to);
                check2 = Check_ID(head , id_to);
                if (check2 == -1)
                {
                    printf("please enter valid id \n");
                }
            }while (check2 == -1);

            do
            {
                printf("please enter the money which will be transfered: ");
                scanf("%lf",&money_transfer);
            }while (money_transfer < 0);

            Transfer_Client_To_Client(head, id_from, id_to, money_transfer);
            break;
        case '6' :
            exit(0);

        default : printf("wrong choice\n\n");
        }
    }
    return 0;
}
