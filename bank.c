#include "bank.h"

int counter = 0;

int Check_ID(Client_t * ptr, int ID)
{
    int ret = -1;
    if (ptr == NULL)
    {
        ret = 1;
    }

    while (ptr != NULL)
    {
        if (ptr->ID == ID)
        {
            ret = 2;
            break;
        }
        ptr = ptr->Next;
    }
    return ret;
}


void Create_New_Client(Client_t ** ptr)
{
    Client_t * new_client = (Client_t *) malloc(sizeof(Client_t));
    printf("please enter the name of the Client number %i: ", counter+1);
    fflush(stdin);
    scanf("%s", &(new_client->name[0]));

    do
    {
        printf("please enter the cash of Client number %i: ", counter+1);
        fflush(stdin);
        scanf("%lf", &(new_client->cash));
        if(new_client->cash < 0)
        {
            printf("the cash money should be positive number and greater than or equal zero  \n");
        }
    }while(new_client->cash < 0);

    printf("please enter the type of the Client number %i (debit or credit): ", counter+1);
    fflush(stdin);
    scanf("%s", &(new_client->type[0]));

    printf("please enter the id of the Client number %i: ", counter+1);
    scanf("%i", &(new_client->ID));
    new_client -> Next = *ptr;
    *ptr = new_client;
    printf("\n\n");

    counter++;
}


void Edit_Client_Data(Client_t * ptr, int ID)
{
    if(ptr == NULL)
    {
        printf("the linked list is empty\n\n");
        return ;
    }
    while (ptr != NULL)
    {
        if (ptr->ID == ID)
        {
            printf("please enter the new name: ");
            fflush(stdin);
            scanf("%s", &(ptr->name[0]));

            printf("please enter the new cash: ");
            scanf("%lf",&(ptr->cash));

            printf("please enter the new type (Debit or credit): ");
            fflush(stdin);
            scanf("%s", &(ptr->type[0]));

            printf("please enter the new id: ");
            scanf("%i",&(ptr->ID));
            break ;
        }
        ptr = ptr->Next;
    }
}


void Print_Client_Data(Client_t * ptr, int ID)
{
    if (ptr == NULL)
    {
        printf("the linked list is empty \n\n");
        return ;
    }

    while (ptr != NULL)
    {
        if (ptr->ID == ID)
        {
            printf("the name of the Client number %i is: %s\n" ,counter+1, ptr->name);
            printf("the cash of the Client number %i is: %0.2lf\n" ,counter+1, ptr->cash);
            printf("the type of the Client number %i is: %s\n" ,counter+1, ptr->type);
            printf("the id of the Client number %i is: %i\n" ,counter+1, ptr->ID);
            printf("\n\n");
            break;
        }
        ptr = ptr->Next;
    }
}

void Delete_Client(Client_t ** ptrToptr, Client_t * ptr, int ID)
{
    int i=0, j;

    Client_t * temp1;
    Client_t * temp2 = ptr;

    if (ptr == NULL)
    {
        printf("the linked list is empty\n\n");
        return ;
    }

    if (ptr->Next == NULL)
    {
        free(*ptrToptr);
        *ptrToptr = NULL;
        counter--;
        return ;
    }

    while (ptr != NULL)
    {
        if (ptr->ID == ID)
        {
            break;
        }
        ptr = ptr->Next;
        i++;
    }

    if (i == 0)
    {
        *ptrToptr = (*ptrToptr)->Next;
        free(temp2);
        counter--;
        return;
    }

    for(j=0; j<i-1; j++)
    {
        temp2 = temp2->Next;
    }
    printf("i=%i",i);
    printf("j=%i",j);
    temp1 = temp2->Next;
    temp2->Next = temp1->Next;
    free(temp1);
    counter--;
}


void Transfer_Client_To_Client(Client_t * ptr1, int Source_ID, int Destination_ID, double money)
{
    int i = 0, j = 0;

    if (ptr1 == NULL)
    {
        printf("the linked list is empty\n\n");
        return ;
    }

    if (ptr1->Next == NULL)
    {
        printf("the linked list is containing just one element and to transfer money it must be at least 2 elements \n\n");
        return ;
    }

    while (ptr1 != NULL)
    {
        if (ptr1->ID == Source_ID)
        {
            if (ptr1->cash < money)
            {
                printf("the transfered money is more than client money\n");
                return ;
            }
            ptr1->cash -= money;
            i = 1;
        }

        if (ptr1->ID == Destination_ID)
         {
             ptr1->cash += money;
             j = 1;
         }

         if (i == 1 && j == 1)
         {
             break;
         }
         ptr1 = ptr1->Next;
    }
}
