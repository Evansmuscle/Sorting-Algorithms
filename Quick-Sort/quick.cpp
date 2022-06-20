#include <iostream>
#include <vector>

using namespace std;

int getSize(vector<double> arr) {
    size_t size = sizeof(arr) / sizeof(arr[0]);
    
    int sizeInt = static_cast<int>(size);
    
    return sizeInt;
}

class QuickSort {
    private:
        void swap(vector<double> elements, int firstIdx, int secondIdx) {
            double temp = elements[secondIdx];
            elements[secondIdx] = elements[firstIdx];
            elements[firstIdx] = temp;
        }

        bool partitioned;
        
    public:
        QuickSort() {
            partitioned = false;
        }

        void sort(vector<double> array, int pivot, int start, int end) {
            if (array[pivot] == array[start] && array[pivot] == array[end] && !partitioned)
            {
                partitioned = true;
                
                sort(array, 0, 0, pivot - 1);
                sort(array, pivot + 1, pivot + 1, getSize(array) - 1);
            }

            if (array[pivot] == array[start])
            {
                if (array[pivot] < array[end])
                {
                    sort(array, pivot, start, end - 1);
                }
                
                if (array[pivot] > array[end])
                {
                    swap(array, pivot, end);
                    sort(array, pivot, start, end);
                }
                
                return;
            }
            
            if (array[pivot] == array[end])
            {
                if (array[pivot] > array[start])
                {
                    sort(array, pivot, start + 1, end);
                }
                
                if (array[pivot] < array[start])
                {
                    swap(array, pivot, start);
                    sort(array, pivot, start, end);
                }

                return;
            }
            
            return;
        };
};

int main(int argc, char const *argv[])
{
    vector<double> array = {1, 3, 5, 6, 7, 8, 10, 2, 4, 6};
    
    QuickSort sorter;
    sorter.sort(array, 0, 0, getSize(array) - 1);

    
    for (int i = 0; i < getSize(array); i++)
    {
        cout << array[i] << endl;
    }

    return 0;
}
