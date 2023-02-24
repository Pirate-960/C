// It is assumed that user will enter arrays in ascending order
#include <stdio.h>
 
void merge(double a[], int m, double b[], int n, double sorted[]);
 
int main() {
  double a[100], b[100], sorted[200];
  int  m, n, c;
 
  printf("Enter the number of elements in first array (there can be at most 100 elements in the array) : \n");
  scanf("%d", &m);
 
  printf("Enter %d sorted double values for the first array: \n", m);
  for (c = 0; c < m; c++) {
    scanf("%lf", &a[c]);
  }
 
  printf("Enter the number of elements in second array (there can be at most 100 elements in the array) : \n");
  scanf("%d", &n);
 
  printf("Enter %d sorted double values for the first array: \n", n);
  for (c = 0; c < n; c++) {
    scanf("%lf", &b[c]);
  }
 
  merge(a, m, b, n, sorted);
 
  printf("Sorted array:\n");
 
  for (c = 0; c < m + n; c++) {
    printf("%lf\n", sorted[c]);
  }
 
  return 0;
}
 
void merge(double a[], int m, double b[], int n, double sorted[]) {
  int i, j, k;
 
  j = k = i= 0;
 

    while (j < m && k < n) {
      if (a[j] < b[k]) {
        sorted[i] = a[j];
        j++;
      }
      else if(a[j] > b[k]){
        sorted[i] = b[k];
        k++;
      }
      else{
      	sorted[i] = a[j];
        j++;
        k++;
	  }
      i++;
    }
    
  
    if (j == m) {
      while (i < m + n) {
        sorted[i] = b[k];
        k++;
        i++;
      }
    }
    else {
      while (i < m + n) {
        sorted[i] = a[j];
        j++;
        i++;
      }
    }
}
