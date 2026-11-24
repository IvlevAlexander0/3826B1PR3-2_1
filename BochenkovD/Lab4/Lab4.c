#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    srand(time(NULL));

    char barcodes[10][5] = { "1111", "2222", "3333", "4444", "5555" };
    char names[10][100] = { "Bread", "Milk", "Cheese", "Sausage", "Tea" };
    int prices[10] = { 50, 80, 400, 350, 150 };
    int discounts[10] = { 5, 10, 15, 20, 25 };
    int count_products = 5;

    int cart[100];
    int cart_quantity[100];
    int cart_count = 0;

    int choice, c;
    int i, j;

    do {
        printf("\n--- Electronic cash register ---\n");
        printf("1. Add a product description\n");
        printf("2. Scan the product (display description)\n");
        printf("3. Scan the product (add to the receipt)\n");
        printf("4. Output of the purchase receipt\n");
        printf("5. Generate the final receipt\n");
        printf("6. Exit\n");
        printf("Your choice: ");

        while (scanf("%d", &choice) != 1 || choice < 1 || choice > 6) {
            while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Error. Enter a number from 1 to 6: ");
        }

        switch (choice) {
        case 1: {
            if (count_products >= 10) {
                printf("Database is full!\n");
                break;
            }

            while ((c = getchar()) != '\n' && c != EOF) {}

            printf("\n--- Adding a new product ---\n");

            int barcode_ok = 0;
            while (barcode_ok == 0) {
                printf("Enter the barcode (exactly 4 digits): ");
                scanf("%s", barcodes[count_products]);
                while ((c = getchar()) != '\n' && c != EOF) {}

                if (strlen(barcodes[count_products]) != 4) {
                    printf("Error: barcode must be exactly 4 characters long!\n");
                    continue;
                }

                barcode_ok = 1;
                for (i = 0; i < 4; i++) {
                    if (barcodes[count_products][i] < '0' || barcodes[count_products][i] > '9') {
                        barcode_ok = 0;
                        printf("Error: barcode must contain only digits!\n");
                        break;
                    }
                }
            }

            printf("Enter the name: ");
            scanf(" %[^\n]", names[count_products]);
            while ((c = getchar()) != '\n' && c != EOF) {}

            while (strlen(names[count_products]) == 0) {
                printf("Error: name cannot be empty. Enter the name: ");
                scanf(" %[^\n]", names[count_products]);
                while ((c = getchar()) != '\n' && c != EOF) {}
            }

            printf("Enter the price (greater than 0): ");
            while (scanf("%d", &prices[count_products]) != 1 || prices[count_products] <= 0) {
                while ((c = getchar()) != '\n' && c != EOF) {}
                printf("Error! Enter a positive integer: ");
            }
            while ((c = getchar()) != '\n' && c != EOF) {}

            printf("Enter the discount (from 1 to 50): ");
            while (scanf("%d", &discounts[count_products]) != 1 || discounts[count_products] < 1 || discounts[count_products] > 50) {
                while ((c = getchar()) != '\n' && c != EOF) {}
                printf("Error! Discount must be from 1 to 50. Try again: ");
            }
            while ((c = getchar()) != '\n' && c != EOF) {}

            count_products++;
            printf("Product successfully added!\n");
            break;
        }

        case 2: {
            char scan_code[5];
            printf("Enter barcode: ");
            scanf("%4s", scan_code);

            int found = -1;
            for (i = 0; i < count_products; i++) {
                if (strcmp(barcodes[i], scan_code) == 0) {
                    found = i;
                    break;
                }
            }

            if (found != -1) {
                printf("Product: %s | Price: %d rub | Discount: %d%%\n",
                    names[found], prices[found], discounts[found]);
            }
            else {
                printf("Product not found!\n");
            }
            break;
        }

        case 3: {
            char scan_code[5];
            printf("Enter barcode to add to receipt: ");
            scanf("%4s", scan_code);

            int found = -1;
            for (i = 0; i < count_products; i++) {
                if (strcmp(barcodes[i], scan_code) == 0) {
                    found = i;
                    break;
                }
            }

            if (found != -1) {
                int in_cart = -1;
                for (i = 0; i < cart_count; i++) {
                    if (cart[i] == found) {
                        in_cart = i;
                        break;
                    }
                }

                if (in_cart != -1) {
                    cart_quantity[in_cart]++;
                }
                else {
                    cart[cart_count] = found;
                    cart_quantity[cart_count] = 1;
                    cart_count++;
                }
                printf("Product added to receipt!\n");
            }
            else {
                printf("Product not found!\n");
            }
            break;
        }

        case 4: {
            printf("\n--- Your receipt ---\n");
            if (cart_count == 0) {
                printf("Receipt is empty.\n");
                break;
            }

            int total_sum = 0;
            int total_discount = 0;

            for (i = 0; i < cart_count; i++) {
                int product_index = cart[i];
                int quantity = cart_quantity[i];
                int price = prices[product_index];
                int discount = discounts[product_index];

                int sum_without_discount = price * quantity;
                int discount_rub = sum_without_discount * discount / 100;
                int final_price = sum_without_discount - discount_rub;

                printf("%s - %d rub - %d pcs - %d%% - %d rub\n",
                    names[product_index], price, quantity, discount, final_price);

                total_sum += final_price;
                total_discount += discount_rub;
            }

            printf("-------------------------\n");
            printf("Total discount: %d rub\n", total_discount);
            printf("TOTAL TO PAY: %d rub\n", total_sum);
            break;
        }

        case 5: {
            printf("\n--- Generating final receipt ---\n");

            if (cart_count == 0) {
                printf("You bought nothing.\n");
            }
            else {
                int total_sum = 0;
                int total_discount = 0;

                for (i = 0; i < cart_count; i++) {
                    int product_index = cart[i];
                    int quantity = cart_quantity[i];
                    int price = prices[product_index];
                    int discount = discounts[product_index];

                    int sum_without_discount = price * quantity;
                    int discount_rub = sum_without_discount * discount / 100;
                    int final_price = sum_without_discount - discount_rub;

                    printf("%s - %d rub - %d pcs - %d%% - %d rub\n",
                        names[product_index], price, quantity, discount, final_price);

                    total_sum += final_price;
                    total_discount += discount_rub;
                }
                printf("-------------------------\n");
                printf("Total discount: %d rub\n", total_discount);
                printf("TOTAL TO PAY: %d rub\n", total_sum);
            }

            printf("\nStart a new receipt? (1 - Yes, 0 - No): ");
            int restart;
            while (scanf("%d", &restart) != 1 || (restart != 0 && restart != 1)) {
                while ((c = getchar()) != '\n' && c != EOF) {}
                printf("Error. Enter 1 or 0: ");
            }
            while ((c = getchar()) != '\n' && c != EOF) {}

            if (restart == 1) {
                cart_count = 0;
                printf("Receipt cleared. You can start scanning again.\n");
            }
            else {
                printf("Receipt closed. Returning to main menu.\n");
            }
            break;
        }

        case 6: {
            printf("Exiting the program. Goodbye!\n");
            break;
        }
        }
    } while (choice != 6);

    return 0;
}