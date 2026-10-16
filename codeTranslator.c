#include <stdio.h>
#include <string.h>


int main() {

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

    char content[100];

    int symbol; //int porque fgetc devuelve en acii

    if (fscanf(txtFile, "%99[^(){}# \n<>]", content) == 0)
    {
        symbol = fgetc(txtFile);
        fprintf(cFile,"%c", symbol);
    }
    
    
    while (fscanf(txtFile, "%99[^({# \n<]", content) == 1) 
    {
        
        
        if (strcmp(content, "incluir") == 0)
        {
            fprintf(cFile, "include");
        }
        else if (strcmp(content, "imprimir") == 0)
        {
            fprintf(cFile, "printf");
        }
        else
        {
            fprintf(cFile, "%s", content);
        }
        
        
        symbol = fgetc(txtFile);
        
        if (symbol != EOF)
        {
            fprintf(cFile,"%c", symbol);
        }
        
    
    }
        
    
    
    printf("------------------\n");
    printf("Proceso terminado\n");
    printf("------------------\n");
    
    
    

    return 0;
}