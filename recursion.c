#include <stdio.h>
//implementing all functions related to recursion
//factorial
int fact(int n){
	if(n==1)
		return 1;
	return (n*fact(n-1));
}
//Tower of Hanoi
void TOH(int n, char S,char T,char D){
	if(n==1){
		printf("%c->%c\n",S,D);
		return;
	}
	else{
		TOH( n-1, S, D,T);
		printf(" %c -> %c\n",S,D);
		TOH(n-1,T,S,D);
	}
}
//GCD
int gcd(int a , int b){
	if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main(int argc, char const *argv[])
{
	printf("%d",fact(5));
	TOH(3,'A','B','C');
	printf("%d",gcd(10,5));
	return 0;
}