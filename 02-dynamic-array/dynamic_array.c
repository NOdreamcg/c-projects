#include <stdio.h>
#include <stdlib.h>   
#include <string.h> 
struct student{
	char name[20];
	int score;
};
int main(void){
	int count=0;
	int capacity=2;
	struct student *a=(struct student*)malloc(capacity*sizeof(struct student));
	struct student tmp;
	int i,j,swapped,k;
	
	if(a==NULL){
		printf("申请失败");
		return 1;
	}
	
	printf("请输入姓名及成绩：（end结束）\n");
	char buf[20];
	while(1){
		scanf("%19s",buf );
		if (strcmp(buf, "end") == 0) break; 
		if(count==capacity){
		capacity = capacity * 2;
	    struct student *tmp2 = realloc(a, capacity * sizeof(struct student));
        if (tmp2 == NULL) {
        printf("扩容失败\n");
        free(a);            
         return 1;
	    }
        a = tmp2;
		}
		strcpy(a[count].name, buf);
		scanf("%d",&a[count].score );
		count++;
	    }
        for (i=0;i<count-1;i++){
		swapped=0;
		for (j=0;j<count-1-i;j++)
		if(a[j].score <a[j+1].score ){
			tmp=a[j];
			a[j]=a[j+1];
			a[j+1]=tmp;
			swapped=1;
		}
		if(swapped==0)break;
	    }
	    printf("成绩排名为：\n");
	    for(k=0;k<count;k++){
	    	printf("%19s %d\n",a[k].name ,a[k].score );
		}
		free(a);
		a=NULL;
		return 0;    
}
