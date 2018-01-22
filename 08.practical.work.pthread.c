  GNU nano 2.5.3                                               File: 08.practical.work.pthread.c                                                                                            Modified  

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10





typedef struct{
  char type;
  int amount;
 char unit;
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last =0;

void *print_message_function( void *ptr ){
 char *message;
 message = (char *) ptr;
 printf("%s \n", message);
 }




void produce(item *i){
 while( (first+1) % BUFFER_SIZE == last){
     }
 memcpy(i, &buffer[last], sizeof(item));
 first = (first+1) % BUFFER_SIZE;
}

item *consume(){
 item *i = malloc(sizeof(item));
 while(first==last){
   }
 memcpy(i, &buffer[last], sizeof(item));
int main(){

 pthread_t thread1, thread2;
 const char *message1 = "Thread 1";
 const char *message2 = "Thread 2";
 int iret1,iret2;

 item *left = malloc(sizeof(item));
 left->type='0';
 left->amount=23;
 left->unit='1';

 item *right = malloc(sizeof(item));
 right->type='0';
 right->amount=22;
 right->unit='1';

 item *middle = malloc(sizeof(item));
 middle->type='0';
 middle->amount=23;
 middle->unit='1';

 iret1 = pthread_create(&thread1, NULL, print_message_function, (void*) message1);
 if(!iret1){
 printf("Thread 1 is created for producer\n");
 produce(left);
 produce(right);
 produce(middle);
 printf("First is %d and Last is %d \n",buffer[first].amount,buffer[last].amount);
 }

 iret2=pthread_create(&thread2, NULL, print_message_function, (void*) message2);
 if(!iret2){
 printf("Thread 2 is created for comsumer\n");
 consume(left);
 consume(right);
 printf("First is %d and Last is %d\n",buffer[first].amount, buffer[last].amount);
 }


 pthread_join(thread1,NULL);
 pthread_join(thread2,NULL);
 exit(EXIT_SUCCESS);
printf("Done");
} 




