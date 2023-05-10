#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char str[100];
    int len, i, j, vocales, consonantes, espacios, n;
    char *strings;
    FILE *archivo;

    printf("Numero de cadenas a ingresar: ");
    scanf("%d", &n);
    getchar();

    strings = malloc(n * sizeof(char *));

    for (int k = 1; k <= n; k++) {
        printf("\nIngrese la cadena %d: ", k);
        fgets(str, 100, stdin);
        len = strlen(str);

        vocales = consonantes = espacios = 0;  //reset para la sig. cadena


        for (i = len - 2; i >= 0; i--) {
            if (str[i] == ' ') {
                espacios++;
                for (j = i + 1; j < len - 1 && str[j] != ' '; j++) {
                    printf("%c", str[j]);
                    if (str[j] == 'a' || str[j] == 'e' || str[j] == 'i' || str[j] == 'o' || str[j] == 'u' || str[j] == 'A' || str[j] == 'E' || str[j] == 'I' || str[j] == 'O' || str[j] == 'U') {
                        vocales++;
                    } else if ((str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'A' && str[j] <= 'Z')) {
                        consonantes++;
                    }
                }
                printf(" ");
            }
        }

        for (j = 0; j < len - 1 && str[j] != ' '; j++) {
            printf("%c", str[j]);


            if (str[j] == 'a' || str[j] == 'e' || str[j] == 'i' || str[j] == 'o' || str[j] == 'u' || str[j] == 'A' || str[j] == 'E' || str[j] == 'I' || str[j] == 'O' || str[j] == 'U') {
                vocales++;
            } else if ((str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'A' && str[j] <= 'Z')) {
                consonantes++;
            }
        }

        archivo = fopen("strings.txt", "a");
        if (archivo == NULL) {
            printf("Error ");
            return 1;
        }

        printf("\nvocales: %d\nconsonantes: %d\nespacios: %d\n", vocales, consonantes, espacios);
        fprintf(archivo, "%s", str);
        fprintf(archivo, "vocales: %d\nconsonantes: %d\nespacios: %d\n\n", vocales, consonantes, espacios);


        vocales = consonantes = espacios = 0; //reset para la sig. cadena
    }

    free(strings);


}
