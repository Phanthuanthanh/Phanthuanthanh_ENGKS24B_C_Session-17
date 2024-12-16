#include <stdio.h>
void nhapMang(int arr[], int *n);
void inMang(int arr[], int n);
void inSoChan(int arr[], int n);
int kiemTraSoNguyenTo(int num);
void inSoNguyenTo(int arr[], int n);
void daoNguocMang(int arr[], int n);
void sapXepMang(int arr[], int n);
void sapXepTangDan(int arr[], int n);
void sapXepGiamDan(int arr[], int n);
int timKiemPhanTu(int arr[], int n, int x);

int main() {
    int arr[1000];  
    int n = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("   a. Tang dan\n");
        printf("   b. Giam dan\n");
        printf("6. Nhap vao mot phan tu va tim kiem phan tu trong mang\n");
        printf("7. Thoat\n");
        printf("\nLua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(arr, &n);
                break;
            case 2:
                inSoChan(arr, n);
                break;
            case 3:
                inSoNguyenTo(arr, n);
                break;
            case 4:
                daoNguocMang(arr, n);
                break;
            case 5:
                printf("\nChon lua chon sap xep:\n");
                printf("a. Tang dan\n");
                printf("b. Giam dan\n");
                char subChoice;
                scanf(" %c", &subChoice);
                if (subChoice == 'a') {
                    sapXepTangDan(arr, n);
                } else if (subChoice == 'b') {
                    sapXepGiamDan(arr, n);
                } else {
                    printf("\nLua chon khong hop le!\n");
                }
                break;
            case 6:
                {
                    int x;
                    printf("\nNhap vao phan tu can tim: ");
                    scanf("%d", &x);
                    int index = timKiemPhanTu(arr, n, x);
                    if (index != -1) {
                        printf("\nPhan tu %d tim thay tai vi tri %d.\n", x, index);
                    } else {
                        printf("\nPhan tu %d khong co trong mang.\n", x);
                    }
                    break;
                }
            case 7:
                printf("\nThoat chuong trinh.\n");
                break;
            default:
                printf("\nLua chon khong hop le. Vui long chon lai!\n");
                break;
        }
    } while (choice != 7);

    return 0;
}

void nhapMang(int arr[], int *n) {
    printf("\nNhap so phan tu: ");
    scanf("%d", n);

    if (*n <= 0 || *n > 1000) {
        printf("\nSo phan tu khong hop le!\n");
        *n = 0;
        return;
    }

    printf("\nNhap cac phan tu:\n");
    for (int i = 0; i < *n; i++) {
        printf("Phan tu [%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

void inMang(int arr[], int n) {
    printf("\nMang: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void inSoChan(int arr[], int n) {
    printf("\nCac phan tu la so chan: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int kiemTraSoNguyenTo(int num) {
    if (num <= 1) return 0;  
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;  
        }
    }
    return 1; 
}

void inSoNguyenTo(int arr[], int n) {
    printf("\nCac phan tu la so nguyen to: ");
    for (int i = 0; i < n; i++) {
        if (kiemTraSoNguyenTo(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void daoNguocMang(int arr[], int n) {
    printf("\nMang sau khi dao nguoc: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sapXepMang(int arr[], int n) {
    printf("\nChon phuong thuc sap xep:\n");
    printf("a. Tang dan\n");
    printf("b. Giam dan\n");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'a') {
        sapXepTangDan(arr, n);
    } else if (choice == 'b') {
        sapXepGiamDan(arr, n);
    } else {
        printf("\nLua chon khong hop le!\n");
    }
}

void sapXepTangDan(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("\nMang sau khi sap xep tang dan: ");
    inMang(arr, n);
}

void sapXepGiamDan(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("\nMang sau khi sap xep giam dan: ");
    inMang(arr, n);
}

int timKiemPhanTu(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;  
        }
    }
    return -1;  
}

