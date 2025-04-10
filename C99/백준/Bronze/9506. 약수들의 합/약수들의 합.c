#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define AND &
struct arraylist {
  int length;
  int head;
  int *data;
  void (*push)(struct arraylist *arr, int);
  int (*pop)(struct arraylist *arr);
};

void push(struct arraylist *arr, int x) {
  arr->length++;
  arr->data[arr->head+arr->length-1] = x;
}

int pop(struct arraylist *arr) {
  int ret = arr->data[arr->head];
  arr->head++;
  arr->length--;
  return ret;
}

void new_array(struct arraylist *arr, int cap) {
  memset(arr,0,sizeof(struct arraylist));
  arr->push = push;
  arr->pop = pop;
  arr->length = 0;
  arr->data = malloc(sizeof(int)*cap);
}


struct arraylist factorization(int x) {
  struct arraylist factorized;
  new_array(&factorized,x/2);
  for(int i = 1; i <= x/2; i++) {
    if(!(x%i)) {
      factorized.push(&factorized, i);
    }
  }
  return factorized;
}

int main() {
  int x = 0;
  for(int i = 0;;i++) {
    scanf("%d",&x);
    if(x==-1) break;
    struct arraylist arr = factorization(x);
    int sum = 0;
    int hyperfect = 0;
    struct arraylist arr2;
    memcpy(&arr2,&arr,sizeof(struct arraylist));
    while(arr.length) {
      int measure = arr.pop(&arr);
      sum += measure;
    }
    if(sum==x) hyperfect = 1;
    if(!hyperfect) {
      printf("%d is NOT perfect.\n", x);
      continue;
    }
    printf("%d =", x);
    while(arr2.length) {
      if(arr2.length>1)
        printf(" %d ", arr2.pop(&arr2));
      else 
        printf(" %d\n", arr2.pop(&arr2));
      if(arr2.length) printf("+");
    }
  }
  return 0;
}
