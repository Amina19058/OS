#include <stdio.h>
#include <stdbool.h>

int main(void) {
  FILE *mf;
  mf = fopen("input.txt", "r");
  FILE *output;
  output = fopen("output.txt", "w");
  if (mf == NULL)
    printf("Error");
  int E[3];
  int A[3];
  bool finish[5];
  for (int i = 0; i < 5; i++) {
    finish[i] = false;
  }
  int work[3];
  int C[5][3];
  int R[5][3];
  for (int i = 0; i < 3; i++) {
    fscanf(mf, "%d", &E[i]);
  }
  for (int i = 0; i < 3; i++) {
    fscanf(mf, "%d", &A[i]);
    work[i] = A[i];
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++){
      fscanf(mf, "%d", &C[i][j]);
    }
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++){
      fscanf(mf, "%d", &R[i][j]);
    }
  }
  for (int k = 0; k < 5; k++) {

  for (int i = 0; i < 5; i++) {
    if (finish[i]==false && R[i][0]<=work[0]&&R[i][1]<=work[1]&&R[i][2]<=work[2]){
      work[0] += C[i][0];
      work[1] += C[i][1];
      work[2] += C[i][2];
      finish[i] = true;
    }
  }
  }
  bool deadlock = false;
  for (int k = 0; k < 5; k++) {
    if (finish[k]==false) {
      deadlock = true;
      fprintf(output,"Process %d is in a deadlock\n",k+1);
    }
  }
  if(deadlock==0){
   fprintf(output,"No deadlock is detected");
 }
 fclose(mf);
 fclose(output);


  return 0;
}
