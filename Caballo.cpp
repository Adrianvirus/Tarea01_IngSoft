#include<stdlib.h>
#include<stdio.h>
#include <iostream>

#define MAX 9

using namespace std;

void Llenar(int a[][MAX],int n, int m);
void Mostrar(int a[][MAX],int n,int m);
void Caballo (int a[][MAX], int n, int m, int *i, int *j, int *k);

int main()
{
    int a[MAX][MAX];
    int n,m,b,x,fila,columna;
    n=8;
    m=8;
        
    Llenar(a,n,m);
    cout<<endl<<"Tablero de 8x8"<<endl;
    Mostrar(a,n,m);
    cout<<"Ingrese la posicion de inicio del caballo"<<endl;
	cout<<"Ingrese fila: ";
    cin>>fila;
    cout<<endl<<"Ingrese columna: ";
	cin>>columna;
	   
		
		 
    system("pause");
}





void Llenar(int a[][MAX],int n, int m)
{
     int i,j,dato;
     dato = 0;
     for(i=1;i<=n;i++)
         for(j=1;j<=m;j++)
         {
          
          a[i][j]=dato;
          a[3][3]=-1;
          a[3][6]=-1;
          a[6][3]=-1;
          a[6][6]=-1;
         }
}
void Mostrar(int a[][MAX],int n,int m)
{
     int i,j;
     for(i=1;i<=n;i++)
     {
                      for(j=1;j<=m;j++)
                      {
                                       cout<<"  "<<a[i][j];
                      }
                      cout<<endl<<endl;
     }
}

void Caballo (int a[][MAX], int n, int m, int *i, int *j, int *k)
{
     int fil;
     int col;
     fil = *i+2; //Mov 1
     col = *j+1;
     if(fil>0 && fil<9 && col>0 && col<9 && a[fil][col]==0)
     {
              a[fil][col]=*k;
              *k=*k+1;
              *i=fil;
              *j=col;
     }  
     else
     {
         fil = *i+1;  //Mov 2
         col = *j+2;
         if(fil>0 && fil<9 && col>0 && col<9 && a[fil][col]==0)
         {
                  a[fil][col]=*k;
                  *k=*k+1;
                  *i=fil;
                  *j=col;
         }
         else
         {
             fil = *i-1; //Mov 3
             col = *j+2; 
             if(fil>0 && fil<9 && col>0 && col<9 && a[fil][col]==0)
             {
                      a[fil][col]=*k;
                      *k=*k+1;
                      *i=fil;
                      *j=col;
             }
             else
             {
                 fil = *i-2; //Mov 4
                 col = *j+1;
                 if(fil>0 && fil<9 && col>0 && col<9 && a[fil][col]==0)
                 {
                          a[fil][col]=*k;
                          *k=*k+1;
                          *i=fil;
                          *j=col;
                 }
                 else
                 {
                     fil = *i-2; // Mov 5
                     col = *j-1;
                     if(fil>0 && fil<9 && col>0 && col<9 && a[fil][col]==0)
                     {
                              a[fil][col]=*k;
                              *k=*k+1;
                              *i=fil;
                              *j=col;
                     }
                     else
                     {
                         fil = *i-1; // Mov 6
                         col = *j-2;
                         if(fil>0 && fil<9 && col>0 && col<9 && a[fil][col]==0)
                         {
                                  a[fil][col]=*k;
                                  *k=*k+1;
                                  *i=fil;
                                  *j=col;
                         }
                         else
                         {
                             fil = *i+1;  //Mov 7
                             col = *j-2;
                             if(fil>0 && fil<9 && col>0 && col<9 && a[fil][col]==0)
                             {
                                      a[fil][col]=*k;
                                      *k=*k+1;
                                      *i=fil;
                                      *j=col;
                             }
                             else
                             {
                                 fil = *i+2;
                                 col = *j-1;
                                 if(fil>0 && fil<9 && col>0 && col<9 && a[fil][col]==0)
                                 {
                                          a[fil][col]=*k;
                                          *k=*k+1;
                                          *i=fil;
                                          *j=col;
                                 }
                             }
                         }
                     }
                 }
             }
         }
     } 
}
