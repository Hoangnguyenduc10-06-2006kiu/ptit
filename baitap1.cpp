#include <stdio.h>
#include <string.h>
#include <ctype.h>

void xau_ho_ten(char *ho_ten) {
    int i, len = strlen(ho_ten);
    char viet_hoa[100]; 
    int j = 0; 

    
    while (ho_ten[0] == ' ') {
        for (i = 0; i < len; i++) {
            ho_ten[i] = ho_ten[i + 1];
        }
        len--;
    }

    
    for (i = 0; i < len; i++) {
        
        if (i == 0 || ho_ten[i - 1] == ' ') {
            viet_hoa[j++] = toupper(ho_ten[i]); 
        } else if (ho_ten[i] == ' ' && ho_ten[i + 1] == ' ') {
            continue; 
        } else {
            viet_hoa[j++] = tolower(ho_ten[i]); 
        }
    }

    
    if (j > 0 && viet_hoa[j - 1] == ' ') {
        j--;
    }

    viet_hoa[j] = '\0'; 
    printf("%s\n", viet_hoa); 
}

int main() {
    int n;
    char ho_ten[100];

    
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        fgets(ho_ten, sizeof(ho_ten), stdin);
        ho_ten[strcspn(ho_ten, "\n")] = 0; 
        xau_ho_ten(ho_ten);
    }

    return 0;
}
