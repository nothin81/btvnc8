#include <stdio.h>
#include <string.h>

/*  Su dung struct de lam bai tap quan ly sinh vien */

int main(){
    int n;
    struct sinhVien
    {
        char hoTen;
        int namSinh;
        int gioiTinh;
        float cc, kT, dT, dKT;
    };
    
    printf("Cho biet so sinh vien: ");
    scanf("%d", &n);

    return 0;
}