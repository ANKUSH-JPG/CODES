#include<stdio.h>
#include <time.h>


void generate_random(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	a[i]=rand()%100;
}
void merge_sort(int i, int j, int a[], int aux[]) {
    if (j <= i) {
        return;
    }
    int mid = (i + j) / 2;



    merge_sort(i, mid, a, aux);
    merge_sort(mid + 1, j, a, aux);

    int pointer_left = i;
    int pointer_right = mid + 1;
    int k;

    for (k = i; k <= j; k++) {
        if (pointer_left == mid + 1) {
            aux[k] = a[pointer_right];
            pointer_right++;
        } else if (pointer_right == j + 1) {
            aux[k] = a[pointer_left];
            pointer_left++;
        } else if (a[pointer_left] < a[pointer_right]) {
            aux[k] = a[pointer_left];
            pointer_left++;
        } else {
            aux[k] = a[pointer_right];
            pointer_right++;
        }
    }

    for (k = i; k <= j; k++) {
        a[k] = aux[k];
    }
}


int main() {
   int a[1000], aux[1000],n, i, d, swap;

   printf("Enter number of elements\n");
   scanf("%d", &n);
   generate_random(a,n);

   printf("\n The random array: ");
	for(int i=0;i<n;i++)
		printf(" %d ",a[i]);
clock_t t;
    t = clock();
  merge_sort(0, n - 1, a, aux);

  printf("\n Printing the sorted array:\n");

  for (i = 0; i < n; i++)
     printf("%d ", a[i]);
t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    printf("\n merge_sort took %f seconds to execute \n", time_taken);
  return 0;
}
