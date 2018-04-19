#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VAL_RANGE 500 

void mergeSort(int *,int ,int );
void merge(int *,int,int);
void printArray(int *,int);
void fillArray(int *,int);

int main(){
     int arr_size;
     int *x;
     srand(time(NULL));
     printf("Enter the size of the array to sort:: ");
     scanf("%d",&arr_size);

     x = (int *)malloc(sizeof(int) * arr_size);
     fillArray(x,arr_size);
     printf("\n The array to be sorted is :: \n");
     printArray(x,arr_size);

     mergeSort(x,0,arr_size-1);
     printf("The sorted array is ::: \n");
     printArray(x,arr_size);
     free(x);
     return 0;
}

void mergeSort(int *x, int left, int right){
     int middle = (left+right)/2;
     if ( right - left > 0 ){
          mergeSort(x,left,middle);
          mergeSort(x,middle+1,right);
          merge(x,left,right);
     }
}

void merge(int *x, int left, int right){
     int *l,*r;
     int middle = ( left + right ) / 2;
     int lsize = (middle + 1)-left, rsize = ( right - middle );
     int i,j,k=left;
     l = (int *)malloc(sizeof(int)*lsize);
     r = (int *)malloc(sizeof(int)*rsize);
     for ( i = 0; i < lsize ; i++ )
         l[i] = x[k++];
     for ( j = 0; j < rsize ; j++ )
        r[j] = x[k++];
     for ( i = left,j = 0,k=0; j < lsize && k < rsize ;i++ ){
          if ( l[j] < r[k] )
               x[i] = l[j++];
          else
               x[i] = r[k++];
     }
     while ( j != lsize )
          x[i++] = l[j++];
     while ( k != rsize )
          x[i++] = r[k++];
     free(l);
     free(r);     
       
}

void fillArray(int *x, int arr_size ){
     int i;
     for ( i = 0; i < arr_size ; i++)
          x[i] = rand()%VAL_RANGE;
}


void printArray(int *x, int arr_size ){
     int i;
     for ( i = 0; i < arr_size ; i++)
          printf("%d ",x[i]);
     putchar('\n');
}










