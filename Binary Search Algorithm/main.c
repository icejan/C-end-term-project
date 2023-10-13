#include <stdio.h>
#define SIZE_OF_ARRAY 10 
#define TRUE 1
#define FALSE 0
#define NOT_FOUND -1

int binary_srch(const int search_array[], int target, int size);  

int main(void) {
  
  int target, index, num[10] = {1,3,5,6,12,63,78,95,101,130};
  char ans = 'y';

  do{

  printf("Please enter the number you would like to search the array for: \n");
  scanf("%d", &target);
  
  index = binary_srch(num, target, SIZE_OF_ARRAY);

  if(index == TRUE){
    printf("%d was found. \n", target);
  }

  else{
    printf("%d was not found. \n", target);
  }
  
  printf("Do you want to search for another number? (Enter y for yes and n for no) \n");
  scanf(" %c", &ans);
  
  }while(ans == 'y');
  
  return 0;
}

int binary_srch(const int search_array[], int target, int size){
  
  int top, bottom, middle, found;
  bottom = 0;
  top = size - 1;
  found = FALSE;
  		
	middle = (top+bottom)/2;

   while(bottom <= top)
    {
        if(search_array[middle] < target)
            bottom = middle+1;
            
        else if(search_array[middle]==target)
        {
			found = TRUE;
            return found;
        }
        else
            top = middle-1;
        middle = (bottom+top)/2;
    }

 found = NOT_FOUND;
 
return found;
  
} 