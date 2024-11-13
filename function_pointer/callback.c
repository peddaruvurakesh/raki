#include <stdio.h>

void hello(){
   printf("Hello World\n");
}

void callback(void (*ptr)()){

   printf("Calling a function with its pointer\n");
   
   (*ptr)();   // calling the callback function
}

int main(){

   void (*ptr)() = hello;

   callback(ptr);
}
