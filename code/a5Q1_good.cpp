#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(char*)a - *(char *)b );
}

char* uniqueElements(int n, char* s) {
    char* unique = (char*)malloc(n * sizeof(char));
    int uniqueIndex = 0;
    qsort(s, n, sizeof(char), cmpfunc);
    for (int i = 0; i < n - 1; i++) {
       if (s[i] != s[i + 1]) {
            unique[uniqueIndex++] = s[i];
            unique[uniqueIndex++] = s[i + 1];
        }
    }
    return unique;
}

// 1sec ---> 10^8
// N =2 * 10^5

int hfactor(int n, int h, char* s) {
    char temp[n];
    for(int i=0; i<n; i++)
    {
        temp[i]=s[i];
    }
    char* unique = uniqueElements(n, s);//2 * 10^5
    int uniqueElement = strlen(unique);
    int counter = INT_MIN;
    for (int i = 0; i <26; i++) { //26
        int tracker = 0, hcounter = 0, ccounter = 0;
        char currentchar='a'+i;
        while (tracker < n) {  // 2 * 10^5
            if (temp[tracker] ==currentchar ) {
                hcounter++;
                if (hcounter == h) {
                    ccounter++;
                    hcounter = 0;
                }
            }
            else if (temp[tracker] != currentchar) {
                hcounter = 0;
            }
            tracker++;
        }
        counter = (counter > ccounter) ? counter : ccounter;
    }
    return counter;
}

int main() {
    int n, h;
    scanf("%d %d", &n, &h);
    char* s = (char*)malloc((n + 1) * sizeof(char));
    scanf("%s", s);
    int ans = hfactor(n, h, s);
    printf("%d\n", ans);
    free(s);
    return 0;
}
// 5
// 3 2 7 4 1
//1 2 3 4 7

//7 2
//4 3 1

//1 4 9 16 25

//25 4 
//16 9 1

// 9 16 25 100

//100
// //25 16 9  
// 10
// 603 324 573 493 659 521 654 70 718 257
// 70 257 324 493 521 573 603 654 659 718

// 718 603 493 324
// 659 654 573  