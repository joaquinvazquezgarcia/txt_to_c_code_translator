#include <stdio.h>
#include <string.h>



int main() {
    
    /* DICCIONARIO TRADUCTOR/INDICE */

    int dictionaryLength = 12; //Modificar si se agregan palabras al diccionario

    typedef struct {
        char spa[dictionaryLength][20];
        char eng[dictionaryLength][20];
    } index;

    index Index;

    FILE *dictionary;

    dictionary = fopen("C:\\Users\\joaqu\\Desktop\\txt_to_c_code_translator\\dictionary.txt", "r");

    if (dictionary == NULL)
    {
        printf("No se encontró un diccionario de palabras para traducir el código");
        return 0;
    }
    
    char indexContent[20];
    int i = 0;

    while (1)
    {
        if (fscanf(dictionary, "%[^=]", indexContent) == 1)
        {    
            strcpy(Index.spa[i], indexContent);
            fgetc(dictionary);
        }
        
        if (fscanf(dictionary, "%[^\n]", indexContent) == 1) {
            strcpy(Index.eng[i], indexContent);
        }

        if (fgetc(dictionary) == EOF)
        {
            break;
        }
        

        i++;
    }



    /* archivos C y TXT */
    FILE *cFile;
    FILE *txtFile;

    txtFile = fopen("C:\\Users\\joaqu\\Desktop\\txt_to_c_code_translator\\txtfile.txt", "r");  //cambiar ruta si se comparte el codigo a otra pc
    cFile = fopen("C:\\Users\\joaqu\\Desktop\\txt_to_c_code_translator\\cfile.c", "r+");  //cambiar ruta si se comparte el codigo a otra pc
    
    if (cFile == NULL)
    {
        cFile = fopen("C:\\Users\\joaqu\\Desktop\\txt_to_c_code_translator\\cfile.c", "w");
        printf("Creando archivo\n\n");
    }
    if (txtFile == NULL)
    {
        printf("No se encontro un archivo txt para traducir\n\n");
        return 0;
    }


    
    char txtFileContent[100];

    while (1) 
    {
        
        int contentStatus = fscanf(txtFile, "%99[^({# \n<]", txtFileContent);
        
        if (contentStatus == 1)
        {

            int found = 0;

            for (int i = 0; i < dictionaryLength; i++)
            {
                if ((strcmp(txtFileContent, Index.spa[i]) == 0))
                {
                    fprintf(cFile,"%s", Index.eng[i]);
                    found = 1;
                    break;
                }
            }
            if (found == 0)
            {
                fprintf(cFile,"%s", txtFileContent);
            }
           
            
            
        }
        else if (contentStatus == 0)
        {
            
            int limit = fgetc(txtFile);
            
            
            if (limit != EOF)
            {
                fprintf(cFile,"%c", limit);
            }
            
        }
        else
        {
            break;
        }
        
    }
    
    
    printf("------------------\n");
    printf("Proceso terminado\n");
    printf("------------------\n");
    
    
    fclose(dictionary);
    fclose(txtFile);
    fclose(cFile);
    
    return 0;
}