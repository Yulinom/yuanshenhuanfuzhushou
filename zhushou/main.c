#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* myStrcat(char *s1, char *s2){
    char *r=malloc(strlen(s1)+strlen(s2)+1);
    strcpy(r,s1);
    strcat(r,s2);

    return r;
}
void strchange(char* old, char a, char b){
    for(int i=0;;i++){
        if(old[i]=='\0') break;
        if(old[i]==a) old[i]=b;
    }
}

void init(char* s){
    FILE* f1=fopen("hf/g_config.ini","r+");
    FILE* f2=fopen("hf/b_config.ini","r+");
    FILE* f3=fopen("hf/exten.txt","a");
    fseek(f3,0,2);//文件位置标记移到末尾
    long sl=ftell(f3);

    fseek(f1,sl,0);
    fseek(f2,sl,0);
    fprintf(f1,s);
    fprintf(f2,s);

    fseek(f1,0,2);
    fseek(f2,0,2);

    fclose(f1);
    fclose(f2);

    fputs("\nhad changed",f3);
    fclose(f3);
}

int copy_file(char* inFileName, FILE* outFile){
    FILE * in;
    char ch;
    if((in=fopen(inFileName,"r"))==NULL){
        printf("can't open in\n");
        exit(0);
    }

    ch=fgetc(in);
    while(!feof(in)){
        fputc(ch,outFile);
        ch=fgetc(in);
    }

    fclose(in);
    return 0;
}



int main()
{
    FILE* cfp=fopen("hf/exten.txt","r");
    //fseek(cfp,0,2);
    //printf("%ld",ftell(cfp));
    char *rf=malloc(sizeof(char*));

    fseek(cfp,0,2);
    if(ftell(cfp)==71){//需要初始化
        printf("请输入原神文件所在目录：\n\t");
        gets(rf);
        char* temp=malloc(strlen(rf)+strlen("/Genshin Impact Game\n"));
        strcpy(temp,rf);
        strcat(temp,"/Genshin Impact Game\n");

        strchange(rf,'\\','/');
        strchange(temp,'\\','/');
        init(temp);

        FILE* rootfile=fopen("rootfile.txt","w+");
        fputs(rf,rootfile);
        fclose(rootfile);
    }

    fgets(rf,1024,fopen("rootfile.txt","r"));


    char *rfc,*rfc2;

    rfc=myStrcat(rf,"/config.ini");
    rfc2=myStrcat(rf,"/Genshin Impact Game/config.ini");

    printf("更改文件目录为：\n\t%s\t%s\n",rfc,rfc2);

    remove(rfc);
    remove(rfc2);
    printf("请键入1/2选择服务器...\n\t1===>官服\n\t2===>b服\n");
    int select,flag=0;

    scanf("%d",&select);
    FILE* fp=fopen(rfc,"wb+");
    FILE* fp2=fopen(rfc2,"wb+");
    if(fp==NULL||fp2==NULL) {
        printf("err");
        exit(0);
    }

    while(flag==0){
        flag=1;
        if(select==1){//官服
            copy_file("hf/g_config.ini",fp);
            copy_file("hf/in/g_config.ini",fp2);
            printf("已更改为官服\n");

        }else if(select==2){//b服
            copy_file("hf/b_config.ini",fp);
            copy_file("hf/in/b_config.ini",fp2);
            printf("已更改为b服\n");

        }else{//非法输入
            printf("输入有误，请重新输入：\n");
            flag=0;
            scanf("%d",&select);
        }
    }

    fclose(fp);
    fclose(fp2);

    system("pause");
    return 0;
}

