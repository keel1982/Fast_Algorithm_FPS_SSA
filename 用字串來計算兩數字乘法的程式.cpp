//�ޤJ�зǿ�J��X : printf , scanf
#include <stdio.h>
//�ޤJ�зǨ禡(system,malloc)
#include <stdlib.h>
//�ޤJ�r��B�z�禡
#include <string.h>
//�ޤJ�ɶ��B�z�禡(clock, CLOCKS_PER_SEC)
#include <time.h>
//�w�q�b����{���� MAXCHAR �N�O 400
#define MAXCHAR 400
int ReverseOrder(char *a, int N); 
int Char2Int(char *a, int N) ;
int Multiply(char *c, char *a, int Na, char *b, int Nb);
int Find_A_Prime(int Na, int Nb, int *Nf, int *w, int *W, int *Ninv);
int Check_A_Prime(int P);
int Order(int w, int P);
int Inverse_Zp(int w, int P);
int SFT(int *X, int *x, int N, int w, int P);

int main()
{
	int i ,j ,Na ,Nb ,Nc ,P ,w ,W ,N ,Ninv ,*x ,*X ,*y ,*Y;
	/*
	for(i=3;i<100;i+=2)
	{
		printf("%d:%d\n",i,Check_A_Prime(i));
	}
	return 0;
	*/
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
	printf("%s * %s = \n", a, b);
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
	for(i=0;i<Na;++i) printf("%d",a[i]);
	printf("\n");	
	for(i=0;i<Nb;++i) printf("%d",b[i]);
	printf("\n");			
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
	P = Find_A_Prime(Na,Nb,&N,&w,&W,&Ninv);
	printf("FFT in Z[%d], with w = %d, W = %d, N = %d, Ninv = %d\n", P, w, W, N, Ninv);

	x = (int *) malloc(N*sizeof(int));
	y = (int *) malloc(N*sizeof(int));
	X = (int *) malloc(N*sizeof(int));
	Y = (int *) malloc(N*sizeof(int));
	for(i=0;i<N;++i)
	{
		x[i] = y[i] = X[i] = Y[i] = 0;
	}
	for(i=0;i<Na;++i) x[i] = a[i];
	for(i=0;i<Nb;++i) y[i] = b[i];
	t1 = clock();
	SFT(X,x,N,w,P);
	SFT(Y,y,N,w,P);
	for(i=0;i<N;++i) X[i] = ((X[i]*Y[i] % P) * Ninv) % P; 
	//for(i=0;i<N;++i) printf("%d ",X[i]);	
	SFT(x ,X ,N ,W ,P);
	for(i=0;i<N;++i) printf("%d ",x[i]);
	for(i=0;i<N-1;++i)
	{
		x[i+1] += x[i]/10;
		x[i] = x[i] % 10;
		printf("%d\n",x[i]);
	}
	for(i=0;i<Nc;++i) c[i] = x[i];
	t2 = clock();
	ReverseOrder(c, Nc);
	for(i=0;i<Nc;++i) printf("%d",c[i]);
	printf("\n");
	printf("%f\n", 1.0*(t2-t1)/CLOCKS_PER_SEC);
	printf("\n");		
	system("pause");
	return 0;
} 
int ReverseOrder(char *a, int N)
{
	// i <-> j
	// 0 <-> N-1
	// 1 <-> N-2
	// 2 <-> N-3
	// ...
	int i, j;
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
		a[i] -= 48;
	}
	return 0;
}
int Int2Char(char *a, int N)
{
	int i;
	for(i=0;i<N;++i)
	{
		a[i] += 48;
	}
	a[N] = 0;
	return 0;
}
int Multiply(char *c, char *a, int Na, char *b, int Nb)
{
	int i, j;
	for(i=0;i<Na+Nb;++i) c[i] = 0;

	for(i=0;i<Na;i++)
	{
		for(j=0;j<Nb;j++)
		{
			c[i+j] += a[i]*b[j];
			if(c[i+j] >= 10)
			{
				c[i+j+1] += (c[i+j] / 10);  // ?L?????h 
				c[i+j] = c[i+j] % 10;
			}
		}
	}
	if(c[Na+Nb-1]==0) return Na+Nb-1; // highest bit = 0 -> ????1 
	else return Na+Nb;
}
int Find_A_Prime(int Na, int Nb, int *Nf, int *w, int *W, int *Ninv)
{
	int Nm, p, n, N, find_w;
	if(Na > Nb) Nm = Na; else Nm = Nb;  // maximum of Na and Nb
	N = 1;
	while(N<2*Nm)   // Nm = D
	{
		N <<= 1;    // N = N * 2
	}
	*Nf = N;
	p = 81*(N/2)+1;  // p = 81*Nm + 1
	if (p % 2 == 0) p = p + 1;
	while(1)
	{
		if(Check_A_Prime(p)==1)
		{
			if( (p - 1) % N == 0)
			{
				find_w = 0;
				for(n=2;n<p;++n)
				{
					if(Order(n,p)==N)
					{
						find_w = 1;
						break;
					}
				}
				if(find_w == 1) break;
			}
		}
		p += 2;
	}
	*w = n;
	*W = Inverse_Zp(n,p);
	*Ninv = Inverse_Zp(N,p);
	return p;
}
int Check_A_Prime(int P)
{
	// not a prime : 0 .  A prime : 1
	if(P % 2 == 0)
	{
		return 0;
	}
	int n;
	for(n=3; n*n<=P ;n+=2)
	{
		if(P % n == 0)
		{
			return 0;
		}
	}
	return 1;
}
int Order(int w, int p)
{
	int k, w0 = w;
	for(k=1;k<p;++k)
	{
		if(w % p == 1)
			break;
		w = (w*w0) % p;
	}
	return k;
}
int Inverse_Zp(int w, int p)
{
	int k, w0 = w;
	for(k=1;k<p;++k)
	{
		if((w*w0) % p == 1)
			break;
		w = (w*w0) % p;
	}
	return w;
}
int SFT(int *X, int *x, int N, int w, int P)
{
	int i, j, w0, wk;
	wk = 1;
	for(i=0;i<N;++i)
	{
		X[i] = 0; w0 = 1;
		for(j=0;j<N;++j)
		{
			X[i] += (w0*x[j]) % P;
			X[i] = (X[i] % P);
			w0 = (w0*wk) % P;
		}
		wk = (wk*w) % P;
		//X[i] = (X[i] % P);
	}
}
