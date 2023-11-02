#include<stdio.h>

int main() {
    int block = 3;
    int no_of_files = 2;
    // printf("Type the no. of blocks:\n");
    // scanf("%d", &block);
    // printf("%d",block);

    int mem[] = {5,2,7};
    int files[] = {1,4};
    int idx[no_of_files];
    int size = sizeof(mem)/sizeof(mem[0]);
   
    // printf("%d",size);

    // first fit
    for (int i = 0; i<no_of_files; i++) {
        for(int j = 0; j<block; j++) {
            if (mem[j] > files[i]) {
                mem[j] -= files[i];
                idx[i] = j+1; 
                break;
            }
        }
    }


    for (int i = 0; i<no_of_files; i++) {
        printf("%d  ",idx[i]);
    }
    printf("\n");
    for (int i = 0; i<block; i++) {
        printf("%d  ",mem[i]);
    }
    printf("\n");

    int membf[] = {5,2,7};
    int bf_idx[no_of_files];

    // best fit
    for (int i = 0; i<no_of_files; i++) {
        int diff = 0;
        int best_idx = -1;
        for(int j = 0; j<block; j++) {
            int temp = membf[j] - files[i];
            if (temp<diff) {
                diff = temp;
                best_idx = j;
            }
            membf[best_idx] -= files[i]; 
            bf_idx[i] = best_idx=1;
        }
    }

    for (int i = 0; i<no_of_files; i++) {
        printf("%d  ",bf_idx[i]);
    }
    printf("\n");
    for (int i = 0; i<block; i++) {
        printf("%d  ",membf[i]);
    }

    // for (int i = 0; i < size; i++) {

    // }
    return 0;
}