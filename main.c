#include <stdio.h>
#include <string.h>
/*  Su dung struct de lam bai tap quan ly sinh vien  */

typedef struct
{
    char hoTen[40];
    int namSinh;
    int gioiTinh;
    float cc, kT, dT, dTK;
} sinhVien;

void nhapLieu(sinhVien SV[99], int n){
    int i;
    for (i=0; i<=n-1; i++){
        printf("Nhap vao ho va ten cua sinh vien thu %d: ", i+1);
        getchar();  //loai new line identifier trong buffer stdin
        fgets(SV[i].hoTen, 30, stdin);

        printf("\nNhap vao nam sinh cua sinh vien thu %d: ", i+1);
        scanf("%d", &SV[i].namSinh);

        printf("Moi nhap gioi tinh cua sinh vien so %d: ", i+1);
        scanf("%d",&SV[i].gioiTinh);

        printf("Moi nhap DCC/DKT/DThi: ");
        scanf("%f%f%f", &SV[i].cc, &SV[i].kT, &SV[i].dT);

    };
}

void tinhToanDiem(){

}