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
    for (i=0; i<n; i++){
        printf("\nNhap vao ho va ten cua sinh vien thu %d: ", i+1);
        getchar();  //loai new line identifier trong buffer stdin cho fgets()
        fgets(SV[i].hoTen, sizeof(SV[i].hoTen), stdin);
        SV[i].hoTen[strcspn(SV[i].hoTen, "\n")] = 0;    //loai bo khoang new line phia sau. //fflush(stdin) gan giong voi endl() trong CXX

        printf("Nhap vao nam sinh cua sinh vien thu %d: ", i+1);
        scanf("%d", &SV[i].namSinh);

        printf("Moi nhap gioi tinh cua sinh vien (0: Nam, 1: Nu) : ");
        printf("Moi nhap gioi tinh cua sinh vien (0: Nam, 1: Nu) : ");
        scanf("%d",&SV[i].gioiTinh);

        printf("Moi nhap DCC/DKT/DThi: ");
        scanf("%f%f%f", &SV[i].cc, &SV[i].kT, &SV[i].dT);
    };
}

void tinhToanDiem(sinhVien SV[99], int n){
    for (int i=0; i<n; i++)
    {
        SV[i].dTK = SV[i].cc * 0.1 + SV[i].kT * 0.4 + SV[i].dT * 0.5;
    }
}

void sapXepDS(sinhVien SV[99], int n){
    //an cap tu bai truoc
    int i, j;
    sinhVien temp1;
    for (i = 0; i <= n-1; i++) {
        for (j = i+1; j < n; j++){
        if (SV[i].dTK < SV[j].dTK) {
            temp1 = SV[i];
            SV[i] = SV[j];
            SV[j] = temp1;
            }
        }
    };
    //note : gan cho temp de di chuyen toan bo struct.
}

void DSHeader(sinhVien SV[99], int n){
    //an cap cua nvidia-smi
    printf("\n+-------------------------------------------------------+");
    printf("\n| STT |            Ho va ten           |  DThi  |  DTK  |");
    printf("\n|=====+================================+========+=======|");
    for (int i = 0; i < n; i++)
    {
        printf("\n| %3d | %-30s |   %3.1f  |  %3.1f  |", i+1, SV[i].hoTen, SV[i].dT, SV[i].dTK);    //-30 de loai bo khoang trang.
    };
    printf("\n+-------------------------------------------------------+");
}

int main(){
    sinhVien svien[99];
    int n;
    
    printf("Nhap vao so sinh vien: ");
    scanf("%d", &n);
    nhapLieu(svien, n);
    tinhToanDiem(svien, n);
    printf("\nBan da nhap vao danh sach sau day: ");
    DSHeader(svien, n);
        
    printf("\n> Ban co muon in ra bang da sap xep (y/N)? ");
    /* feature ask usr*/
    
    printf("\n\n");
    sapXepDS(svien, n);
    DSHeader(svien, n);     
    printf("\n\n === Chuong trinh ket thuc ===");
    return 0;
}