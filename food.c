#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Food {
    int id;
    char name[50];
    float price;
};

struct Order {
    char username[50];
    char foodName[50];
    int quantity;
    float total;
};

// 🍽️ Menu
struct Food menu[] = {
    {1, "Burger", 120},
    {2, "Pizza", 250},
    {3, "Pasta", 180},
    {4, "Sandwich", 100},
    {5, "Juice", 80}
};

// 📜 Show Menu
void showMenu() {
    printf("\n--- Food Menu ---\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s - Rs. %.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
}

// 🛒 Place Order
void placeOrder(char username[]) {
    FILE *fp = fopen("orders.txt", "a");
    struct Order o;
    int choice, qty;

    showMenu();

    printf("Enter food ID: ");
    scanf("%d", &choice);

    printf("Enter quantity: ");
    scanf("%d", &qty);

    for (int i = 0; i < 5; i++) {
        if (menu[i].id == choice) {
            strcpy(o.foodName, menu[i].name);
            o.quantity = qty;
            o.total = qty * menu[i].price;
        }
    }

    strcpy(o.username, username);

    fwrite(&o, sizeof(o), 1, fp);
    fclose(fp);

    printf("Order placed! Total = Rs. %.2f\n", o.total);
}

// 📦 View Orders
void viewOrders(char username[]) {
    FILE *fp = fopen("orders.txt", "r");
    struct Order o;

    printf("\n--- Your Orders ---\n");

    while (fread(&o, sizeof(o), 1, fp)) {
        if (strcmp(o.username, username) == 0) {
            printf("\nFood: %s", o.foodName);
            printf("\nQuantity: %d", o.quantity);
            printf("\nTotal: Rs. %.2f\n", o.total);
        }
    }

    fclose(fp);
}

// 🔑 Simple Login
void login(char username[]) {
    printf("Enter username: ");
    scanf("%s", username);
}

// 🏠 Main
int main() {
    char username[50];
    int choice;

    login(username);

    while (1) {
        printf("\n1. View Menu\n2. Place Order\n3. View Orders\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) showMenu();
        else if (choice == 2) placeOrder(username);
        else if (choice == 3) viewOrders(username);
        else break;
    }

    return 0;
}