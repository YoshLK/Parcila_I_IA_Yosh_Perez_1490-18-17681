#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace:: std;
  
  const int Tamano_Arreglo = 8;
  int x = 0;
  int y = 0;
  

  int accesibilidad = 100;
  

   int Determina_Minimo( int Arreglo[][Tamano_Arreglo], int lado)
   {               

   int minimo = 30;   

   for ( int i = 0; i < lado; i++)
   for ( int j = 0; j < lado; j++)
   {           
    if ( Arreglo[i][j] < minimo )
    minimo = Arreglo[i][j];
   
   }        

   return minimo;
   }            

   void Marca_Minimos( int menor, int Arreglo_Valores[][Tamano_Arreglo], int Arreglo_Tablero[][Tamano_Arreglo])

 {      
 for ( int i = 0; i < Tamano_Arreglo; i++)
 for ( int j = 0; j < Tamano_Arreglo; j++)
 {      
  if ( Arreglo_Valores[i][j] == menor)
  Arreglo_Tablero[i][j] = 'a';

  
 }   
 }           


  

  int Determina_Posicion( int Tabla[][Tamano_Arreglo], int contador_reinas)
  {        

   
   int contador = 0;

   for( int i = 0; i < Tamano_Arreglo; i++ )
   for( int j = 0; j < Tamano_Arreglo; j++ )
   {        
   if ( 'a' == Tabla[i][j])
   {     
   contador++;
   }    
   }       

  
  
   if ( 0 != contador)

   {         
    int dado;
    srand(time(NULL));   

   
   dado = 1 + rand() % contador;

  
   int s = 0;  
  

  for ( int i = 0; i < Tamano_Arreglo; i++)
  for ( int j = 0; j < Tamano_Arreglo; j++)
  { 
  if( 'a' == Tabla[i][j] )
  {
  s++;
  if (s == dado )
  
  {  
  Tabla[i][j] = contador_reinas;
  y = i;   
  x = j;   
  }   
  }
  }  
 

  for ( int i = 0; i < Tamano_Arreglo; i++)
  for ( int j = 0; j < Tamano_Arreglo; j++)
  { 
  if( 'a' == Tabla[i][j])
  Tabla[i][j] = 0;
  }    

  }        

  return contador;
  }          

  void Modifica_Valores( int Arreglo_Valores[][Tamano_Arreglo])

  {  

   Arreglo_Valores[y][x] = accesibilidad;
   

   for ( int i = 0; i < Tamano_Arreglo; i++ )
   Arreglo_Valores[y][i] = accesibilidad;
  

   for ( int j = 0; j < Tamano_Arreglo; j++ )
   Arreglo_Valores[j][x] = accesibilidad;
  
  int s;
  int t;
  s = x;
  t = y;
  while ( (s < Tamano_Arreglo) && ( t < Tamano_Arreglo))
  Arreglo_Valores[t++][s++] = accesibilidad;

  s = x;
  t = y;

  while ( (s >= 0) && ( t >= 0))
  Arreglo_Valores[t--][s--] = accesibilidad;

  s = x;
  t = y;

   while ( (t >= 0) && ( s < Tamano_Arreglo))
   Arreglo_Valores[t--][s++] = accesibilidad;
   
   s = x;
   t = y;

   while ( (t < Tamano_Arreglo) && ( s >= 0))
   Arreglo_Valores[t++][s--] = accesibilidad;

  
  }  

  void Imprimir( int B[][Tamano_Arreglo ], int lado)

  {                           
  for ( int k = 0; k < lado; k++ )
  {
  for ( int l = 0; l < lado; l++ )
  cout << "\t " << B[k][l];
  cout << endl<<endl;
  }

  cout << endl<<endl;
  }

  
 // Main
   int main()

   {          


   int Valores[Tamano_Arreglo ][Tamano_Arreglo ] =

   { {22, 22, 22, 22, 22, 22, 22, 22},
     {22, 24, 24, 24, 24, 24, 24, 22},
     {22, 24, 26, 26, 26, 26, 24, 22},
     {22, 24, 26, 28, 28, 26, 24, 22},
     {22, 24, 26, 28, 28, 26, 24, 22},
     {22, 24, 26, 26, 26, 26, 24, 22},
     {22, 24, 24, 24, 24, 24, 24, 22},
     {22, 22, 22, 22, 22, 22, 22, 22}

   };


  int Tablero[Tamano_Arreglo][Tamano_Arreglo] = {{0},{0}};
 

  int minimo;
  int numero_reina = 1;
  int casillas_disponibles = Tamano_Arreglo*Tamano_Arreglo;

  while ((0 != casillas_disponibles)  )
 {      
  minimo =  Determina_Minimo( Valores, Tamano_Arreglo);

  

  Marca_Minimos( minimo, Valores, Tablero);
  casillas_disponibles = Determina_Posicion( Tablero, numero_reina);
  
  

  Modifica_Valores( Valores);

  numero_reina++;
  } 

  ( Tamano_Arreglo == numero_reina -2)? cout <<"\nAQUI ESTAN LAS OCHO REINAS!" << endl: cout <<"\nLo siento, solo se pudo colocar: " << numero_reina -2 <<    " reinas. Intente de nuevo." <<endl;
  Imprimir( Tablero, Tamano_Arreglo   );

  return 0;
  }  // fin del programa
