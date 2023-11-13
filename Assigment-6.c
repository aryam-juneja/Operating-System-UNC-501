#include<stdio.h>

// first fit
void first_fit(int block, int no_of_files, int mem[], int files[]){
    printf("First Fit\n");

    int idx[no_of_files];

    for (int i = 0; i<no_of_files; i++) {
        for(int j = 0; j<block; j++) {
            if (mem[j] > files[i]) {
                mem[j] -= files[i];
                idx[i] = j+1; 
                break;
            }
        }
    }
    printf("Index --> ");
    for (int i = 0; i<no_of_files; i++) {
        printf("%d  ",idx[i]);
    }
    printf("\n");
    printf("Free space --> ");
    for (int i = 0; i<block; i++) {
        printf("%d  ",mem[i]);
    }
    printf("\n");
}

// best fit
void best_fit(int block, int no_of_files, int mem[], int files[]) {
    printf("Best Fit\n");

    int idx[no_of_files];

    for (int i=0; i<no_of_files; i++) {
        int diff = 999;
        int index = -1;
        for (int j=0; j<block; j++) {
            if (mem[j]-files[i] < diff && mem[j]-files[i] >= 0) {
                diff = mem[j] - files[i];
                index = j;
            }
        }
        idx[i] = index+1;
        mem[index] -= files[i];
    }
    printf("Index --> ");
    for (int i = 0; i<no_of_files; i++) {
        printf("%d  ",idx[i]);
    }
    printf("\n");
    printf("Free space --> ");
    for (int i = 0; i<block; i++) {
        printf("%d  ",mem[i]);
    }
    printf("\n");
}

// worst fit
void worst_fit(int block, int no_of_files, int mem[], int files[]) {
    printf("Worst Fit\n");

    int idx[no_of_files];

    for (int i=0; i<no_of_files; i++) {
        int diff = -1;
        int index = -1;
        for (int j=0; j<block; j++) {
            if (mem[j]-files[i] > diff && mem[j]-files[i] >= 0) {
                diff = mem[j] - files[i];
                index = j;
            }
        }
        idx[i] = index+1;
        mem[index] -= files[i];
    }
    printf("Index --> ");
    for (int i = 0; i<no_of_files; i++) {
        printf("%d  ",idx[i]);
    }
    printf("\n");
    printf("Free space --> ");
    for (int i = 0; i<block; i++) {
        printf("%d  ",mem[i]);
    }
    printf("\n");
}

void show(int n[]) {
    n = 9;
    printf("%d",n);
}

// driver code
int main() {
    int block = 3;
    int no_of_files = 2;

    int mem[] = {5,2,7};
    int files[] = {1,4};

    // first_fit(block, no_of_files, mem, files);
    // best_fit(block, no_of_files, mem, files);
    // worst_fit(block, no_of_files, mem, files);
    return 0;
}