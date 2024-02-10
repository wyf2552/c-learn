#include <stdio.h>
#include <stdbool.h>

 int main() {
    int n = 0;
    int ret = -1;
    bool isFound = false;

    scanf("%d", &n);

    int x[n];    

    for (int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);

        if (x[i] == i && isFound == false) {
            ret = i;
            isFound = true;
        }
    }
    if (isFound == true) {
        printf("%d\n", ret);
    } else {
        printf("%c\n", 'N');
    }
 }
    
    
