#include <stdio.h>
#include <string.h>

void buscarPalabras(char texto[], int longitud, char palabrasFound[][100], int* cantidad) {

    char* palabra;

    palabra = strtok(texto, " ,.\n");

    while (palabra != NULL) {

        if (strlen(palabra) == longitud) {
            strcpy(palabrasFound[*cantidad], palabra);
            (*cantidad)++;
        }

        palabra = strtok(NULL, " ,.\n");
    }
}

int main(void) {


    char texto[1000];
    int longitud;
    char palabrasFound[100][100];
    int cantidad = 0;

FILE *archivo;

    archivo=fopen("texto.txt", "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    fgets(texto, 1000, archivo);

    printf("Longitud de palabras a buscar: ");
    scanf("%d", &longitud);

    buscarPalabras(texto, longitud, palabrasFound, &cantidad);

    printf("Palabras encontradas:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%s\n", palabrasFound[i]);
    }

    fclose(archivo);

}
