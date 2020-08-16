#include<iostream>
#include<assert.h>
using namespace std;

class A
{
public:
	virtual void sayhello()
	{
		cout << "hello A" << endl;
	}
private:
};

class B: public A
{
public:
	virtual void sayhello()
	{
		cout << "hello B" << endl;
	}
private:
	int a;
	int b;
	int x;
};

void main()
{
	B b;
	memset(&b, 0, sizeof(b));  //?????

	A *pa = &b;
	pa->sayhello();
}

/*
int main()
{
	A *pa = NULL;
	pa->sayhello();

	B *pb = NULL;
	pb->sayhello();
	
	system("pause");
	return 0;
}


/*
class Base
{
public:
	virtual void f()
	{
		this->print(); 
	}
	virtual void print(int i=6)
	{
		cout<<"Base:"<< i*i <<endl;
	}
};

class Derived : public Base
{
public:
	virtual void f()
	{
		this->print();  //
	}
	virtual void print(int i=10)
	{
		cout<<"Derived" << i*i<<endl;
	}
};

void bar(Base* p)
{
	p->print();
	p->f();
}
 
int main()
{
	Base * p = new Base;
	bar(p);

    Derived  * q = new Derived();
    bar(q);
	//q->print();
	//q->f();


	Base * r = (Base *)new Derived();
	bar(r);

	system("pause");
	return 0;
}


/*
class animal
{
protected:
	int age;
public:
	virtual void print_age(void) = 0;
};
class dog : public animal
{
public:
	dog(){ this->age = 2; }
	~dog(){}
	virtual void print_age(void){ cout << "wang. my age=" << this->age << endl; }
};
class cat :public animal
{
public:
	cat(){ this->age = 1; }
	~cat(){}
	virtual void print_age(void){ cout << " Miao,my age= " << this->age << endl; }
};
int main(void)
{
	cat kitty;
	dog jd;

	animal *pa;
	int *p = (int *)(&kitty);
	int *q = (int *)(&jd);

	p[1] = q[1] = 2;
	
	pa = &kitty;
	pa->print_age();
	pa = &jd;
	pa->print_age();
	return 0;
}


/*
class Base
{
public:
	int Bar(char x)
	{
		return (int)(x);
	}
	virtual int Bar(int x)
	{
		return (2 * x);
	}
};
class Derived : public Base
{
public:
	int Bar(char x)
	{
		return (int)(-x);
	}
	int Bar(int x)
	{
		return (x / 2);
	}
};
int main(void)
{
	Derived Obj;
	Base *pObj = &Obj;
	printf("%d,", pObj->Bar((char)(100)));  //100
	printf("%d,", pObj->Bar(100));          //50
}


/*
//�ڴ�й©�ļ��

int GoodBye()
{
	cout<<"GoodBye."<<endl;
	return 0;
}

void main()
{
	//atexit(GoodBye);
	_onexit(GoodBye);
	//..................
	cout<<"Main End."<<endl;
	return;
}

/*
void main()
{
	// log
	cout<<__FILE__<<endl;
	cout<<__LINE__<<endl;
	cout<<__DATE__<<endl;
	cout<<__TIME__<<endl;
}

/*
int fun(int a, int b)
{
	return a + b;
}
void main()
{
	fun(10, 20);

	int(*pfun)(int, int);
	pfun = fun;

	//(*pfun)(10,20);
	(*(int(*)(int, int))0)(10,20);

}

/*
1��int *(*(*fun)(int*))[10];

2��int (*fun)(int *, int (*)(int *));

3��int (*fun[5])(int *);

4��int (*(*fun)[5])(int *);

5��int (*(*fun)(int *)) [5];

6��int*(*fun(int*))[5]

7��(*(void(*)())0)()

8��int *(*p(int))[3];

/*
class SmallInt
{
public:
	SmallInt(int i = 0);
	//���ز���ͳ�ȡ�����
	friend ostream &operator<<(ostream&os, const SmallInt &si);
	friend istream &operator>>(istream &is, SmallInt &si);

	//�������������
	SmallInt operator+(const SmallInt &si){ return SmallInt(val + si.val); }
	SmallInt operator-(const SmallInt &si){ return SmallInt(val - si.val); }
	SmallInt operator*(const SmallInt &si){ return SmallInt(val*si.val); }
	SmallInt operator/(const SmallInt &si){ return SmallInt(val / si.val); }
	//���رȽ������
	bool operator==(const SmallInt &si){ return (val == si.val); }

	SmallInt& operator+=(const SmallInt &si)
	{
		val += si.val;
		
		while (val > 127)
			val -= 256;
		while (val < -128)
			val += 256;
		return *this;
	}
	SmallInt& operator+=(const SmallInt &si)
	{
		SmallInt tmp(val + si.val);
		*this = tmp;
		return *this;
	}
	SmallInt& operator+=(const SmallInt &si)
	{
		*this = *this + si;
		return *this;
	}
private:
	char val;
};

SmallInt::SmallInt(int i)
{
	while (i > 127)
		i -= 256;
	while (i < -128)
		i += 256;
	val = i;
}

ostream &operator<<(ostream &os, const SmallInt &si)
{
	os << (int)si.val;
	return os;
}

istream &operator>>(istream &is, SmallInt &si)
{
	int tmp;
	is >> tmp;
	si = SmallInt(tmp);
	return is;
}

void main()
{

}

/*
class A
{
private:
	//��������Ա
	static int object_count;
public:
	A()
	{
		object_count++;
	}
	~A()
	{
		object_count--;
	}
	static int GetObjectCount()
	{
		return object_count;
	}
	virtual void func(int data){ cout << "class A : " << data << endl; }
	void func(char *str){ cout << "class A : " << str << endl; }
};

class B : public A{
	//��������Ա
public:
	void func() { cout << "function in B without parameter!\n"; }
	void func(int data) { cout << "class B : " << data << endl; }
	void func(char *str){ cout << "class B : " << str << endl; }
};

int A::object_count = 0;

void main()
{
  A *pA=new A[3];
  cout<<"There are "<<pA->GetObjectCount()<<" objects"<<endl;
  delete []pA;
  cout<<"There are "<<A::GetObjectCount()<<" objects"<<endl;
}


/*
int main(int argc, char *argv[])
{
	A *pA;
	B b;
	pA = &b;
	pA->func(1);
	pA->func("haha");
	return 0;
}


/*
//sum(n) = 1^2 + 2^2 + ..... n^2
long sum(int n)
{
	if(n == 1)
		return 1;
	else
		return sum(n-1)+n*n;
}

void main()
{
	cout<<sum(5)<<endl;
}

/*
int CalcDigital(char *str)
{
	assert(str != NULL);
	
	int count = 0;
	while(*str != '\0')
	{
		//if(*str>='0' && *str<='9')
		if(isdigit(*str))
			count++;
		str++;
	}
	return count;
}

void main()
{
	char *str = "ol4739ympic2000";
	//char *str = NULL;
	cout<<"count = "<<CalcDigital(str)<<endl;
}
*/