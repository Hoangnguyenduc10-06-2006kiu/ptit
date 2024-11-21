#include <stdio.h>

void nhap(int a[100][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void tinh(int a[100][100], int b[100][100], int c[100][100], int n, int m) {
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0; 
            for (int k = 0; k < m; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void in(int c[100][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", c[i][j]);
            if (j < n - 1) printf(" "); 
        }
        printf("\n"); 
    }
}

int main() {
    int t; 
    scanf("%d", &t);
    
    for (int check = 1; check <= t; check++) {
        int n, m;
        scanf("%d %d", &n, &m);
        
        int a[100][100];
        int b[100][100]; 
        int c[100][100]; 
        
        
        nhap(a, n, m);
        
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[j][i] = a[i][j];
            }
        }
        
       
        tinh(a, b, c, n, m);
        
        
        printf("Test %d:\n", check);
        in(c, n);
    }

    return 0;
}
