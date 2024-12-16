#include <stdio.h>
#include <string.h>
void nhapChuoi(char *str, int maxLength);
void inChuoi(char *str);
int demChuCai(char *str);
int demChuSo(char *str);
int demKyTuDacBiet(char *str);

int main() {
    char str[1000];  
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi\n");
        printf("4. Dem so luong chu so trong chuoi\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi\n");
        printf("6. Thoat\n");
        printf("\nLua chon cua ban: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                nhapChuoi(str, 1000);  
                break;
            case 2:
                inChuoi(str);
                break;
            case 3:
                printf("\nSo luong chu cai trong chuoi: %d\n", demChuCai(str));
                break;
            case 4:
                printf("\nSo luong chu so trong chuoi: %d\n", demChuSo(str));
                break;
            case 5:
                printf("\nSo luong ky tu dac biet trong chuoi: %d\n", demKyTuDacBiet(str));
                break;
            case 6:
                printf("\nThoat chuong trinh.\n");
                break;
            default:
                printf("\nLua chon khong hop le. Vui long chon lai!\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

void nhapChuoi(char *str, int maxLength) {
    printf("\nNhap vao chuoi : ", maxLength - 1);
    fgets(str, maxLength, stdin);  

    str[strcspn(str, "\n")] = '\0';
}

void inChuoi(char *str) {
    printf("\nChuoi: %s\n", str);
}

int demChuCai(char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            count++;
        }
    }
    return count;
}

int demChuSo(char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            count++;
        }
    }
    return count;
}

int demKyTuDacBiet(char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {

        if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z') && !(str[i] >= '0' && str[i] <= '9') && str[i] != ' ') {
            count++;
        }
    }
    return count;
}

