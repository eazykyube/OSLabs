#include <stdio.h>

void swap(int *a, int *b){
    int c = 0;
    c = *a;
    *a = *b;
    *b = c;
}

void bubbleSort(int arr[], int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<n-i; j++){
      if(arr[j]>arr[j+1]){
        swap(&arr[j], &arr[j+1]);
      }
    }
  }
}

int main(){
  int a[5] = {1, 3, 4, 7, 6};
  int b = 5;
  bubbleSort(a, b);
  for(int i=0; i<5; i++){
    printf("%d\n", a[i]);
  }
}
