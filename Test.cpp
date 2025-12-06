#include <iostream>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;


//Bubble Sort
void bubbleSort(int* arr1, int N) {
    for (int i = (N - 1); i > 0; i--) {
        for (int n = 0; n < i; n++) {
            if (arr1[n] > arr1[n + 1])
                swap(arr1[n], arr1[n + 1]);
        }
    }
    
}


//Shaker Sort
void shakerSort(int* arr2, int N) {
    int left = 0, right = N - 1;
    while (left <= right) {
        for (int i = left; i < right; ++i)
        {
            if (arr2[i] > arr2[i + 1])
                swap(arr2[i], arr2[i + 1]);
        }
        --right;

        for (int i = right; i > left; --i)
        {
            if (arr2[i] < arr2[i - 1])
                swap(arr2[i], arr2[i - 1]);
        }
        ++left;
    }
    
}


//Insertion Sort
void insertionSort(int* arr3, int N) {
    for (int i = 1; i < N; ++i) {
        int key = arr3[i];
        int j = i - 1;
        while (j >= 0 && arr3[j] > key) {
            arr3[j + 1] = arr3[j];
            --j;
        }
        arr3[j + 1] = key;
    }
}


//SelectionSort
void selectionSort(int* arr4, int N) {
    for (int i = 0; i < N - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < N; ++j) {
            if (arr4[j] < arr4[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr4[i], arr4[minIdx]);
    }
    
}


//Merge Sort
void merge(int* arr5, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int* left = new int[n1], * right = new int[n2];
    for (int i = 0; i < n1; ++i) left[i] = arr5[l + i];
    for (int j = 0; j < n2; ++j) right[j] = arr5[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) arr5[k++] = left[i++];
        else arr5[k++] = right[j++];
    }
    while (i < n1) arr5[k++] = left[i++];
    while (j < n2) arr5[k++] = right[j++];
    delete[] left;
    delete[] right;
}

void mergeSort(int* arr5, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr5, l, m);
        mergeSort(arr5, m + 1, r);
        merge(arr5, l, m, r);
    }
}

void mergeSortWrapper(int* arr5, int N) {
    mergeSort(arr5, 0, N - 1);
    
}


//Алгоритм бинарного поиска
int binarySearch(int arr1[], int value, int start, int end) {
    if (end >= start) {
        int mid = start + (end - start) / 2;

        if (arr1[mid] == value) {
            return mid;
        }

        if (arr1[mid] > value) {
            return binarySearch(arr1, value, start, mid - 1);
        }

        return binarySearch(arr1, value, mid + 1, end);
    }

    return -1;
}

//Для float
int binarySearch1(int arr1[], float value, int start, int end) {
    if (end >= start) {
        int mid = start + (end - start) / 2;
        float fl = 1;
        float p = arr1[mid] / fl;
        float epsilon = 1e-6f;
        if (abs(p - value) < epsilon) {
            return mid;
        }

        if (abs(p - value) > epsilon) {
            return binarySearch(arr1, value, start, mid - 1);
        }

        return binarySearch(arr1, value, mid + 1, end);
    }

    return -1;
}



int main() {
    
    //1

    const int N = 100;
    int arr[N];

    for (int a = 0; a < N; a++) {
        arr[a] = rand() % 199 - 99;
    };

    for (int a = 0; a < N; a++) {
        cout << arr[a] << " ";
    };
    cout << "\n\n";
    

    //Копии массива для разных сортировок
    int arr1[N];
    for (int a = 0; a < N; a++) {
        arr1[a] = arr[a];
    };
    
    int arr2[N];
    for (int a = 0; a < N; a++) {
        arr2[a] = arr[a];
    };

    int arr3[N];
    for (int a = 0; a < N; a++) {
        arr3[a] = arr[a];
    };
    
    int arr4[N];
    for (int a = 0; a < N; a++) {
        arr4[a] = arr[a];
    };

    int arr5[N];
    for (int a = 0; a < N; a++) {
        arr5[a] = arr[a];
    };



    //2
    /*
    bubbleSort(arr1, N);

    shakerSort(arr2, N);
    
    insertionSort(arr3, N);

    selectionSort(arr4, N);

    mergeSortWrapper(arr5, N);
    */


    //1)
    auto begin = steady_clock::now();
    bubbleSort(arr1, N);
    auto end = steady_clock::now();

    for (int a = 0; a < N; a++) {
        cout << arr1[a] << ' ';
    };
    cout << "\n\n";

    auto time1_ms = duration_cast<microseconds>(end - begin);
    cout << "The time BubbleSort: " << time1_ms.count() << " microseconds\n\n";


    //2)
    begin = steady_clock::now();
    shakerSort(arr2, N);
    end = steady_clock::now();

    for (int a = 0; a < N; a++) {
        cout << arr2[a] << ' ';
    };
    cout << "\n\n";

    auto time2_ms = duration_cast<microseconds>(end - begin);
    cout << "The time ShakerSort: " << time2_ms.count() << " microseconds\n\n";


    //3)
    begin = steady_clock::now();
    insertionSort(arr3, N);
    end = steady_clock::now();

    for (int a = 0; a < N; a++) {
        cout << arr3[a] << ' ';
    };
    cout << "\n\n";

    auto time3_ms = duration_cast<microseconds>(end - begin);
    cout << "The time InsertionSort: " << time3_ms.count() << " microseconds\n\n";


    //4)
    begin = steady_clock::now();
    selectionSort(arr4, N);
    end = steady_clock::now();

    for (int a = 0; a < N; a++) {
        cout << arr4[a] << ' ';
    };
    cout << "\n\n";

    auto time4_ms = duration_cast<microseconds>(end - begin);
    cout << "The time SelectionSort: " << time4_ms.count() << " microseconds\n\n";


    //5)
    begin = steady_clock::now();
    mergeSortWrapper(arr5, N);
    end = steady_clock::now();

    for (int a = 0; a < N; a++) {
        cout << arr5[a] << ' ';
    };
    cout << "\n\n";

    auto time5_ms = duration_cast<microseconds>(end - begin);
    cout << "The time MergeSort: " << time5_ms.count() << " microseconds\n\n";


    
    //3

    //Неотсортированный:
    // Поиск максимального элемента
    begin = steady_clock::now();
    int max = arr[0];
    for (int j = 1; j < N; ++j) {
        if (arr[j] > max) {
            max = arr[j];
        }
    }
    end = steady_clock::now();
    cout << "UnsortedMax: " << max << "\n";
    auto timeUnsortedMax = duration_cast<nanoseconds>(end - begin);
    cout << "The time UnsortedMax: " << timeUnsortedMax.count() << " nanoseconds\n\n";

    // Поиск минимального элемента
    begin = steady_clock::now();
    int min = arr[0];
    for (int j = 1; j < N; ++j) {
        if (arr[j] < min) {
            min = arr[j];
        }
    }
    end = steady_clock::now();
    cout << "UnsortedMin: " << min << "\n";
    auto timeUnsortedMin = duration_cast<nanoseconds>(end - begin);
    cout << "The time UnsortedMin: " << timeUnsortedMin.count() << " nanoseconds\n\n";

    //Отсортированный:
    // Поиск максимального элемента
    begin = steady_clock::now();
    int maxS = arr1[N-1];
    end = steady_clock::now();
    cout << "SortedMax: " << maxS << "\n";
    auto timeSortedMax = duration_cast<nanoseconds>(end - begin);
    cout << "The time SortedMax: " << timeSortedMax.count() << " nanoseconds\n\n";

    // Поиск минимального элемента
    begin = steady_clock::now();
    int minS = arr1[0];
    end = steady_clock::now();
    cout << "SortedMin: " << minS << "\n";
    auto timeSortedMin = duration_cast<nanoseconds>(end - begin);
    cout << "The time SortedMin: " << timeSortedMin.count() << " nanoseconds\n\n";



    //4
    
    //Неотсортированный:
    begin = steady_clock::now();
    float f = 2;
    float UnsortedSr = (max + min)/f;
    cout << "UnsortedSr: " << UnsortedSr << "\n";
    int k = 0;
    cout << "indices of elements = UnsortedSr: ";
    for (int i = 0; i < N; i++) {
        if (UnsortedSr == arr[i]) {
            cout << i << " ";
            k++;
        }
    }
    if (k == 0) {
        cout << "0";
    }
    cout << "\nNumber of elements = UnsortedSr: " << k;
    end = steady_clock::now();
    
    auto timeUnsortedSr = duration_cast<microseconds>(end - begin);
    cout << "\nThe time UnsortedSr: " << timeUnsortedSr.count() << " microseconds\n\n";

    //Через бинарный поиск сделать так, чтобы в отсорт. не перебирать все
    //Oтсортированный:
    begin = steady_clock::now();
    float SortedSr = (maxS + minS) / f;
    cout << "SortedSr: " << SortedSr << "\n";
     
    int result4 = binarySearch1(arr1, SortedSr, 0, N - 1);
    if (result4 == -1) {
        cout << "indices of elements = SortedSr: 0" << endl << "Number of elements = SortedSr: 0" << endl;
    }
    else {
        k = 1;
        cout << "indices of elements = SortedSr: ";
        for (int h = 1; arr1[result4 - h] == arr1[result4]; h++) {
            cout << result4 - h << " ";
            k++;
        }
        cout << result4 << " ";
        for (int h = 1; arr1[result4 + h] == arr1[result4]; h++) {
            cout << result4 + h << " ";
            k++;
        }
        cout << endl << "Number of elements = SortedSr: " << k << endl;
    }
    end = steady_clock::now();

    auto timeSortedSr = duration_cast<microseconds>(end - begin);
    cout << "The time SortedSr: " << timeSortedSr.count() << " microseconds\n\n";
    //binarySearch(int arr1[], int value, int start, int end)


    //5
    int a;
    cout << "Enter a number a (from -99 to 99) ";
    cin >> a;
    k = 0;
    int t = 0;
    while ((arr1[t] < a) && (t < N)) {
        k++;
        t++;
    }
    cout << k << "\n\n";



    //6
    int b;
    cout << "Enter a number b (from -99 to 99) ";
    cin >> b;
    k = 0;
    t = N - 1;
    while ((arr1[t] > a) && (t >= 0)) {
        k++;
        t--;
    }
    cout << k << "\n\n";
    
    
    

    //7
    int value;
    cout << "Enter a number (from -99 to 99) ";
    cin >> value;

    begin = steady_clock::now();
    int result = binarySearch(arr1, value, 0, N - 1);
    if (result == -1) {
        cout << "Item not found" << endl;
    }
    else {
        cout << "The item is in position " << result << endl;
    }
    end = steady_clock::now();
    auto timeSearchBin = duration_cast<microseconds>(end - begin);
    cout << "The time SearchBin: " << timeSearchBin.count() << " microseconds\n\n";

    
    begin = steady_clock::now();
    for (int i = 0; i < N; i++) {
        if (arr1[i] == value) {
            cout << "The item is in position " << i << endl;
            break;
        }
        if (i == N - 1)
            cout << "Item not found" << endl;
    }
    end = steady_clock::now();
    auto timeSearch = duration_cast<microseconds>(end - begin);
    cout << "The time Search: " << timeSearch.count() << " microseconds\n\n";



    //8
    int n1, n2;
    cout << "Enter a number 1 (from -99 to 99) ";
    cin >> n1;
    cout << "Enter a number 2 (from -99 to 99) ";
    cin >> n2;
    begin = steady_clock::now();
    swap(arr[n1], arr[n2]);
    end = steady_clock::now();
    for (int a = 0; a < N; a++) {
        cout << arr[a] << ' ';
    };
    cout << "\n";
    auto timeSwap = duration_cast<nanoseconds>(end - begin);
    cout << "The time Swap: " << timeSwap.count() << " nanoseconds\n\n";
    


    //18 ИДЗ
    int u = 0, d = 0;
    int arrU[N], arrD[N];
    for (int a = 0; a < N; a++) {
        arrD[a] = 0;
    };
    for (int a = 0; a < N; a++) {
        arrU[a] = 0;
    };
    for (int i = 0; i < N; i++) {
        if (arr1[i] == arr1[i + 1]) {
            arrD[d] = arr1[i];
            arrD[d + 1] = arr1[i + 1];
            d += 2;
            i++;
        }
        else if (i > 0 && arr1[i] == arr1[i - 1]) {
            arrD[d] = arr1[i];
            d++;
        }
        else {
            arrU[u] = arr1[i];
            u++;
        }
    }
    for (int a = 0; a < N; a++) {
        cout << arrD[a] << ' ';
    };
    cout << "\n\n";
    for (int a = 0; a < N; a++) {
        cout << arrU[a] << ' ';
    };
    cout << "\n\n";
    

    return 0;
}
