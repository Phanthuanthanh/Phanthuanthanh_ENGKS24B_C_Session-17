#include <stdio.h>
void nhapMang(int arr[], int *n);
void hienThiMang(int arr[], int n);
int tinhDoDaiMang(int n);
int tinhTongMang(int arr[], int n);
int timPhanTuLonNhat(int arr[], int n);

int main() {
    int n = 0;
    int choice;
    int arr[1000]; 

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("\nLua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(arr, &n);
                break;
            case 2:
                hienThiMang(arr, n);
                break;
            case 3:
                printf("\nDo dai mang: %d\n", tinhDoDaiMang(n));
                break;
            case 4:
                printf("\nTong cac phan tu trong mang: %d\n", tinhTongMang(arr, n));
                break;
            case 5:
                if (n > 0)
                    printf("\nPhan tu lon nhat: %d\n", timPhanTuLonNhat(arr, n));
                else
                    printf("\nMang chua co phan tu.\n");
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

void nhapMang(int arr[], int *n) {
    printf("\nNhap so phan tu trong mang: ");
    scanf("%d", n);

    if (*n <= 0 || *n > 1000) { 
        printf("\nSo phan tu khong hop le.\n");
        *n = 0;
        return;
    }

    printf("\nNhap tung phan tu:\n");
    for (int i = 0; i < *n; i++) {
        printf("Phan tu [%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

void hienThiMang(int arr[], int n) {
    if (n <= 0) {
        printf("\nMang chua co phan tu.\n");
        return;
    }

    printf("\nCac phan tu trong mang: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int tinhDoDaiMang(int n) {
    return n;
}

int tinhTongMang(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int timPhanTuLonNhat(int arr[], int n) {
    if (n <= 0) return -1; 

    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

