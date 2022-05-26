// Лабораторная работа №6 (2 семестр) Вариант №2
// 
// Подобрать структуру для хранения данных, над которой будут осуществляться операции поиска. Добавление и удаление не предусмотрены.
//
// Т.к. операции удаления и добавления не предусмотрены я выбрал массив с бинарным поиском, 
// поскольку он проще в реализации, по сравнению с бинарным деревом, занимает меньше оперативной памяти,
// а бинарный поиск по массиву не уступает в скорости работы поиску по бинарному дереву.
//

#include <iostream>
#define N 100

void printArray(int* arr, int count)
{
	for (int i = 0; i < count; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void quickSort(int a, int b, int* x)
{
	if (a >= b) return;
	int m = ((a + b) / 2) + 1;
	int k = x[m];
	int l = a - 1;
	int r = b + 1;
	while (true)
	{
		do l++; while (x[l] < k);
		do r--; while (x[r] > k);
		if (l >= r) break;
		std::swap(x[l], x[r]);
	}
	r = l;
	l = l - 1;
	quickSort(a, l, x);
	quickSort(r, b, x);
}

int binarySearch(int* mass, int left, int right, int key)
{
	if (key < mass[left]) return -1;
	if (key == mass[left]) return left;
	if (key > mass[right]) return -1;

	while (left + 1 < right)
	{
		int middle = (left + right) / 2;
		if (key > mass[middle]) left = middle;
		else right = middle;
	}
	if (mass[right] == key) return right;
	return -1;
}

int main()
{
    srand(time(0));
    int array[N];
    for (int i = 0; i < N; i++) array[i] = rand() % 100;
	printArray(array, N);
	std::cout << std::endl;
    quickSort(0, N-1, array);
	printArray(array, N);
	int key, result;
	std::cout << "search: ";
	std::cin >> key;
	result = binarySearch(array, 0, N - 1, key);
	if (result != -1) std::cout << "position: " << result << " (from 0)" << std::endl;
	else std::cout << "not found" << std::endl;
    return 0;
}