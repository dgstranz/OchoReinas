#include <iostream>
using namespace std;
#define tam 8 //Se puede cambiar este valor para probar con tableros m�s grandes o m�s peque�os.

int main()
{
    int i,j,reina[tam],legal;
    /* i,j son contadores
       legal es un booleano
       reina[tam] es un array que indica las posiciones de las 8 reinas.
       Considero que las casillas del tablero est�n numeradas (0,0) hasta (7,7). Entonces, "reina[i]=j" indica que hay una reina en (i,j).
       Como no puede haber dos reinas en la misma fila, no necesito crear un array bidimensional.
    */
    for(i=0;i<tam;i++)          //Lleno el array de -1. Despu�s sumar� 1 a la posici�n relevante, as� que al menos ser� 0.
    {
        reina[i]=-1;
    }
    i=0;
    while(i<tam)
    {
        reina[i]=reina[i]+1;
        if(reina[i]>=tam)       //Me he salido del rango y tengo que ir a una fila anterior.
        {
            if(i==0)            //Estoy en la primera fila, no puedo ir a una fila anterior.
            {
                cout << "Error. No he podido poner las " << tam << " reinas en el tablero.";
                return 0;
            }
            else
            {
                reina[i]=-1;    //Reinicializo el valor para esa fila y vuelvo atr�s.
                i=i-1;
            }
        }
        else                    //Es decir, reina[i]<tam. Se ha conseguido situar una reina en el tablero.
        {                       //Ahora hay que comprobar que no puede capturar a ninguna de las dem�s reinas.
            cout << "Intentando (" << i << ", " << reina[i] << "). ";
            j=0;
            legal=1;
            while(legal&&(j<i))
            {
                if((reina[i]==reina[j]) || (reina[i]+i==reina[j]+j) || (reina[i]-i==reina[j]-j))
                {
                    legal=0;    //Entonces la posici�n no es v�lida.
                    cout << "Posici�n no v�lida. Captura al menos a la reina " << j << "." << endl;
                }
                else
                {
                    j++;        //Entonces hay que comprobar para la siguiente reina.
                }
            }
            if(legal)           //La posici�n es v�lida.
            {
                cout << "Posici�n v�lida." << endl;
                i++;
            }
        }
    }
    cout << endl << "Las reinas pueden ir en las siguientes casillas: " << endl << endl;
    for(i=0;i<tam;i++)
    {
        cout << "+";
        for(j=0;j<tam;j++)
        {
            cout << "-+";
        }
        cout << endl << "|";
        for(j=0;j<tam;j++)
        {
            if(reina[i]==j)
            {
                cout << "R|";
            }
            else
            {
                cout << " |";
            }
        }
        cout << endl;
    }
    cout << "+";
    for(j=0;j<tam;j++)
    {
        cout << "-+";
    }
    return 0;
}
