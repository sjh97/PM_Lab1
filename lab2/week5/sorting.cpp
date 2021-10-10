#include <iostream>
using namespace std;

void bubble_sort(int* array, unsigned int size){
    for(unsigned int i=0;i<size-1;i++){
        for(unsigned int j=0;j<size-1-i;j++){
            if(array[j] > array[j+1]){
                int tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
}

void insertion_sort(int* array, unsigned int size){
    for(unsigned int i = 1; i < size;i++){
        int temp = array[i];
        int j = i - 1;
        while (1)
        {
            if(j<0) break;
            if(array[j] > temp){
                array[j+1] = array[j];
                j--;
            }
            else{
                break;
            }
            
        }
        array[j+1] = temp;
        
    }
}

void selection_sort(int* array, unsigned int size){
    for(unsigned int i=0;i<size-1;i++){
        int min = array[i];
        int min_idx = i;
        for(unsigned int j = i+1;j<size;j++){
            if(min > array[j]){
                min = array[j];
                min_idx = j;
            }
        }
        int temp = array[i];
        array[i] = array[min_idx];
        array[min_idx] = temp;
    }
}

int main(){

    int arr[9] = {54,26,93,17,77,31,44,55,20};

    //bubble_sort(arr,9);
    // insertion_sort(arr,9);
    selection_sort(arr,9);

    for(int i=0;i<9;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

}