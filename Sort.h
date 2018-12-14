#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

class Sort
{
  public:
    Sort(); // constructor
    ~Sort(); // deconstructor

    void selectionSort(double arr[], int n);
    void insertSort(double arr[]);
    void bubbleSort(double myArray[]);
    void quickSort(double arr[], int low, int high);

    // used for quick sort
    void swap(double a, double b);
    int partition (double arr[], int low, int high);

    // executes all the swaping algorithms
    void mainSort(string name);

    double *temp;
    double *quickArr;
    double *insertArr;
    double *bubbleArr;
    double *selectionArr;

    int length; // stores length of the array
};

Sort::Sort()
{
  // constructor
}

Sort::~Sort()
{
  delete [] temp;
  delete [] quickArr;
  delete [] insertArr;
  delete [] bubbleArr;
  delete [] selectionArr;
}

void Sort::quickSort(double arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1); // recursive function
        quickSort(arr, pi + 1, high); // recursive function
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
  for (int j = 1; j < length; ++j){
    double temp = arr[length];
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
  for (int i; i < length; ++i){
    int temp = 0;
    for (int j = 1; j < length - 1; ++j){
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

void Sort::mainSort(string file)
{
  ifstream myFile;
  double data;
  string line;
  clock_t t; // for checking the time 

  myFile.open(file);

  if (!myFile) { // file checking
    cerr << "Unable to open file " << file << endl;;
    exit(1);
  }

  getline(myFile, line);
  length = atof(line.c_str());


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

  srand(time(NULL));

  // cout time start
  t = clock();
  quickSort(quickArr, 0, length - 1);
  t = clock()-t;
  cout << "Quick Sort: " << t << " milliseconds!" << endl;

  t = clock();
  insertSort(insertArr);
  t = clock()-t;
  cout << "Insert Sort: " << t << " milliseconds!" << endl;

  t = clock();
  bubbleSort(bubbleArr);
  t = clock()-t;
  cout << "Bubble Sort: " << t << " milliseconds!" << endl;

  t = clock();
  selectionSort(selectionArr, length);
  t = clock()-t;
  cout << "Selection Sort: " << t << " milliseconds!" << endl;


  cout << "Done" << endl;
}
