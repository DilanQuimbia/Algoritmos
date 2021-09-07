#include <iostream>
using namespace std;
#include <fstream>

int mitad (int a[],int pinicial, int pfinal);
void ordenar (int a[],int pinicial, int pfinal);
void archivo(int a[]);

int main()
{
  int A[10]= {123, -6, 13, -33, -98, 333, 23, -5, 0, -100};
  archivo(A);
  return 0;

}

void archivo(int a[]){
  ofstream archivo;
  archivo.open("QuickSort",ios::app);
  cout<<"Elementos originales"<<endl;
  archivo<<"Elementos originales"<<endl;
  for(int i=0;i<10;i++)
  {
    cout<<"["<<a[i]<<"]";
    archivo<<"["<<a[i]<<"]";
  }

  cout<<"\nElementos ordenados"<<endl;
  archivo << endl << "Elementos ordenados por Quicksort"<<endl;
  ordenar(a,0,9);
  for(int i=0;i<10;i++)
  {
    cout<<"["<<a[i]<<"]";
    archivo<<"["<<a[i]<<"]";
  }
  archivo.close();
}

int mitad (int a[],int pinicial, int pfinal)
{
  return a[(pinicial+pfinal)/2];
}


void ordenar (int a[],int pinicial, int pfinal)
{

  int i=pinicial;
  int j=pfinal;
  int temp;
  int piv=mitad(a,pinicial,pfinal);
  do
  {
    while(a[i]<piv)
    {
      i++;
    }
    while(a[j]>piv)
    {
      j--;
    }
    if(i<=j)
    {
      temp =a[i];
      a[i]=a[j];
      a[j]=temp;
      i++;
      j--;
    }
  }
    while(i<=j);
    if(pinicial<j)
    {
        ordenar(a,pinicial,j);
    }
    if(i<pfinal)
    {
      ordenar(a,i,pfinal);
    }
}
