/* Program Sequential Search
  Nama File : Lat_Searching_01a */
#include <iostream>
// #include<conio.h>

using namespace std;

int main()
{
  int Nilai[20];
  int i, N, Bilangan;
  bool ketemu;
  
  cout<<"Masukkan Banyaknya Bilangan = ";
  cin>>N;
  
  //Membaca elemen Array
  for(i=0; i<N; i++)
  {
    cout<<"Masukkan elemen ke-"<<i<<" = ";
    cin>>Nilai[i];
  }
  
  //Mencetak Elemen Array
  cout<<"\nDeretan Bilangan = ";
  for(i=0; i<N; i++)
  cout<<Nilai[i]<<" ";
  
  cout<<"\n\nMasukkan Bilangan yang akan Dicari = ";
  cin>>Bilangan;
  
  //Melakukan Pencarian
  i=0;
  do
  {
    if(Nilai[i]==Bilangan)
    ketemu = true;
    i++;
  }
  while(!(ketemu));
  
  if(ketemu)
  cout<<"Bilangan "<<Bilangan<<" ditemukan";
  else
  cout<<"Bilangan "<<Bilangan<<" tidak ditemukan";
  // getch();
}