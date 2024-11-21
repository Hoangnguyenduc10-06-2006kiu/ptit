#include <stdio.h>
#include <string.h>

#define MA_THI_SINH 100

typedef struct {
    int maSV; 						
    char name[100]; 
    char date_of_birth[100]; 
    float score[3]; 
    float total_score; 
} ThiSinh;

void nhap_thi_sinh(ThiSinh *ts, int maSV) {
    ts->maSV = maSV;
    printf("Nhap ten thi sinh: ");
    fgets(ts->name, sizeof(ts->name), stdin);
    ts->name[strcspn(ts->name, "\n")] = 0; 

    printf("Nhap ngay sinh (dd/mm/yyyy): ");
    fgets(ts->date_of_birth, sizeof(ts->date_of_birth), stdin);
    ts->date_of_birth[strcspn(ts->date_of_birth, "\n")] = 0; 

    printf("Nhap diem mon 1: ");
    scanf("%f", &ts->score[0]);
    printf("Nhap diem mon 2: ");
    scanf("%f", &ts->score[1]);
    printf("Nhap diem mon 3: ");
    scanf("%f", &ts->score[2]);
    ts->total_score = ts->score[0] + ts->score[1] + ts->score[2]; 
    getchar(); 
}

void tim_thu_khoa(ThiSinh ds[], int n) {
    float diem_cao_nhat = -1;
    int i;

    
    for (i = 0; i < n; i++) {
        if (ds[i].total_score > diem_cao_nhat) {
            diem_cao_nhat = ds[i].total_score;
        }
    }

    
    printf("Thu khoa:\n");
    for (i = 0; i < n; i++) {
        if (ds[i].total_score == diem_cao_nhat) {
            printf("%d %s %s %.1f\n", ds[i].maSV, ds[i].name, ds[i].date_of_birth, ds[i].total_score);
        }
    }
}

int main() {
    int n;
    ThiSinh ds[MA_THI_SINH];

    
    printf("Nhap so thi sinh: ");
    scanf("%d", &n);
    getchar(); 

    
    for (int i = 0; i < n; i++) {
        nhap_thi_sinh(&ds[i], i + 1);
    }

    
    tim_thu_khoa(ds, n);

    return 0;
}
