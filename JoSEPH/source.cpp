#include <cstdlib>
#include <conio.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <windows.h>

using namespace std;

void Randominitialize(int&);


void initialize(int *&pa, int k);

void gotoRowCol(float rpos, float cpos);
void drawcircle(int *aptr, int size);
void delay();

void setcolor(int *pa,int k,int num,int,int);

void delvariable(int *&A, int val, int &size);
int findi(int *A, int val, int size);
void  regrow(int *&pa, int&currentsize, int newsize,int n);


int main()
{
    system("color 7");
	int n, k, r, p, count = 0, q;
	int * pa = 0;
	cout << "enter the number of persons  :";   cin >> n;
	k = n;                     //k=size of array;
	initialize(pa, k);
	drawcircle(pa, k);
	Randominitialize(p);
	Randominitialize(q);
	while (k > 1)
	{

		Randominitialize(r);

		if (count == p)
		{

			regrow(pa, k, k + q,n);
			

			system("CLS");
			drawcircle(pa, k);

		}
		count++;
	
		int j = 0;
		
		for (int i = 0; i <= r; i++)
		{
			pa[j];

			setcolor(pa, k, r,i,j+1);
		
				drawcircle(pa, k);
			
			j++;
			if (j == k)
				j = 0;
		}
		
		delvariable(pa, pa[j], k);
		system("CLS");
	
		system("color 7");
		drawcircle(pa, k);


	}
	cout << endl << "winner is " << pa[0];

	delete[] pa;

}




void drawcircle(int *aptr, int size)
{
	float x, y;
	int cx = 20;
	int cy = 20;
	int r = 10;

	int	z = (360 / size);
	int j = 0;
	for (int i = 1; i <= 360, j<size; i = i + z)
	{
		x = cx + r*cos((i*3.14) / 180);
		y = cy - r*sin((i*3.14) / 180);
		gotoRowCol(y, x);
		cout << *(aptr + j);
		j++;


	}
	cout << endl << "\n\n\n\n\n ";

}
void setcolor(int *aptr,int size,int num,int i2,int j2)
{
        	float x, y;
	        int cx = 20;
	        int cy = 20;
	        int r = 10;

	int	z = (360 / size);
	int j = 0;
	for (int i = 1; i <= 360, j<size; i = i + z)
	{
		x = cx + r*cos((i*3.14) / 180);
		y = cy - r*sin((i*3.14) / 180);
		gotoRowCol(y, x);
		if (num == i2)
		{
			delay();
			if (j == j2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				cout << *(aptr + j2);
				delay(); delay(); delay();
				
				break;

			}
			else
			  {
			

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);


			cout << *(aptr + j);
			delay(); delay();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			drawcircle(aptr, size);

		      }

        }


        else
        {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
			delay();
			cout << *(aptr + j);
			
			delay();  	delay();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			drawcircle(aptr, size);
			
			
        }
      
		j++;


	}
	cout << endl << "\n\n\n\n\n ";

}







void Randominitialize(int &num)
{

	srand(time(0));

	num = (rand() % 2) + 1;

}



void initialize(int *&pa, int k)
{

	pa = new int[k];
	for (int i = 0; i<k; i++)
	{
		*(pa + i) = i + 1;
	}
}






void delay()
{
	for (int i = 0; i <= 100000 * 1111; i++)
	{
	}
}





void delvariable(int *&A, int val, int &size)
{
	int index;
	index = findi(A, val, size);
	for (int j = index; j<size; j++)
	{
		*(A + j) = *(A + j + 1);

	}
	size--;


}

int findi(int *A, int val, int size)
{
	for (int i = 0; i<size; i++)
	{
		if (val == *(A + i))
			return i;
	}
}


void  regrow(int *&pa,int&currentsize,int newsize,int n)

{
	int x = 0;
	int *a = new int[newsize];
	for (int i = 0; i < currentsize; i++)
	{
		*(a + i) = *(pa + i);
		
	}
	for (int j =currentsize ; j < newsize; j++)
	{
		*(a + j) = n+ 1;
		n++;
	}

	
		currentsize = newsize;

	delete[] pa;
	pa = a;

}
void gotoRowCol(float rpos, float cpos)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int xpos = cpos, ypos = rpos;
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos;     scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}
