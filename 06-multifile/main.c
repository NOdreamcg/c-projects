#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(void){
	int n;
	if (scanf("%d", &n) != 1 || n <= 0) {
    printf("人数不合法\n");
    return 1;
    }
	struct student *list = malloc(n * sizeof(struct student));
    if (list == NULL) {
    printf("内存申请失败\n");
    return 1;
    }
    input(list,n);
    if (save(list, n) != 1) {
	 printf("处理失败");
	 free(list);
	 return 1;
	 }
    if (load(list, n) != 1) {
	 printf("处理失败");
	 free(list);
	 return 1;
	 }
    print(list,n);
    
    free(list);
    return 0;
}
