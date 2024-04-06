#include "main.h"


int main(){

    FILE* f1 = fopen("name.txt","r");
    FILE* f2 = fopen("codename.txt","r");

    printf("Enter input string \n");
    char inputname [30];
    char inputcode[5];

    scanf("%s",inputname);
    printf("Please enter code\n");
    scanf("%s",inputcode);
    char name[30];
    char code[5];
    int index = 0;
    while (fscanf(f1,"%s",name) != EOF){

        for (int i = 0; i <strlen(name);i++){
            if (name[i] == inputname[0]){
                for (int j = 0;j < strlen(inputname);j++){
                    if (name[i+j] == inputname[j]){
                        index++;
                    }
                }
                if (index == strlen(inputname)){
                    printf("%s\n",name);
                    index = 0;
                    break;
                }
                else{
                    index = 0;
                    break;
                }
                
            }
        }
    }
     while (fscanf(f2,"%s",code) != EOF){

        for (int i = 0; i <strlen(code);i++){
            if (code[i] == inputname[0]){
                for (int j = 0;j < strlen(inputname);j++){
                    if (code[i+j] == inputname[j]){
                        index++;
                    }
                }
                if (index == strlen(inputname)){
                    printf("%s\n",code);
                    index = 0;
                    break;
                }
                else{
                    index = 0;
                    break;
                }
                
            }
        }
    }
    return 0;
}