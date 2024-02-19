#include <stdio.h>

double sum2(int n) {
    return 2.0 * n * (n+1) + 10.0 * (n+1);
}
int x(int n) {
    return (4*n+10);
}
int u(int n) {
    return (n >= 0) ? 1 : 0; // Unit step function u(n)
}


int main() {
    FILE *fp;
    fp = fopen("output.dat", "w"); // Open file for writing

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int n = 15; // Number of terms
    int a=10;
    int d=4;
    int sum=0;

    for (int i = 0; i <= n; i++) {
        //printf("%d\n", a);
        sum += a+ i*d;
        fprintf(fp, "%d\n", sum); 
        
    }

    // Write sum to file
    fprintf(fp,"Writing the sum of n terms through C\n");


    int y[5];
    

    // Convolution sum for the first 5 elements
    for (n = 0; n < 5; n++) {
        y[n] = 0;
        for (int k = 0; k <= n; k++) {
            y[n] += x(k) * u(n - k);
        }
    }

    // Store the first 5 elements of y(n) in a text file
    

    fprintf(fp, "n\t\ty(n)\n");
    for (n = 0; n < 5; n++) {
        fprintf(fp, "%d\t\t%d\n", n, y[n]);
    }


    double sumvalues[5];
    fprintf(fp,"Writing Sum values through convolution\n");
    
    // Generate the first five terms of the sequence
    for (n = 0; n < 5; n++) {
        sumvalues[n] = sum2(n);
    }

    // Store the first five terms in a text file
   
    fprintf(fp, "n\t\ty(n)\n");
    for (n = 0; n < 5; n++) {
        fprintf(fp, "%d\t\t%.2f\n", n, sumvalues[n]);
    }
    fprintf(fp,"Generating the first five terms of the sequence using the formula of y(n)\n");
    fclose(fp);

    return 0;
}
