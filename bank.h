
#ifndef _BANK_H
#define _BANK_H

#include <stdio.h>
#include <stdlib.h>

struct client
{
    char name[50];
    int ID;
    double cash;
    char type[7];
    struct client * Next;
};

typedef struct client Client_t;



//operation that client make in bank

//this function to check if the system has a client with that ID or not, if has return 1 , if not return -1
int Check_ID(Client_t * ptr, int ID);
//function to add a new client
void Create_New_Client(Client_t ** ptr);
//function to edit data of a client
void Edit_Client_Data(Client_t * ptr, int ID);
//function to print information for a client
void Print_Client_Data(Client_t * ptr, int ID);
//function to delete a client from database
void Delete_Client(Client_t ** ptrToptr, Client_t * ptr, int ID);
//function to transfer money from a client with Source_ID to a client with Destination_ID
void Transfer_Client_To_Client(Client_t * ptr1, int Source_ID, int Destination_ID, double money);

#endif
