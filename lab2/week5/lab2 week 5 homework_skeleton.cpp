/*
::: SourceCode CopyRight @ Yongil Kim
::: Apr.2020 SNU MiLab
::: miles94@snu.ac.kr
*/
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

class arr {
public:
	arr();
	~arr();
	void sort(void (*f)(int*, unsigned int));
	void sort(void(*f)(int*, int, int));
	void init(int n);
	void reset();
	void check();
private:
	int* input_array;
	int* ref_array;
	int size;
};
void swap(int& a, int& b);
void bubble_sort(int* array, unsigned int size);
void insertion_sort(int* array, unsigned int size);
void selection_sort(int* array, unsigned int size);

int main(void) {
	srand((unsigned int)time(NULL));

	int size;
	clock_t start, end;
	double passed_time;
	cout << "Give me the size : ";
	cin >> size;
	arr mysort;
	mysort.init(size);

	cout << "Bubble Sort : ";
	start = clock();
	mysort.sort(bubble_sort);
	end = clock();
	passed_time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%.3f(s) & ", passed_time);
	mysort.check();
	mysort.reset();

	cout << "Insertion Sort : ";
	start = clock();
	mysort.sort(insertion_sort);
	end = clock();
	passed_time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%.3f(s) & ", passed_time);
	mysort.check();
	mysort.reset();

	cout << "Selection Sort : ";
	start = clock();
	mysort.sort(selection_sort);
	end = clock();
	passed_time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%.3f(s) & ", passed_time);
	mysort.check();
	mysort.reset();

	return 0;
}


arr::arr() {}
arr::~arr() {
	delete[] input_array;
	delete[] ref_array;
}

void arr::init(int size) {
	this->size = size;
	input_array = new int[size];
	ref_array = new int[size];
	for (int i = 0; i < size; i++) {
		int rnd_num = (int)(rand() % 1000);
		input_array[i] = rnd_num;
		ref_array[i] = rnd_num;
	}
}

void arr::reset() {
	if (ref_array == nullptr) ref_array = new int[size];
	for (int i = 0; i < size; i++)
		ref_array[i] = input_array[i];
	cout << "Reset" << endl << endl;

}

void arr::check() {
	bool check = true;
	if (ref_array == nullptr)
		cout << "Error! The array has no element." << endl;
	else {
		for (int i = 0; i < size - 1; i++) {
			if (ref_array[i] < ref_array[i + 1])
				check = false;
		}
	}
	if (check) cout << "Correct!" << endl;
	else cout << "Wrong!" << endl;
}

void arr::sort(void(*f)(int*, unsigned int)) {
	f(ref_array, size);
}

void arr::sort(void(*f)(int*, int, int)) {
	f(ref_array, 0, (int)(size - 1));
}

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

/*###################################################################################
##########################  Incremental Algorithm ###################################
#####################################################################################
*/

void bubble_sort(int* array, unsigned int size) {
	for (unsigned int i = 0; i < size - 1; i++)
		for (unsigned int j = 0; j < size - 1 - i; j++)
		{
			if (array[j] < array[j + 1])
			{
				int tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
			}
		}
}

void insertion_sort(int* array, unsigned int size) {
	for (unsigned int i = 1; i < size; i++)
	{
		int temp = array[i];
		int j = i - 1;
		while(1)
		{
            if(j<0) break;
            if(array[j] < temp){
                array[j+1] = array[j];
                j--;
            }
            else{
                break;
            }
		}
		array[j + 1] = temp;
	}
}

void selection_sort(int* array, unsigned int size) {
	for (unsigned int i = 0; i < size - 1; i++)
	{
		int max = array[i];
		int max_idx = i;
		for (unsigned int j = i + 1; j < size; j++)
		{
            if(max < array[j]){
                max = array[j];
                max_idx = j;
            }
		}
		swap(array[i], array[max_idx]);
	}
}