//�ޤJ�зǿ�J��X : printf , scanf
#include <stdio.h>
//�ޤJ�зǨ禡(system,malloc)
#include <stdlib.h>
//�ޤJ�r��B�z�禡
#include <string.h>
//�ޤJ�ɶ��B�z�禡(clock, CLOCKS_PER_SEC)
#include <time.h>
//�w�q�b����{���� MAXCHAR �N�O 100
#define MAXCHAR 255
int ReverseOrder(char *a, int N); 
int main()
{
	int i ,j ,Na ,Nb ,Nc ,P ,w ,W ,N ,Ninv ,*x ,*X ,*y ,*Y ;
	
	/*int multiplication is not working
	printf("input i , j = ");
	scanf("%d %d",&i,&j);
	printf("%d ",i*j);
	return 0;
	*/
	
	char a[MAXCHAR] ,b[MAXCHAR] ,c[2*MAXCHAR] ,t;
	/*
	printf("input a:");
	scanf("%s",a);
	printf("%s\n",a);
	//��J : 12345 , ascii table �q���̦s�� 49 51 52 53 
	for(i=0;i<strlen(a);i++){
		printf("%d ",a[i]);
	}
	return 0;
	*/
	/*
	a = (char *)malloc(MAXCHAR*sizeof(char));
	b = (char *)malloc(MAXCHAR*sizeof(char));
	c = (char *)malloc(2*MAXCHAR*sizeof(char));  
	*/
	clock_t t1, t2 ;
	// �Φr���J a,b
	printf("Input number a and b (MAXIMUM DIGITS:%d)\n",MAXCHAR);
	// ��J�r��,%s�O�ۦꪺ�N�q
	scanf("%s %s", a, b);
	// �L�X�r��,%s�O�r�ꪺ�N�q
	printf("%s * %s = \n",a,b);
	//for(i=0;i<MAXCHAR-1;++i) a[i] = b[i] = '9';
	//��X�r��a,b������(strlen) 
	Na = strlen(a); 
	Nb = strlen(b);	
	//�Na,b���줸���Ǥ���. EX : a = 1234 -> 4321
	ReverseOrder(a,Na);
 	ReverseOrder(b,Nb);
	//�Na,b�q�r���ন0-9���Ʀr ,�igoogle : ascii code, 48 = '0', ..... 
	Char2Int(a,Na);
	Char2Int(b,Nb);			
	// �� a , b�����k(�зǰ�p���k)
	t1 = clock();
	Nc = Multiply(c, a, Na, b, Nb);
	t2 = clock(); 
	printf("%f\n", 1.0*(t2-t1)/CLOCKS_PER_SEC);
	// ��c���줸���ǰf��
	ReverseOrder(c, Nc);
	for(i=0;i<Nc;++i) printf("%d",c[i]);
	printf("\n");
	// ��c���Ʀr�ܦ^�r��
	// Int2Char(c,Nc);
	// �L�Xc�� 
	// printf("%s\n", c); 
	P = Find 
	
	
	
	
	 
} 

int ReverseOrder(char *a, int N)
{
	// 0 <-> N-1
	// 1 <-> N-2
	// 2 <-> N-3
	// ... 
	int i,j;
	char t;
	for(i=0;i<N/2;++i)
	{
		j = N - 1 - i;
		t = a[i];
		a[i] = a[j]; 
		a[j] = t;  
	} 
	return 0; 
} 

int Char2Int(char *a, int N) 
{
	int i;
	for(i=0;i<N;++i)
	{
		a[i]-=48; 
	} 
	return 0; 
} 








