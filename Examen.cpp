#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
typedef struct Examen
{
    int tiempo;
} reg;
reg registros[100];

void cargar(reg registros[], int *n);
void imprimir(reg registros[], int n);
int media(reg registros[], int n);
void moda(reg registros[], int n);
void mediana(reg registros[], int n);
void ordenar(reg registros[], int n);
void varianzdes(reg registros[], int n);
void generarArchivo(reg registros[], int n);
void cuartil(reg registros[], int n);
void gen_Arch_bin(reg registros[], int n);

int main()
{
    int op, n = 0;
    
    do
    {
        printf("\tMenu\n ");
        printf("1.- Cargar muestra\n");
        printf("2.- Imprimir muestra\n");
        printf("3.- Media aritmetica\n");
        printf("4.- Moda\n");
        printf("5.- Mediana\n");
        printf("6.- Varianza y desvición estandar\n");
        printf("7.- Tercer cuartil\n");
        printf("8.- Generar archivo Texto\n"); //toda la info
        printf("9.- Generar archivo binario\n"); //reg calculos
        printf("10.- Imprimir archivo Binario\n");
        printf("0.- Salir\n\n");
 
        scanf("%d",&op);
        

        if (op == 1)
        {
            cargar(registros, &n);   
        }
        else
        {
            if (op == 2)
            {
                imprimir(registros, n);
            }
            else
            {
                if (op == 3)
                {
                    float medi = media(registros, n);
                    printf("La media es: %.2f\n", medi);

                }
                else
                {
                    if (op == 4)
                    {
                        moda(registros, n);
                    }
                    else
                    {
                        if (op == 5)
                        {
                            mediana(registros, n);
                        }
                        else
                        {
                            if (op == 6)
                            {
                                varianzdes(registros, n);
                            }
                            else
                            {
                                if (op == 7)
                                {
                                    cuartil(registros, n);
                                }
                                else
                                {
                                    if (op == 8)
                                    {
                                        generarArchivo(registros, n);
                                    }
                                    else
                                    {
                                        if (op == 9)
                                        {
                                            gen_Arch_bin(registros, n);
                                        }
                                        
                                    }
                                    
                                }
                                
                            }
                            
                            
                        }
                        
                    }
                }
            }
            
        }
        
        
    } while (op != 0);
    return 0;
}

void cargar(reg registros[], int *n)
{
    FILE *fa = fopen("C://Users//costco//Documents//Programacion estructurada//Examen/ensamble.txt", "r");

    while ((*n < 100) && (fscanf(fa, "%d", &registros[*n].tiempo) == 1)) {
        (*n)++;
    }

    fclose(fa);
}

void imprimir(reg registros[], int n) 
{
    printf("\nMuestra:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d\n", registros[i].tiempo);
    }
}

int media(reg registros[], int n)
{
    int suma = 0;
    for (int i = 0; i < n; i++) 
    {
        suma += registros[i].tiempo;
    }

    float media = (float)suma / n;
    return media;
}

void moda(reg registros[], int n)
{
    int *moda, maxi = 0, maxmoda;

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (registros[i].tiempo == registros[j].tiempo) 
            {
                moda[i]++;
            }
        }
    }

    maxmoda = moda[0];
    for (int i = 1; i < n; i++) 
    {
        if (moda[i] > maxmoda) 
        {
            maxmoda = moda[i];
            maxi = i;
        }
    }
    printf("La moda es: %d\n", registros[maxi].tiempo);
}

void mediana(reg registros[], int n)
{
    ordenar(registros, n);

    float mediana;
    if (n % 2 == 0) 
    {
        mediana = (registros[n / 2 - 1].tiempo + registros[n / 2].tiempo) / 2.0;
    } 
    else 
    {
        mediana = registros[n / 2].tiempo;
    }

    printf("La mediana es: %.2f\n", mediana);
}

void ordenar(reg registros[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (registros[j].tiempo < registros[min].tiempo)
            {
                min = j;
            }
        }
        if (min != i)
        {
            reg temp = registros[i];
            registros[i] = registros[min];
            registros[min] = temp;
        }
    }
}
void varianzdes(reg registros[], int n)
{
    float varianza, desvest, medial = media(registros, n);
    for (int i = 0; i < n; i++)
    {
        varianza += ((registros[i].tiempo - medial)*(registros[i].tiempo - medial));
    }
    varianza /= n;
    desvest = sqrt(varianza);

    printf("La varianza es: %.2f\n", varianza);
    printf("La desvest es: %.2f\n", desvest);

}

void cuartil(reg registros[], int n)
{
    printf("Este es el tercer cuartil:\n");
    ordenar(registros, n);
    int cuartil = (3*(n+1))/4;
    for (int i = cuartil; i < n; i++)
    {
        printf("%d\n", registros[i].tiempo);
    }
    
}

void generarArchivo(reg registros[], int n) 
{
    FILE *archivo = fopen("C:\\Users\\costco\\Documents\\Programacion estructurada\\EXAMEN\\archivo.txt", "w");
        for (int i = 0; i < n; i++) 
        {
            fprintf(archivo, "%d\n", registros[i].tiempo);
        }
    fclose(archivo);
    printf("\n\nArchivo generado\n");
}

void gen_Arch_bin(reg registros[], int n)
{
    reg rege;
    FILE *fa = fopen("C:\\Users\\costco\\Documents\\Programacion estructurada\\EXAMEN\\ARCHIVOBIN.tmp", "ab");

    for (int i = 0; i < n; i++)
    {
        rege = registros[i]; //no lei que era de los registros de calculos
    }
    fclose(fa);
}