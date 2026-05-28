#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

void addProduct() {
    Product p;
    FILE *file = fopen("inventory.txt", "a");
    if (!file) return;
    printf("اسم المنتج: "); scanf("%s", p.name);
    printf("الكمية: "); scanf("%d", &p.quantity);
    printf("السعر: "); scanf("%f", &p.price);
    fprintf(file, "%s %d %.2f\n", p.name, p.quantity, p.price);
    fclose(file);
}

void viewProducts() {
    Product p;
    FILE *file = fopen("inventory.txt", "r");
    if (!file) { printf("المخزون فارغ.\n"); return; }
    while (fscanf(file, "%s %d %f", p.name, &p.quantity, &p.price) != EOF)
        printf("المنتج: %s | الكمية: %d | السعر: %.2f\n", p.name, p.quantity, p.price);
    fclose(file);
}

void searchProduct() {
    Product p;
    char name[50];
    int found = 0;
    FILE *file = fopen("inventory.txt", "r");
    if (!file) return;
    printf("اسم المنتج للبحث: "); scanf("%s", name);
    while (fscanf(file, "%s %d %f", p.name, &p.quantity, &p.price) != EOF) {
        if (strcmp(p.name, name) == 0) {
            printf("تم العثور: %s - السعر: %.2f\n", p.name, p.price);
            found = 1; break;
        }
    }
    if (!found) printf("غير موجود.\n");
    fclose(file);
}

int main() {
    int choice;
    while(1) {
        printf("\n1.إضافة 2.عرض 3.بحث 4.خروج\nاختر: ");
        scanf("%d", &choice);
        if(choice==1) addProduct();
        else if(choice==2) viewProducts();
        else if(choice==3) searchProduct();
        else break;
    }
    return 0;
}