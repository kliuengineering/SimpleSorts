//
//  main.cpp
//  SimpleSorts
//
//  Created by Kevin Liu on 2024-02-17.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <ctime>

template <typename T>
void Swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

template <typename T>
void BubbleSort(std::vector<T> &array, const int &SIZE)
{
    int i, j;
    
    for(i = 0; i < SIZE-1; i++)
    {
        for(j = 0; j < SIZE-1-i; j++)
        {
            int next = j+1;
            if(array[next] < array[j])
                Swap(array[next], array[j]);
        }
    }
}

template <typename T>
void InsertionSort(std::vector<T> &array, const int &SIZE)
{
    int i, j, current;
    for(i = 1; i < SIZE; i++)
    {
        current = array[i];
        for(j = i; j > 0 && array[j-1] > current; j--)
        {
            array[j] = array[j-1];
        }
        array[j] = current;
    }
}

template <typename T>
void SelectionSort(std::vector<T> &array, const int &SIZE)
{
    int i, j, min;
    for(i = 0; i < SIZE-1; i++)
    {
        min = i;
        for(j = i+1; j < SIZE; j++)
        {
            if(array[j] < array[min])
                min = j;
        }
        if(min != i)
            Swap(array[i], array[min]);
    }
}

template <typename T>
void PopulateArray(std::vector<T> &array, const int &SIZE)
{
    array.clear();
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    for(int i = 0; i < SIZE; i++)
    {
        T value = static_cast<T>(std::rand() % 200-100);
        array.push_back(value);
    }
}

template <typename T>
void Print(std::vector<T> &array)
{
    for(typename std::vector<T>::iterator itr = array.begin(); itr != array.end(); itr++)
    {
        std::cout << *itr << "  ";
    }
    puts("");
}

int main(int argc, const char * argv[]) 
{
    
    std::vector<int> array;
    const int SIZE = 20;
    
    std::cout << "Unsorted array: \n";
    PopulateArray(array, SIZE);
    Print(array);
    puts("");
    
    std::cout << "Bubble Sort Result: \n";
    BubbleSort(array, SIZE);
    Print(array);
    array.clear();
    puts("");
  
    std::cout << "Unsorted array: \n";
    PopulateArray(array, SIZE);
    Print(array);
    puts("");
    
    std::cout << "Insertion Sort Result: \n";
    InsertionSort(array, SIZE);
    Print(array);
    array.clear();
    puts("");
    
    std::cout << "Unsorted array: \n";
    PopulateArray(array, SIZE);
    Print(array);
    puts("");
    
    std::cout << "Selection Sort Result: \n";
    SelectionSort(array, SIZE);
    Print(array);
    array.clear();
    puts("");
    
    puts("");
    return 0;
}
