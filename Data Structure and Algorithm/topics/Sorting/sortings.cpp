#include <iostream>
#include <deque>
#include <random>
#include <ctime>
//#define N 10
using namespace std;
void swap(int &a, int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
//bubble sort
void bubble_sort(int *array, int n)
{
    for(int i=0; i<n-1; i++)
        for(int j=0; j < n-i; j++)
    {
        if(array[j] > array[j+1])
            swap(array[j], array[j+1]);
    }
}
//selection sort
void selection_sort(int *array, int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min = array[i+1];
        int k=i+1;
        for(int j = i+1; j<n; j++)
        {
            if(array[j]<min)
            {
                min = array[j];
                k = j;
            }
        }
        swap(array[i] , array[k]);
    }
}

//insertion sort
void insertion_sort(int *array, int n)
{
    for(int i=1; i<n; i++)
    {
        int temp = array[i];
        for(int j = i-1; j>=0; j--)
        {

            if(array[j]>temp)
            {
                array[j+1] = array[j];
                if(j ==0)
                {
                    array[0] = temp;
                    break;
                }
            }
            if(array[j]<=temp)
            {
                array[j+1] = temp;
                break;
            }
        }
    }
}
//merging sort
void merging(int *array, int low, int  mid, int high)
{
//    cout<<"low"<<low<<endl;
//    cout<<"mid"<<mid<<endl;
//    cout<<"high"<<high<<endl;
    int i = low;
    int j = mid;
    int k = 0;
    int* array_reserved = new int[high-low];  //use a temporary array in each merging operation.
    while(i<mid && j<high)
    {
        if(array[i] <= array[j])
        {
            array_reserved[k] =array[i];
            i++;
            k++;
        }
        else
        {
            array_reserved[k] = array[j];
            j++;
            k++;
        }
    }
    while(j<high)
    {
        array_reserved[k] = array[j];
        k++;
        j++;
    }
    while(i<mid)
    {
        array_reserved[k] = array[i];
        i++;
        k++;
    }
    for(k=0; k<high-low; k++)
    {
        array[k+low] = array_reserved[k];
    }
    delete [] array_reserved;
}
void merging_sort(int *array, int i, int j) //[i, j)
{
    if(i == j-1)
        return;
    int m=(i+j)/2;
    merging_sort(array, i, m);
    merging_sort(array, m, j);
    merging(array, i, m, j);
}
//heap sort
void heap_adjust(int *array, int parent, int n)
{
    int child = 2*parent+1;  //first get left child
    while(child < n) //when child >=n, the parent is the lowest level
    {
        if(2*parent+2<n)
        {
            if(array[2*parent+1]<array[2*parent+2])  //child to be the largest one between lchild and rchild
                child = 2* parent +2;
        }
        if(array[parent]<array[child])  //if parent < largest child, then swap them
        {
            swap(array[parent], array[child]);
        }
        else                        //else, no need to adjust on this node
            break;
        parent = child;  // go deeper
        child = parent*2+1;
    }
}
void heap_sort(int *array, int n)
{
    //construct a big top heap
    for(int i = n/2; i>=0; i--)
    {
        heap_adjust(array, i, n);
    }
    //sort
    for(int i = n-1; i>=0; i--)
    {
        swap(array[0] , array[i]);
        heap_adjust(array, 0, i);
    }
}

//quick sort
int quick_sort_component(int *array, int low, int high)
{
    int i = low, j = high-1;
    int key = array[low];
    while(i<j)
    {
        while(array[j] >=key&& i<j)
        {
            j--;
        }
        if(i<j)
        {
            array[i] = array[j];
            i++;
        }
        while(array[i] <=key&& i<j)
        {
            i++;
        }
        if(i<j)
        {
            array[j] = array[i];
            j--;
        }
    }
    array[i] = key;
    return i;
}
void quick_sort(int * array, int low, int high)
{
    if(low<high)
    {
        int pivot = quick_sort_component(array, low, high);
        quick_sort(array, low, pivot);
        quick_sort(array,pivot+1, high);
    }

}
//bucket sort
int get_digit(int number, int digit)
{
    int mod;
    for(int i=0; i<digit+1; i++)
    {
        mod = number%10;
        number /= 10;
    }
    return mod;
}
void bucket_sort(int *array, int n, int digit)
{
    int radix = 10;
    deque<int> *queues = new deque<int> [radix];
    for(int i=0; i<digit; i++)
    {
        int j = 0;
        for(j=0; j<n; j++)
        {
            queues[get_digit(array[j], i)].push_back(array[j]);
        }
        j=0;
        for(int k=0; k<radix; k++)
        {
            while(!queues[k].empty())
            {
                array[j++] = queues[k].front();
                queues[k].pop_front();
            }
        }
    }
    delete[] queues;

}
void generator(int *array, int n)
{
    static default_random_engine engine(time(0));
    static uniform_int_distribution<unsigned> distributor(0,200);
    for(int i=0; i<n; i++)
    {
        array[i] = distributor(engine);
    }
}
void show_array(int *array, int N)
{
    for(int i=0; i<N; i++)
        cout<<array[i]<<' ';
    cout<<endl;
}
int main()
{
    //int array[N] = {7, 1, 42, 10, 4, 36, 7, 29, 105, 1};
    int N = 20;
    int *array = new int [N];

    cout<<"-------------------------insertion_sort------------------------"<<endl;
    generator(array, N);
    insertion_sort(array, N);
    show_array(array, N);

    cout<<"-------------------------selection_sort------------------------"<<endl;
    generator(array, N);
    selection_sort(array, N);
    show_array(array, N);

    cout<<"-------------------------bubble_sort------------------------"<<endl;
    generator(array, N);
    bubble_sort(array, N);
    show_array(array, N);

    cout<<"-------------------------heap_sort------------------------"<<endl;
    generator(array, N);
    heap_sort(array, N);
    show_array(array, N);

    cout<<"-------------------------merging_sort------------------------"<<endl;
    generator(array, N);
    merging_sort(array, 0, N);
    show_array(array, N);

    cout<<"-------------------------quick_sort------------------------"<<endl;
    generator(array, N);
    quick_sort(array, 0, N);
    show_array(array, N);

    cout<<"-------------------------bucket_sort------------------------"<<endl;
    generator(array, N);
    bucket_sort(array, N, 3);
    show_array(array, N);

    delete[] array;
    return 0;
}

