#include<iostream>
using namespace std;

//�ͷſռ�
//�ͷ�ָ��

void main()
{
	char *str = (char *)malloc(57);
	strcpy(str, "Bit");
	free(str);
	str = NULL;

	//free(str);  str==NULL  Ұָ��

	if (str != NULL)
	{
		strcpy(str, "C++");
		printf(str);
	}
}


/*
void GetMemory(char **p)
{
	*p = (char *)malloc(57);
}
void main()
{
	char *str = NULL;
	GetMemory(&str);
	strcpy(str, "Hello Bit.");
	printf(str);
	free(str); //�ڴ�й©
}


/*
char* GetMemory(void)
{
	static char p[] =  "Hello Bit.";
	return p;
}
void main()
{
	char *str = NULL;
	str = GetMemory();
	printf(str);
}


/*
void GetMemory(char **p)
{
	*p = (char*)malloc(57);
}
void main()
{
	char *str = NULL;
	GetMemory(&str);
	strcpy(str, "Hello Bit.");
	printf(str);
	free(str);
}


/*
int func(int a[])
{
	cout<<sizeof(a)<<endl;
	return 0;
}

void main()
{
	char str[] = "Welcome to Bit";
	int Array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	char *p = str;
	int  n;
	
	cout<<strlen(str)<<endl; //14
	cout<<sizeof(str)<<endl; //15
	cout<<sizeof(Array)<<endl; //36
	cout<<sizeof(p)<<endl;  //4
	cout<<sizeof(n)<<endl; //4
	func(Array);  //4
}


/*
void fun(int ar[10][10])
{
	cout<<sizeof(ar)<<endl; //
}

void main()
{
	int ar[10][10] = {0};
	fun(ar);
}

/*
void main()
{
	short *ar[10][10] = {0};
	cout<<sizeof(ar)<<endl; //4 200 400
}

/*
void main()
{
	char *str = "Hello";
	cout<<sizeof(str)<<endl; //4
	cout<<strlen(str)<<endl; //5

	char str1[] = "Hello";
	cout<<sizeof(str1)<<endl; //6
	cout<<strlen(str1)<<endl; //5

	char str3[10] = "Hello";
	cout<<sizeof(str3)<<endl; //10
	cout<<strlen(str3)<<endl; //5

	char str4[10];
	for(int i=0; i<5; ++i)
		str4[i] = 'a' + i;
	cout<<sizeof(str4)<<endl; //10
	cout<<strlen(str4)<<endl; //
}

/*
int fun(int a, int b)
{
	return a + b;
}

int* fun1(int ar[], int n)  //fun1��һ������ָ��ĺ���  ָ�뺯��
{
	for(int i=0; i<n; ++i)
		ar[i] = i+1; //1 2 ...n
	return ar;
}

int main(int argc, char *argv[])
{
	int ar[3] = {10,20,30};
	int (*pa)[3] = &ar;  //pa ��ָ�������ָ��   ����ָ��

	int a=10, b=20, c=30;
	int* pb[3] = {&a, &b, &c}; //pb �Ǳ���ָ�������  ָ������

	int(*pfun)(int,int); //pfun ��һ��ָ������ָ��  ����ָ��
	pfun = fun;
	cout<<pfun(10,20)<<endl;

	return 0;
}
*/