#include <stdio.h>
#include <stdlib.h>
#include "student.h"     

void input(struct student *a,int n){
	int k;
	for(k=0;k<n;k++){
		scanf("%s %d",a[k].name ,&a[k].score  );
	}
}
int save(struct student *a,int n){
	FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) {
    printf("打开失败\n");
    return 0;
    }
    int k;
    for(k=0;k<n;k++){
    	fprintf(fp,"%s %d\n",a[k].name ,a[k].score  );
	}
	fclose(fp);
	return 1;
}
int load(struct student *a,int n){
	int k;
	FILE *fp2 = fopen("students.txt", "r");
	if (fp2 == NULL) {
    printf("打开失败\n");
    return 0;
    }
	for(k=0;k<n;k++){
		int ret = fscanf(fp2, "%s %d", a[k].name, &a[k].score );
        if (ret != 2) {
        printf("第 %d 个读取失败\n", k + 1);
          fclose(fp2);
          return 0;
         } 
	}
	fclose(fp2);
	return 1;
}
void  print(struct student *a,int n){
	int k;
	for(k=0;k<n;k++){
		printf("%s %d\n",a[k].name ,a[k].score );
	}
}
