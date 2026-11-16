#include<stdio.h>
struct student{
	char name[20];
	int score;
};
int main(void){
    struct student a[5],tmp;
	int i,j,k;
	
	printf("请输入：\n");
	for(k=0;k<5;k++){
		printf("第 %d 个学生（姓名 成绩）：", k + 1);
		scanf("%s %d",a[k].name ,&a[k].score );
	}
	for(i=0;i<5;i++){
		for(j=0;j<5-i-1;j++){
			if(a[j].score <a[j+1].score ){
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}
	printf("排序结果为：\n");
	for(k=0;k<5;k++){
	printf("%s %d\n",a[k].name ,a[k].score );
}
    return 0;
  
}
