#include <stdio.h>

/* 1. Создать структуру для флагов (все поля = 0)
  2. Пройти по argv[1..argc-1]:
     если это флаг → установить бит в структуре
     если это не флаг → добавить путь в список файлов
  3. Если список файлов пуст → читать stdin
  4. Для каждого файла в списке → вывести с учётом флагов */
Flags flags = {0};

int main(int argc, char *argv[]){
    char *files[argc];  
    int file_count = 0;
    for (int i = 1; i < argc; i++) {
        if (parse_flags(argv[i])==0){
            files[file_count]=argv[i];
            
        }
        
        print_file(argv[i]);
    }
    return 0;
}

void print_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        char ch;
        while ((ch = fgetc(file)) != EOF) {
            putchar(ch);
        }
        fclose(file);
    } else {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
    }
}
int parse_flags(char *el){
    for (int i; i<el; i++){
        if ("-" == el[0]){
            if (el[i] in flags){
                flags.el[i]=1;
            } 
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
    }

}

typedef struct {
    int b;  
    int e;  
    int n;  
    int s;  
    int t;  
    int E;  
    int T;  
    int v;  
} Flags;