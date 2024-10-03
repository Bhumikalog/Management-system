//Happy coding!
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SUPPLIERS 100
#define MAX_PRODUCTS 100
#define MAX_TRANSACTIONS 100

struct Suppliers {
    int id;
    char name[50];
    char address[50];
};

struct Products {
    int id;
    char name[50];
    float price;
};

struct Transactions {
    int id;
    char mode[50];
    float amount;
};

struct Suppliers s[MAX_SUPPLIERS];
struct Products p[MAX_PRODUCTS];
struct Transactions t[MAX_TRANSACTIONS];

int supplierCount = 0;
int productCount = 0;
int transactionCount = 0;

void add_supplier();
void displaySuppliers();
void writeSuppliersToCSV();

void add_product();
void displayProducts();
void writeProductsToCSV();

void add_transaction();
void displayTransactions();
void writeTransactionsToCSV();


void add_supplier() {
    if (supplierCount >= MAX_SUPPLIERS) {
        printf("Suppliers limit reached. Cannot add more suppliers.\n");
        return;
    }
    struct Suppliers newSupplier;
    int idExists = 0;
    printf("Enter Supplier Name: ");
    scanf("%s", newSupplier.name);

    do {
        idExists = 0;
        printf("Enter Supplier ID: ");
        scanf("%d", &newSupplier.id);
        getchar();
        for (int i = 0; i < supplierCount; i++) {
            if (s[i].id == newSupplier.id) {
                idExists = 1;
                printf("Supplier ID already exists. Please enter a unique ID.\n");
                break;
            }
        }
    } while (idExists);

    printf("Enter address: ");
    scanf("%s", newSupplier.address);

    s[supplierCount++] = newSupplier;

    printf("Supplier Data created successfully!\n");
}

void writeSuppliersToCSV() {
    FILE *file = fopen("SUPPLIERS.csv", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "SUPPLIER_ID,NAME,ADDRESS\n");

    for (int i = 0; i < supplierCount; i++) {
        fprintf(file, "%d,%s,%s\n",
                s[i].id,
                s[i].name,
                s[i].address);
    }

    fclose(file);
    printf("Supplier data successfully written to SUPPLIERS.csv\n");
}

void displaySuppliers() {
    if (supplierCount == 0) {
        printf("No Supplier to display.\n");
        return;
    }

    for (int i = 0; i < supplierCount; i++) {
        printf("\nSupplier Details %d\n", i + 1);
        printf("Name: %s\n", s[i].name);
        printf("ID: %d\n", s[i].id);
        printf("Address: %s\n", s[i].address);
    }
}

void add_product() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Products limit reached. Cannot add more products.\n");
        return;
    }
    struct Products newProduct;
    int idExists = 0;
    printf("Enter Product Name: ");
    scanf("%s", newProduct.name);

    do {
        idExists = 0;
        printf("Enter Product ID: ");
        scanf("%d", &newProduct.id);
        getchar();
        for (int i = 0; i < productCount; i++) {
            if (p[i].id == newProduct.id) {
                idExists = 1;
                printf("Product ID already exists. Please enter a unique ID.\n");
                break;
            }
        }
    } while (idExists);

    printf("Enter price: ");
    scanf("%f", &newProduct.price);

    p[productCount++] = newProduct;

    printf("Product Data created successfully!\n");
}

void writeProductsToCSV() {
    FILE *file = fopen("PRODUCTS.csv", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

        fprintf(file, "PRODUCT_ID,NAME,PRICE\n");

    for (int i = 0; i < productCount; i++) {
        fprintf(file, "%d,%s,%f\n",
                p[i].id,
                p[i].name,
                p[i].price);
    }

    fclose(file);
    printf("Product data successfully written to PRODUCTS.csv\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("No Product to display.\n");
        return;
    }

    for (int i = 0; i < productCount; i++) {
        printf("\nProduct Details %d\n", i + 1);
        printf("Name: %s\n", p[i].name);
        printf("ID: %d\n", p[i].id);
        printf("Price: %.2f\n", p[i].price);
    }
}

void add_transaction() {
    if (transactionCount >= MAX_TRANSACTIONS) {
        printf("Transactions limit reached. Cannot add more transactions.\n");
        return;
    }
    struct Transactions newTransaction;
    int idExists = 0;
    printf("Enter Transaction mode: ");
    scanf("%s", newTransaction.mode);

    do {
        idExists = 0;
        printf("Enter Transaction ID: ");
        scanf("%d", &newTransaction.id);
        getchar();
        for (int i = 0; i < transactionCount; i++) {
            if (t[i].id == newTransaction.id) {
                idExists = 1;
                printf("Transaction ID already exists. Please enter a unique ID.\n");
                break;
            }
        }
    } while (idExists);

    printf("Enter amount: ");
    scanf("%f", &newTransaction.amount);

    t[transactionCount++] = newTransaction;

    printf("Transaction Data created successfully!\n");
}

void writeTransactionsToCSV() {
    FILE *file = fopen("TRANSACTIONS.csv", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "TRANSACTION_ID,MODE,AMOUNT\n");

    for (int i = 0; i < transactionCount; i++) {
        fprintf(file, "%d,%s,%.2f\n",
                t[i].id,
                t[i].mode,
                t[i].amount);
    }

    fclose(file);
    printf("Transaction data successfully written to TRANSACTIONS.csv\n");
}

void displayTransactions() {
    if (transactionCount == 0) {
        printf("No Transaction to display.\n");
        return;
    }

    for (int i = 0; i < transactionCount; i++) {
        printf("\nTransaction Details %d\n", i + 1);
        printf("ID: %d\n", t[i].id);
        printf("Mode: %s\n", t[i].mode);
        printf("Amount: %.2f\n", t[i].amount);
    }
}

int main() {
    char ch;

    while (1) {
        printf("_Welcome to IMS!!_\n\n");
        printf("Here is your menu: \n\n");
        printf("a. Product details\nb. Supplier details\nc. Transaction details\nd. Exit \n");
        printf("Enter your choice: (E.g., Enter a, b, c, d for above mentioned options) \n");

        scanf(" %c", &ch);
        
        if (ch < 'a' || ch > 'd') {
            printf("Invalid choice. Please enter a small letter between a and d.\n");
            continue;
        }

        if (ch == 'd')
            break;

        switch (ch) {
            case 'a':
                printf("You have selected product details.\n");
                printf("1. Add the product\n2. Display the product and create csv\n3. Exit\n");
                printf("Enter your choice: (E.g., Enter 1, 2, 3 for above mentioned options) \n");
                int choice;
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("You have selected to add the product.\n");
                        add_product();
                        break;
                    case 2:
                        printf("You have selected to display the product and create csv.\n");
                        displayProducts();
                        writeProductsToCSV();
                        break;
                    case 3:
                        printf("You have selected exit.\n");
                        exit(0);
                }
                break;

            case 'b':
                printf("You have selected supplier details.\n");
                printf("1. Add the supplier\n2. Display the supplier\n3. Exit\n");
                printf("Enter your choice: (E.g., Enter 1, 2, 3 for above mentioned options)\n");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("You have selected to add the supplier.\n");
                        add_supplier();
                        break;
                    case 2:
                        printf("You have selected to display the supplier and create csv.\n");
                        displaySuppliers();
                        writeSuppliersToCSV();
                        break;
                    case 3:
                        printf("You have selected exit.\n");
                        exit(0);
                }
                break;

            case 'c':
                printf("You have selected transaction details.\n");
                printf("1. Record new transaction\n2. Display transaction and create csv\n3. Exit\n");
                printf("Enter your choice: (E.g., Enter 1, 2, 3 for above mentioned options) \n");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("You have selected to add the transactions.\n");
                        add_transaction();
                        break;
                    case 2:
                        printf("You have selected to display the transaction.\n");
                        displayTransactions();
                        writeTransactionsToCSV();
                        break;
                    case 3:
                        printf("You have selected exit.\n");
                        exit(0);
                }
                break;
        }
    }
    return 0;
}
//Thank you

