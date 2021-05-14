#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void merge_asc(int numbers[], int temp[], int left, int mid, int right){
	int i, left_end, num_elements, tmp_pos;
	left_end = mid-1;
	tmp_pos = left;
	num_elements = right - left + 1;
	while ((left <= left_end) && (mid <= right)){
		if(numbers[left] <= numbers[mid]){
			temp[tmp_pos] = numbers[left];
			tmp_pos = tmp_pos + 1;
			left = left + 1;	
		}else{
			temp[tmp_pos] = numbers[mid];
			tmp_pos = tmp_pos + 1;
			mid = mid + 1;
		}
	}
	while(left <= left_end){
		temp[tmp_pos] = numbers[left];
		left = left + 1;
		tmp_pos = tmp_pos + 1;
	}
	while(mid <= right){
		temp[tmp_pos] = numbers[mid];
		mid = mid + 1;
		tmp_pos = tmp_pos + 1;
	}
	for(i=0; i<num_elements; i++){
		numbers[right] = temp[right];
		right = right - 1;
	}
}

void merge_sort_asc(int numbers[], int temp[], int left, int right) {
    int mid;
	if(right > left){
		mid = (right + left)/2;
		merge_sort_asc(numbers, temp, left, mid);
		merge_sort_asc(numbers, temp, mid+1, right);
		merge_asc(numbers, temp, left, mid+1, right);
	}
		
} 
 

void merge_desc(int numbers[], int temp[], int left, int mid, int right){
	int right_pos = mid + 1;
	int tmp_pos = left;
	while(left<=mid && right_pos<=right){
		if(numbers[left] >= numbers[right_pos]){
			temp[tmp_pos] = numbers[left];
			tmp_pos = tmp_pos + 1;
			left = left + 1;
		}else{
			temp[tmp_pos] = numbers[right_pos];
			tmp_pos = tmp_pos + 1;
			right_pos = right_pos + 1;
		}
	}
	while(left<=mid){
			temp[tmp_pos] = numbers[left];
			left = left + 1;
			tmp_pos = tmp_pos + 1;
	}
	while(right_pos<=right){
			temp[tmp_pos] = numbers[right_pos];
			tmp_pos = tmp_pos + 1;
			right_pos = right_pos + 1;
	}
}

void merge_sort_desc(int numbers[], int temp[], int left, int right) {
    if (left == right) return; 
    int mid = (left + right)/2;
    merge_sort_desc(numbers, temp, left, mid);
    merge_sort_desc(numbers, temp, mid + 1, right);
    merge_desc(numbers, temp, left,mid, right);
  
  	int i = left;
    while(i <= right)  {
        numbers[i] = temp[i];
        i++;
    }
}

int order_check(int number[],int size){
    int order_asc = 1;
    int i = 0;
    if(number[0]<number[1]){
        while(i < size-1){
            if(number[i]<=number[i+1]){
                order_asc++;
            }
            i++;
        }
        if(size==order_asc){
            return 1;
        }else{
        	return 3;
		}
    }else if(number[0]>number[1]){
    	while(i < size-1){
            if(number[i]>number[i+1]){
                order_asc++;
            }
            i++;
        }
        if(size==order_asc){
            return 2;
        }else{
        	return 3;
		}
	}   
}

int binarySearch_asc(int number[], int left, int right, int data) { 
   if (right >= left){ 
        int mid = left + (right - left)/2; 
        if (number[mid] == data)   
            return mid; 
        if (number[mid] > data)  
            return binarySearch_asc(number, left, mid-1, data); 
        return binarySearch_asc(number, mid+1, right, data); 
   } 
   return -1; 
} 

int binarySearch_desc(int number[], int left, int right, int data) { 
   if (right >= left){ 
        int mid = left + (right - left)/2; 
        if (number[mid] == data)   
            return mid; 
        if (number[mid] > data)  
            return binarySearch_desc(number, mid+1, right, data); 
        return binarySearch_desc(number, left, mid-1, data); 
   } 
   return -1; 
}

void Binary_search(int numbers[],int size, int data){
	int check;
	check = order_check(numbers,size);
	if(check == 1){
		int result = binarySearch_asc(numbers,0,size-1,data);
		if(result== -1){
			printf("no");
		}else{
			printf("%d",result+1);
		}
	}else if(check == 2){
		int result = binarySearch_desc(numbers,0,size-1,data);
		if(result== -1){
			printf("no");
		}else{
			printf("%d",result+1);
		}
	}else{
		int i = 0;
		while(i<size){
			if(numbers[i]==data){
				printf("%d",i+1);
				break;
			}else{
				i++;
			}
		}if(i>=size){
			printf("no");
		}
	}
}

void Sort_by_asc(int numbers[], int temp[], int left, int right){
	int size = right+1;
	merge_sort_asc(numbers,temp,left,right);
	
	int i =0;
    while(i<size){
      printf("%d ",numbers[i]);
      i++;
    }
}

void Sort_by_desc(int numbers[], int temp[], int left, int right){
	int size = right+1;
	merge_sort_desc(numbers,temp,left,right);
	
	int i =0;
    while(i<size){
      printf("%d ",numbers[i]);
      i++;
    }
}


int main(){
	int num;
	int size;
	int data;
	int i = 0;
	scanf("%d", &size);
	int numbers[size];
	int temp[size];
	while (i < size){
		scanf("%d",&numbers[i]) ;
		i++;
	} 
	
	scanf("%d", &num);
	while(num<=3 && num>0){
		if(num == 1){
			scanf("%d", &data);
			Binary_search(numbers,size,data);
			printf("\n");
		}else if(num == 2){
			Sort_by_asc(numbers, temp, 0, size-1);
			printf("\n");			
		}else if(num == 3){
			Sort_by_desc(numbers, temp, 0, size-1);
			printf("\n");
		}
		scanf("%d", &num);
	}if(num == 4){
		return 0;
	}
}
 
