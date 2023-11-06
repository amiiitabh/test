#include<stdio.h>
int max_num (int a[], int n){
   int max = a[0];
   for (int i = 1; i < n; i++)
      if (a[i] > max)
         max = a[i];
   return max;
}
void radix_sort (int a[], int n){
   int bucket[10][10], bucket_cnt[10];
   int i, j, k, r, NOP = 0, divisor = 1, largest_number, pass;
   largest_number = max_num (a, n);
   while (largest_number > 0){
      NOP++;
      largest_number /= 10;
   }
   for (pass = 0; pass < NOP; pass++){
      for (i = 0; i < 10; i++){
         bucket_cnt[i] = 0;
      }
      for (i = 0; i < n; i++){
         r = (a[i] / divisor) % 10;
         bucket[r][bucket_cnt[r]] = a[i];
         bucket_cnt[r] += 1;
      }
      i = 0;
      for (k = 0; k < 10; k++){
         for (j = 0; j < bucket_cnt[k]; j++){
            a[i] = bucket[k][j];
            i++;
         }
      }
      divisor *= 10;
      printf ("After pass %d :", pass + 1);
      for (i = 0; i < n; i++)
         printf ("%d ", a[i]);
      printf ("\n");
   }
}
int main (){
   int i, n, a[10];
   printf ("Enter the number of items in Array: ");
   scanf ("%d", &n);
   
   for (i = 0; i < n; i++){
     printf ("Enter the %d item: ",i);
      scanf ("%d", &a[i]);
   }
   radix_sort (a, n);
   printf ("Sorted items : ");
   for (i = 0; i < n; i++)
      printf ("%d ", a[i]);
   printf ("");
   return 0;
}