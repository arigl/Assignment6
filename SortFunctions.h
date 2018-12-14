#include <iostream>
#include <fstream>
using namespace std;

class Sort
{
public:
  void selectionSort(double arr[], int n);
  void insertSort(double arr[]);
  void bubbleSort(double myArray[]);
  void quickSort(double arr[], int low, int high);

  void swap(double a, double b);
  int partition (double arr[], int low, int high);
  void mainSort(string name);
};

void Sort::quickSort(double arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void Sort::swap(double a, double b)
{
    double t = a;
    a = b;
    b = t;
}

int Sort::partition (double arr[], int low, int high)
{
    double pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void Sort::insertSort(double arr[]){
  for (int j = 1; j < 10; ++j){
    double temp = arr[j];
    int k = j;
    while (k > 0 && arr[k-1] >= temp)
    {
      arr[k] = arr[k-1];
      --k;
    }
    arr[k] = temp;
  }
}

void Sort::bubbleSort(double myArray[])
{
  for (int i; i < 10; ++i){
    int temp = 0;
    for (int j = 1; j < 9; ++j){
      if (myArray[j] > myArray[j+1]){
        temp = myArray[j+1];
        myArray[j+1] = myArray[j];
        myArray[j] = temp;
      }
    }
  }
}

void Sort::selectionSort(double arr[], int n){
  int i, j, minIndex, tmp;

  for (i = 0; i < n-1; i++){
    minIndex = i;
    for (j = i + 1; j < n; j++){
      if (arr[j] < arr[minIndex])
        minIndex = j;
    }
    if (minIndex != i){
      tmp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = tmp;
    }
  }
}
/*
void mergeSort(int[] a, int lo, int hi){
  if (lo<hi){
    m = (lo + hi) / 2;
    mergeSort (a, lo, m);
    mergeSort (a, m+1, hi);
    merge (a, lo, hi);
  }
}

void merge(int[] a, int lo, int hi){
  int i, j, k, m, n=hi-lo+1;
  int[] b = new int[n];

  k = 0;
  m = (lo+hi)/2;
  // copy lower half to array b

  for (i=lo; i<= m; i++){
    b[k++]=a[i];
  }
  for (j=hi; j>=m+1; j--){
    b[k++]=a[j];
  }

  i=0;j=n-1;k=lo;

  //copy back next-greatest element at each time
  //until i and j cross

  while (i<=j){
    if (b[i]<=b[j]){
      a[k++]=b[i++];
    }
    else{
      a[k++]=b[j--]
    }
  }
}
*/

void Sort::mainSort(string file)
{
  ifstream myFile;
  int length;
  double data;
  string line;

  myFile.open(file);

  if (!myFile) {
    cerr << "Unable to open file " << file << endl;;
    exit(1);
  }

  getline(myFile, line);

  double *temp = new double[length];
  double *quickArr = new double[length];
  double *insertArr = new double[length];
  double *bubbleArr = new double[length];
  double *selectionArr = new double[length];

  for( std::string line; getline( myFile, line ); )
  {
    for (int i = 0; i < line.length(); i++)
    {
      getline(myFile, line);
      data = atof(line.c_str());

      temp[i] = data;
    }
  }

  quickArr = temp;
  insertArr = temp;
  bubbleArr = temp;
  selectionArr = temp;

  myFile.close();

  // cout time start
  quickSort(quickArr, 0, length - 1);
  // cout time end + name

  // cout time start
  insertSort(insertArr);
  // cout time end + name

  // cout time start
  bubbleSort(bubbleArr);
  // cout time end + name

  // cout time start
  selectionSort(selectionArr, length);
  // cout time end + name

  cout << "Done" << endl;
}

int main(int argc, char** argv)
{
  Sort s;
  string file;

  file = argv[1];
  s.mainSort(file);
}
