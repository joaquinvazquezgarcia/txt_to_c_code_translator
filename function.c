#include <stdio.h>
#include <string.h>

int main() {

    int indexSize = 11; //cantidad de palabras en el diccionario;

    typedef struct {
        char spa[indexSize][20];
        char eng[indexSize][20];
    } index;

    index Index;

    FILE *dictionary;

    dictionary = fopen("C:\\Users\\joaqu\\Desktop\\txt_to_c_code_translator\\dictionary.txt", "r");

    if (dictionary == NULL)
    {
        printf("No se encontró un diccionario de palabras para traducir el código");
        return 0;
    }



    char content[20];
    int i = 0;



    while (1)
    {
        if (fscanf(dictionary, "%[^=]", content) == 1)
        {    
            strcpy(Index.eng[i], content);
            fgetc(dictionary);
        }
        
        if (fscanf(dictionary, "%[^\n]", content) == 1) {
            strcpy(Index.spa[i], content);
        }

        if (fgetc(dictionary) == EOF)
        {
            break;
        }
        

        i++;
    }
    


    for (int i = 0; i < indexSize; i++)
    {
        printf("%s = ", Index.eng[i]);
        printf("%s\n", Index.spa[i]);
    }
    

    return 0;
}