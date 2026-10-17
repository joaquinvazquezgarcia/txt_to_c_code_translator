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

    while (1) 
    {
        
        int contentStatus = fscanf(txtFile, "%99[^({# \n<]", content);
        
        if (contentStatus == 1)
        {
            if (strcmp(content,"incluir") == 0)
            {
                fprintf(cFile,"include");
            }
            else if (strcmp(content,"si") == 0)
            {
                fprintf(cFile,"if");
            }
            else if (strcmp(content,"imprimir") == 0)
            {
                fprintf(cFile,"printf");
            }
            else if (strcmp(content,"ingresar") == 0)
            {
                fprintf(cFile,"scanf");
            }
            else if (strcmp(content,"retornar") == 0)
            {
                fprintf(cFile,"return");
            }
            else if (strcmp(content,"entero") == 0)
            {
                fprintf(cFile,"int");
            }
            else if (strcmp(content,"principal") == 0)
            {
                fprintf(cFile,"main");
            }
            else if (strcmp(content,"real") == 0)
            {
                fprintf(cFile,"float");
            }
            else if (strcmp(content,"mientras") == 0)
            {
                fprintf(cFile,"while");
            }
            else if (strcmp(content,"para") == 0)
            {
                fprintf(cFile,"for");
            }
            else if (strcmp(content,"sino") == 0)
            {
                fprintf(cFile,"else");
            }
            else if (strcmp(content,"caracter") == 0)
            {
                fprintf(cFile,"char");
            }
            else
            {
                fprintf(cFile,"%s", content);
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
    
    
    
    
    return 0;
}