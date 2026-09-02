#include "include/nha_hang.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    TD td;
    khoiTaoThucDon(&td);
    int luonChon;

    themMonAn(&td, taoMonAn("MA01", "Com Tam", "Mon chinh", 35.0));
    themMonAn(&td, taoMonAn("MA02", "Pho Bo", "Mon chinh", 45.0));
    themMonAn(&td, taoMonAn("MA03", "Tra Sua", "Giai khat", 25.0));
    themMonAn(&td, taoMonAn("MA04", "Bun Ca", "Mon chinh", 30.0));

    do {
        printf("\n================ QUAN LY NHA HANG ================\n");
        printf("1. Nhap / Them mon an moi\n");
        printf("2. Hien thi danh sach thuc don\n");
        printf("3. Tim kiem mon an\n");
        printf("4. Xoa mon an\n");
        printf("5. Cap nhat thong tin mon an\n");
        printf("6. Sap xep thuc don\n");
        printf("7. Doc / Ghi file text\n");
        printf("8. Quon ly ban an & Thanh toan\n");
        printf("0. Thoat chuong trinh\n");
        printf("==================================================\n");
        printf("Nhap lua chon cua ban: ");
        if(scanf("%d", &luonchon) != 1){
        	printf("Vui long nhap so!\n");
        	while(getchar() != "\n");
        	continue;
		}
        getchar();

        switch (luonChon) {
            case 1:{
            	printf("Nhap / Them mon an: ");
            	nhapDanhSachMonAn(&td);
            	break;
				
			
			}
            case 2:{
				hienThiThucDon(&td);
				break;
			
			}
            case 3:{
			int chonTimKiem;
                printf("\n----- TIM KIEM MON AN -----\n");
                printf("1. Tim kiem theo Ma mon\n");
                printf("2. Tim kiem theo Ten mon\n");
                printf("3. Tim kiem theo Loai mon\n");
                printf("4. Tim kiem theo Khoang gia\n");
                printf("Chon phuong thuc tim kiem: ");
                scanf("%d", &chonTimKiem);
                getchar();

                switch (chonTimKiem) {
                    case 1: {
                        char ma[15];
                        printf("Nhap ma mon an can tim: ");
                        fgets(ma, sizeof(ma), stdin);
                        ma[strcspn(ma, "\n")] = '\0';

                        MA *found = timKiemTheoMa(&td, ma);
                        if (found != NULL) {
                            printf("\n=> KET QUA TIM KIEM:\n");
                            printf("| %-12s | %-25s | %-15s | %-10s |\n", "Ma Mon", "Ten Mon", "Loai Mon", "Gia");
                            printf("-----------------------------------------------------------------------------\n");
                            hienThiMonAn(found);
                        } else {
                            printf("Khong tim thay mon an co ma: %s\n", ma);
                        }
                        break;
                    }
                    case 2: {
                        char ten[50];
                        printf("Nhap ten mon an can tim: ");
                        fgets(ten, sizeof(ten), stdin);
                        ten[strcspn(ten, "\n")] = '\0';

                        TD kq = timKiemTheoTen(&td, ten);
                        if (kq.count > 0) {
                            printf("\n=> KET QUA TIM KIEM THEO TEN (%d mon):\n", kq.count);
                            hienThiThucDon(&kq);
                            giaiPhongThucDon(&kq); // Giai phong danh sach tam
                        } else {
                            printf("Khong tim thay mon an nao co ten chua: '%s'\n", ten);
                        }
                        break;
                    }
                    case 3: {
                        char loai[30];
                        printf("Nhap loai mon an can tim: ");
                        fgets(loai, sizeof(loai), stdin);
                        loai[strcspn(loai, "\n")] = '\0';

                        TD kq = timKiemTheoLoai(&td, loai);
                        if (kq.count > 0) {
                            printf("\n=> KET QUA TIM KIEM THEO LOAI (%d mon):\n", kq.count);
                            hienThiThucDon(&kq);
                            giaiPhongThucDon(&kq);
                        } else {
                            printf("Khong tim thay mon an nao thuoc loai: '%s'\n", loai);
                        }
                        break;
                    }
                    case 4: {
                        double min, max;
                        printf("Nhap gia thap nhat: ");
                        scanf("%lf", &min);
                        printf("Nhap gia cao nhat: ");
                        scanf("%lf", &max);
                        getchar();

                        TD kq = timKiemTheoKhoangGia(&td, min, max);
                        if (kq.count > 0) {
                            printf("\n=> KET QUA TIM KIEM THEO KHOANG GIA %.2f - %.2f (%d mon):\n", min, max, kq.count);
                            hienThiThucDon(&kq);
                            giaiPhongThucDon(&kq);
                        } else {
                            printf("Khong co mon an nao trong khoang gia tu %.2f den %.2f\n", min, max);
                        }
                        break;
                    }
                    default:
                        printf("Lua chon tim kiem khong hop le!\n");
                }
                break;
            }}
            case 4:{}
            case 5:{}
            case 6:{}
            case 7:{}
            case 8:{}
            case 0:{}
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (luonChon != 0);

    return 0;
}
