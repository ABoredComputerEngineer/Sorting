//IMPLEMENTATION OF THE SELECTION SORT IN C

#include <stdio.h>
#define MAXLENGTH 100
#define LONGLINE printf("----------------------------------------------------------------\n")
#define TRUE 1
#define FALSE 0

void insertionSort(int [],int);
void printArray(int [], int);
int checkSort(int [],int);
void swap(int *,int *);

void main(){
	int x[MAXLENGTH],i=0,c;
	printf("Enter numbers ....  ENTER ANY OTHER CHARACTER TO EXIT \n ");
	while ( (c=scanf("%d",&x[i++])) != 0 ); // TAKES INPUT FROM THE USER
	printf("Initial Array:::: \n");
	printArray(x,i-1);
	LONGLINE;
	insertionSort(x,--i); //--i IS  USED TO DECREASE THE LENGTH AS AN EXTRA CHARACTER IS ADDED IN DUE TO THE LOOP
	LONGLINE;
	printArray(x,i);
}

void insertionSort(int a[],int length){
	int i,j,temp,min,minIndex;

	for( i = 0;i<length;i++)		//PRINTS THE UPPER MENU OF INDEXES
		printf("Index %d|",i);
	printf("\n");

	for ( i = 0 ; i<length-1 ; i++ ){
		min = a[i];
		LONGLINE;
			if ( checkSort(a,length) == TRUE ) // CHECK IF SORTED BEFORE EACH SWAP
				return;
		for ( j = i+1;j<length;j++){
			if ( a[j] < min ){
				minIndex = j;
				min = a[j];
			}
		}
		swap(&a[i],&a[minIndex]);
		printArray(a,length);  //PRINTS THE ARRAY
	}
}

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printArray(int x[],int length){
	int i;
	printf("\n");
	for ( i = 0; i<length; i++)
		printf("%7d|",x[i]);
	printf("\n");
}

int checkSort(int x[],int length){
	int i = 0;
	for ( i = 0; i<length-1;i++){
		if (x[i]>x[i+1])
			return FALSE; 
	}
	return TRUE;
}