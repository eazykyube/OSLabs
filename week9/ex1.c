#include<stdio.h>
#include<stdlib.h>

int aging_algo(int page_frames) {
  FILE *file = fopen("input.txt", "r");
  int count = 0, hit = 0, miss = 0, some_var; 
  while (fgetc(file) != EOF){
    fscanf(file, "%d", &some_var);
    count++;
  }
  fclose(file);
  file = fopen("input.txt", "r");
  int *arr = calloc(count, sizeof(int));
  int *age = calloc(page_frames, sizeof(int));
  int *frame = calloc(page_frames, sizeof(int));
  for (int i = 0; i < count; i++){
    fscanf(file, "%d", &arr[i]);
    int free = 0, hitted = 0;
    for(int j = 0; j < page_frames; j++){
      age[j] = age[j] >> 1;
      if (frame[j] == arr[i] && hitted != 1){
        age[j] += (1<<31);
        hit++;
        hitted = 1; 
      }      
    }
    if (!hitted){
      for(int j = 0; j < page_frames; j++){
        if (frame[j] == 0){
          frame[j] = arr[i];
          age[j] = 1<<31;
          miss++;
          free = 1;
          break;
        }
      }
    }  
    if (!free && !hitted){
      int ind = 0;
      int min = age[0];
      for (int j = 1; j < page_frames; j++){
        if (age[j] < min){
          min = age[j];
          ind = j;
        }
      }
      frame[ind] = arr[i];
      age[ind] = 1<<31;
      miss++; 
    }
  }
  fclose(file);
  printf("Hit/Miss ratio: %f\n", (double) hit/miss);
  return 0;
}
int main(){
  aging_algo(10);
  aging_algo(50);
  aging_algo(100);
}