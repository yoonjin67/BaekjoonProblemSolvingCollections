#include <stdio.h>
#define print(x) main(x)
#define hello(x) puts(x)
typedef int world;
#define string "Hello World!"
world print(){
	hello(string);
}