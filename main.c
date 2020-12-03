#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void task1(){
printf("vvedite kolichestvo elementov massiva\n");
int n;
scanf("%d",&n);
int* a,i,ans=0;
a=(int*)malloc(sizeof(int)*n);
printf("vvedite elementi massiva\n");
for(i=0;i<n;i++){
    scanf("%d",&a[i]);
}
for (i=1;i<n;i++){
    if (a[i]*a[i-1]<0)
        ans++;
}

printf("\n znak menyaetsa %d raz(a)\n",ans);
}

void task2(){
printf("vvedite kolichestvo elementov massiva\n");
int n;
scanf("%d",&n);
int* a,i,ans=0,ans_end=0;;
a=(int*)malloc(sizeof(int)*n);
printf("vvedite elementi massiva\n");
for(i=0;i<n;i++){
    scanf("%d",&a[i]);
}
for (i=0;i<n;i++){
    if(a[i]%2){
        ans++;}
    else{
        if (ans>ans_end) ans_end=ans;
        ans=0;}
}
if (ans>ans_end) ans_end=ans;
printf("podryad nechetnich chisel: %d\n",ans_end);

}


void task4(){
printf("vvedite kolichestvo elementov massiva\n");
int n;
scanf("%d",&n);
int* a,i;
a=(int*)malloc(sizeof(int)*n);
printf("vvedite elementi massiva\n");
for(i=0;i<n;i++){
    scanf("%d",&a[i]);
}

int max1,max2;
if (n<2){
    printf("nuzhno hotya bi dva elementa\n");
    return;
}

    if (a[0]>a[1]){
        max1=a[0];
        max2=a[1];
    }else{
    max2=a[0];
    max1=a[1];
    }
for (i=2;i<n;i++){
    if (a[i]>=max1){
        max2=max1;
        max1=a[i];
    }
    else if(a[i]>max2){
        max2=a[i];
    }
}
printf("vtoroi maksimalniy element: %d\n",max2);

}



char* delete_spaces(){
    char* str ;

str=(char*)malloc(sizeof(char)*256);
printf("vvedite stroku\n");
fgets(str,256,stdin);
    char* str_without_spaces;
    int cur_char=0;
    str_without_spaces=(char*)malloc(sizeof(char)*256);
    for (int i=0;i<(int)strlen(str);i++){
        if (str[i]!=' '){
            str_without_spaces[cur_char]=str[i];
            cur_char++;}
    }
    str_without_spaces[cur_char]='\0';
    return str_without_spaces;

}



int task7(char* str,int left, int right){

if (right-left==1){
    if((int)str[left]==(int)str[right])
        return 1;
    else return 0;

}
else if(right==left)
    return 1;

/*else if(right<left)
    return 0;*/
if ((int)str[left]==(int)str[right])
    return 1*task7(str,left+1,right-1);
else
    return 0*task7(str,left+1,right-1);

}


int main()
{

int request;
while(1){
        printf("vvedite nomer zadaniya(1,2,4,7) 0 dlya zaversheniya\n");
        scanf("%d%*c",&request);
        if (request==1)
            task1();
        if (request==2)
            task2();
        if(request==4)
            task4();
        if (request==7){

            char* str1=delete_spaces();
            int ans=task7(str1,0,((int)strlen(str1)-2));
            if (ans)
                printf("palyndrom\n");
            else
                printf("ne palyndrom\n");
        }
        if (request==0)
            return 0;





}



}
