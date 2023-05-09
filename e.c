#include <stdio.h>
#include <string.h>

void Phone(char *telOriginal, char *telDos) {

    int len = strlen(telOriginal);

    telDos[0] = '(';
    telDos[1] = telOriginal[0];
    telDos[2] = telOriginal[1];
    telDos[3] = ')';
    telDos[4] = '-';
    telDos[5] = telOriginal[2];
    telDos[6] = '-';
    telDos[7] = telOriginal[3];

    for (int i = 0; i < 6; i++) {
        telDos[i + 8] = telOriginal[i + 4];
    }

    telDos[14] = '\0';
}

int main(void) {

    FILE *archivo;
    archivo = fopen("telefonos.txt", "w");

    if (archivo == NULL) {
        printf("Error\n");
        return 1;
    }

    int n;
    printf("Ingrese el número de teléfonos que desea ingresar: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        char telOriginal[10];
        char nuevo[13];

        printf("Ingrese el número telefónico numero %d: ", i + 1);
        scanf("%9s", telOriginal);

        while (getchar() != '\n');


        Phone(telOriginal, nuevo);

        fprintf(archivo, "Número telefónico: %s\n", telOriginal);
        fprintf(archivo, "Número nuevo: %s\n\n", nuevo);
    }

    fclose(archivo);

    printf("Se han guardado los números telefónicos en el archivo telefonos.txt.\n");


}
