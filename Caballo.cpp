#include<stdlib.h>
#include<stdio.h>
#include <iostream>

#define MAX 9

using namespace std;

void Llenar(int a[][MAX],int n, int m); //Permite inicializar el tablero
void Mostrar(int a[][MAX],int n,int m); //Imprime la matriz (tablero) con movimientos
void Caballo (int a[][MAX], int n, int m, int *i, int *j, int *k); //Permite mover al caballo por el tablero
int Completo (int a[][MAX], int m, int n);  //permite Ver si el tablero fue recorrido completamente
void Cualquiera (int a[][MAX], int n, int m, int *i, int *j, int *k); // Permite obtener un movimiento al azar del caballo


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
	b=0;
	x=1;
	int i=0;
	a[fila][columna]= x; //Posicion inicial del caballo
	x++;
	while(i==0)
	{
               b=x;  // Permite verificar cambios en la funcion Caballo
               cout<<"turno"<<x<<endl;
               Caballo(a,n,m,&fila,&columna,&x);
               if(b==x) //de no haber posicion vacia disponible, se Realiza un movimiento al azar para buscar casillas vacias
               {
                       Cualquiera(a,n,m,&fila,&columna,&x);
                   
               }
               Mostrar (a,n,m);
               i=Completo(a,m,n);
    }	 
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
          a[3][6]=-1;  // Los peones seran reprensentado pro el -1
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

int Completo (int a[][MAX], int m, int n)
{
     int cont=0;
     for(int i=1;i<=m;i++)
     {
                      for(int j=1;j<=n;j++)
                      {
                              if(a[i][j]!=0)
                              {
                                            cont++;
                              }
                      }
     }
     if(cont==64)
     {
                return 1;
     }
     else
     {
         return 0;
     }
}

void Cualquiera (int a[][MAX], int n, int m, int *i, int *j, int *k)
{
     int mov = (1 + rand() % 8); //Permite obtener un numero al azar entre 1-8
     cout<<"mov aleatorio:"<<mov<<endl;
     int fil;
     int col;
     if(mov==1)
     {
            fil = *i+2; //Mov 1
            col = *j+1;
            if(fil>0 && fil<9 && col>0 && col<9 && a[fil][col]>0)
            {
              a[fil][col]=*k;
              *k=*k+1;
              *i=fil;
              *j=col;
            }     
     }
     if(mov==2)
     {
               fil = *i+1; //Mov 2
               col = *j+2;
               if(fil>0 && fil<9 && col>0 && col<9 && a[fil][col]>0)
               {
                a[fil][col]=*k;
                *k=*k+1;
                *i=fil;
                *j=col;
               }
     }  
     if(mov==3)
     {
               fil = *i-1; //Mov 3
               col = *j+2;
               if(fil>0 && fil<9 && col>0 && col<9 && a[fil][col]>0)
               {
                a[fil][col]=*k;
                *k=*k+1;
                *i=fil;
                *j=col;
                }  
     }
     if(mov==4)
     {
               fil = *i-2; //Mov 4
               col = *j+1;
               if(fil>0 && fil<9 && col>0 && col<9 && a[fil][col]>0)
               {
                a[fil][col]=*k;
                *k=*k+1;
                *i=fil;
                *j=col;
                }  
     }
     if(mov==5)
     {
               fil = *i-2; //Mov 5
               col = *j-1;
               if(fil>0 && fil<9 && col>0 && col<9 && a[fil][col]>0)
               {
                a[fil][col]=*k;
                *k=*k+1;
                *i=fil;
                *j=col;
               }  
     }
     if(mov==6)
     {
               fil = *i-1; //Mov 6
               col = *j-2;
               if(fil>0 && fil<9 && col>0 && col<9 && a[fil][col]>0)
               {
                a[fil][col]=*k;
                *k=*k+1;
                *i=fil;
                *j=col;
               }  
     }
     if(mov==7)
     {
               fil = *i+1; //Mov 7
               col = *j-2;
               if(fil>0 && fil<9 && col>0 && col<9 && a[fil][col]>0)
               {
                a[fil][col]=*k;
                *k=*k+1;
                *i=fil;
                *j=col;
               }  
     }
     if(mov==8)
     {
               fil = *i+2; //Mov 8
               col = *j-1;
               if(fil>0 && fil<9 && col>0 && col<9 && a[fil][col]>0)
               {
                a[fil][col]=*k;
                *k=*k+1;
                *i=fil;
                *j=col;
               }  
     }
}
