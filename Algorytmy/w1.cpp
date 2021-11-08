#include <iostream>
#include <stdlib.h>
#include<time.h>


using namespace std;

void SelectionSort(int t[], int r);
void InsertSort(int t[], int r);
void InsertSort2(int t[], int r);

void MergeSort(int t[], int z[], int start, int stop);

void Wyswietl(int t[], int r);





int main()
{
  int rozm = 200000;
  int c1, c2;

  int *t1 = new int[rozm];
  int *t2 = new int[rozm];
  int *t3 = new int[rozm];
  int *z = new int[rozm];

  for(int i=0; i< rozm; i++)
    t1[i]=t2[i]=t3[i]=rand();


  c1 = clock();
  SelectionSort(t1,rozm);
  c2 = clock();
  Wyswietl(t1,rozm);
  cout <<"czas "<<c2-c1<<endl<<endl;

  c1 = clock();
  InsertSort(t2,rozm);
  c2 = clock();
  Wyswietl(t2,rozm);
  cout <<"czas "<<c2-c1<<endl<<endl;


  c1 = clock();
  MergeSort(t3,z,0,rozm-1);
  c2 = clock();
  Wyswietl(t3,rozm);
  cout <<"czas "<<c2-c1<<endl<<endl;




  return 0;
}





void SelectionSort(int t[], int r)
{
    for(int i=0; i< r; i++)
    {
      int idx = i;
      for(int j=i+1; j< r; j++)
         if(t[j]<t[idx]) idx = j;
      swap(t[i],t[idx]);
    }
}

void InsertSort(int t[], int r)
{
    for(int i=1; i< r; i++)
    {   int idx = i-1;
        int temp = t[i];
        while(idx >= 0 && t[idx]> temp)
         {
           t[idx+1] = t[idx];
           idx --;
         }
        t[idx+1] = temp;
    }
}

void InsertSort2(int t[], int r)
{

    int idx = 0;
    for(int j=1; j< r; j++)
        if(t[j]<t[idx]) idx = j;
    swap(t[0],t[idx]);


    for(int i=1; i< r; i++)
    {   int idx = i-1;
        int temp = t[i];
        while(t[idx]> temp)
         {
           t[idx+1] = t[idx];
           idx --;
         }
        t[idx+1] = temp;

    }
}




void Wyswietl(int t[], int r)
{
    for(int i=1; i< r; i++) cout <<t[i]<<", ";
    cout<<endl<<endl;
}

void Merge(int t[], int z[], int p, int s, int k)
{
    for(int i=p; i<= k; i++) z[i] = t[i];

    int a = p; int b = s+1;
    for(int i=p; i<= k; i++)
    {
      if (a==s+1) {t[i]=z[b++]; continue;}
      if (b == k+1) {t[i]=z[a++]; continue;}
      if (z[a]<=z[b]){t[i]=z[a++]; continue;}
      else {t[i]=z[b++]; continue;}
    }


}

void MergeSort(int t[], int z[], int start, int stop)
{
  if(start>=stop) return;
  int mid = (start+stop)/2;
  MergeSort(t,z, start, mid);
  MergeSort(t,z,  mid+1, stop);
  Merge(t,z,start, mid, stop);
}
