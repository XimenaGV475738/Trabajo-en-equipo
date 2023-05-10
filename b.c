#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct actividad {
    char fecha[11];
    char concepto[100];
};

int main(void) {

    int n;
    struct actividad *actividades;
    FILE *archivo;
    char fecha[11];

    printf("Ingresa la fecha (en formato dd/mm/yyyy): ");
    scanf("%s", fecha);

    printf("\nIngresa el número de actividades: ");
    scanf("%d", &n);

    actividades = malloc(n * sizeof(struct actividad));
    getchar();

    for (int i = 0; i < n; i++) {

        printf("\nIngresa la actividad %d (en formato dd/mm/yyyy Concepto): ", i + 1);
        scanf("%s %[^\n]", actividades[i].fecha, actividades[i].concepto);
        getchar();
    }

    archivo = fopen("actividades.txt", "a");

    if (archivo == NULL) {
        printf("Error\n");
        return 1;
    }

    fprintf(archivo, "Actividades ingresadas:\n");

    for (int i = 0; i < n; i++) {

        if (strcmp(fecha, actividades[i].fecha) == 0) {
            printf("\nActividad %d: Actividad válida.\n", i + 1);
            fprintf(archivo, "%s %s: Actividad válida.\n", actividades[i].fecha, actividades[i].concepto);
        }

        else {
            printf("\nActividad %d: Actividad no válida.\n", i + 1);
            fprintf(archivo, "%s %s: Actividad no válida.\n", actividades[i].fecha, actividades[i].concepto);
        }
    }

    fclose(archivo);
    free(actividades);


}

