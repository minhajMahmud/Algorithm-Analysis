#include<stdio.h>
#include<algorithm> // For std::max
using namespace std;

void knapSack(int W, int n, int val[], int wt[]);

int main(void) {

  int val[] = {-1, 100, 20, 60, 40};  // value of the items
  int wt[] = {-1, 3, 2, 4, 1};        // weight of the items
  
  int n = 4;  // total items
  int W = 5;  // capacity of knapsack
  
  knapSack(W, n, val, wt);

  return 0;
}

void knapSack(int W, int n, int val[], int wt[]) {
  int i, w;

  int V[n+1][W+1];

  // Initialize the table
  for(w = 0; w <= W; w++) {
    V[0][w] = 0;
  }
  for(i = 0; i <= n; i++) {
    V[i][0] = 0;
  }

  // Fill the table
  for(i = 1; i <= n; i++) {
    for(w = 1; w <= W; w++) {
      if(wt[i] <= w) {
        V[i][w] = max(V[i-1][w], val[i] + V[i-1][w - wt[i]]);
      } else {
        V[i][w] = V[i-1][w];
      }
    }
  }

  printf("Max Value: %d\n", V[n][W]);
}
