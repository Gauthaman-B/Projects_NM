#include <stdio.h>
#include <stdlib.h>

void add_item();
void checkinv();
void total_inv();

struct inventory
{
    char item_name[20];
    int item_price;
    int item_id;
    int item_quantity;
};

struct inventory item[50];
int n;

void add_item()
{
    int new_items, i;
    printf("Enter number of items to add: ");
    scanf("%d", &n);

    for (i = n; i < n; i++)
    {
        printf("\nEnter Item %d Name: ", i + 1);
        scanf("%s", item[i].item_name);
        printf("Enter Item ID: ");
        scanf("%d", &item[i].item_id);
        printf("Enter Quantity: ");
        scanf("%d", &item[i].item_quantity);
        printf("Enter Item Price: ");
        scanf("%d", &item[i].item_price);
        printf("------------------------------------------\n");
    }

}

void checkinv()
{
    int i, total_value;

    if (n == 0)
    {
        printf("\nNo Items in The Inventory yet!\n");
        return;
    }

    printf("\n******** INVENTORY LIST ********\n");
    printf("--------------------------------------------------------------------------\n");
    printf("S.No | Name           | ID    | Quantity | Price(Rs.) | Total Value (Rs.)\n");
    printf("--------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        total_value = item[i].item_price * item[i].item_quantity;
        printf("%-4d | %-14s | %-5d | %-8d | %-10d | %-15d\n", i + 1, item[i].item_name, item[i].item_id, item[i].item_quantity, item[i].item_price, total_value);
    }

    printf("--------------------------------------------------------------------------\n");
}

void total_inv()
{
    int i, tot = 0;

    if (n == 0)
    {
        printf("\nNo items in inventory yet\n");
        return;
    }

    for (i = 0; i < n; i++)
    {
        tot += item[i].item_price * item[i].item_quantity;
    }

    printf("\n******* TOTAL INVENTORY VALUE *******\n");
    printf("Total Worth of Inventory = Rs. %d\n", tot);
    printf("-----------------------------------------\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n=== INVENTORY MANAGEMENT SYSTEM ===\n");
        printf("1. Add Item\n");
        printf("2. Check Inventory\n");
        printf("3. Total Value of Inventory\n");
        printf("4. Exit\n");
        printf("Choose Action: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_item();
            break;
        case 2:
            checkinv();
            break;
        case 3:
            total_inv();
            break;
        case 4:
            printf("\nExiting Program... \n");
            return 0;
        default:
            printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}
