#include <iostream>
#include <windows.h>
#include <math.h>
#include<conio.h>
#include<stdlib.h>


using namespace std;
void initializeGame(char GRID[3][3], int dim,int&player);
int updateboard(char [3][3],int,int,int,int);
int iswin(char[3][3],int,int);
int  displayboard(char[3][3],int);
void gotoRowCol(int rpos, int cpos);



int  isdraw(char [3][3],int);
void taketurn(int&,int&);
int isvalidinput(char[3][3],int,int,int);
int index(int r,int c,int dim);
void changeplayer(int&player);





int main()
{

     cout<<"tic tac to\n";
    const int Size=100;
    char GRID[3][3];
    int dim,r,c,player;
    do
    {
    cout<<"enter dimension ";
    cin>>dim;
    }while(dim<3);
    initializeGame(GRID,dim,player);
    do
{
    system("CLS");
      displayboard(GRID,dim);
    do
    {
        cout<<"\n enter row and column";
        taketurn(r,c);
    }while(isvalidinput(GRID,dim,r,c)==0);
    updateboard(GRID,r,c,player,dim);
    if(iswin(GRID,player,dim)==1)
    {
        cout<<endl<<"player "<<player<<" wins "<<endl<<endl;
        break;
    }
  changeplayer(player);
}while(isdraw(GRID,dim)==0);
displayboard(GRID,dim);


    return 0;
}
void initializeGame(char GRID[3][3], int dim,int &player)
{
    for(int i=0;i<dim;i++)
    {
         for(int j=0;j<dim;j++)
         {

       GRID[i][j]='-';


         }
player=1;
}
}
void taketurn(int&r,int&c)
{
    cout<<"(r and c) should be greater than o and < dim\n";
    cout<<"enter row ";

cin>>r;
cout<<"enter column ";
cin>>c;
}
int isvalidinput(char GRID[3][3],int dim,int r,int c)
{
    if(r>=0&&r<dim&&c>=0&&c<dim)
    {
   if(  GRID[r][c]=='-')
   {
       return 1;
   }
   else
    return 0;
    }
    return 0;
}
int index(int r,int c,int dim)
{
    return(r-1)*dim+(c-1);
}


void changeplayer(int&player)
{
    if(player==1)
    player=2;
    else if (player==2)
    player=1;
}




int iswin(char GRID[3][3],int player,int dim)
{
    int Count=0,x=0,y=0,z=0,a=0,b=0;
     char sym;
        if(player==1)
            sym='x';
        else
            sym='o';
    for(int i=0;i<dim;i++)     // horizontal
    {
        Count=0;

        for(int j=0;j<dim;j++)
        {
            if(GRID[i][j]==sym )
                Count++;

        }
        if(Count==dim)
            return 1;
        }
         for(int k=0;k<dim;k++)    // vertical
    {
        x=0;

        for(int l=0;l<dim;l++)
        {
            if(GRID[l][k]==sym )
                x++;

        }

        if(x==dim)
            return 1;
    }

       for(int m=0;m<dim;m++)      // diagonal 1
    {

        for(int n=0;n<dim;n++)
        {
            if(m==n)
            {
            if(GRID[m][n]==sym )
                y++;

        }
         if(y==dim)
            return 1;

        }

    }

       for(int p=0;p<dim;p++)        // diagonal 2
    {
              if(GRID[p][2-p]==sym )
                z++;

         if(z==dim)
            return 1;

        }
        return 0;

}
int updateboard(char GRID[3][3],int r,int c,int player, int dim)
{
    int boxdim=5,x,y;

    x=r*boxdim-(boxdim)/2;
    y=(boxdim+1)/2+(c-1)*boxdim;
   //  gotoRowCol(x,y);
     if(player==1)
     {

         GRID[r][c]='x';

     }

     else if(player==2)
     {
           GRID[r][c]='o';
     }

}
int displayboard(char GRID[3][3],int dim)
{

    int Count=0;

    for(int r=0;r<dim;r++)
    {
        for(int c=0;c<dim;c++)
        {
             cout<<GRID[r][c];
        cout<<"       ";
        Count++;
        if(Count==dim)
        {
            cout<<endl<<endl;
            Count=0;
        }
}
    }
}
void gotoRowCol(int rpos, int cpos)
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    int xpos=cpos, ypos = rpos;
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos;     scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput,scrn);
}
int  isdraw(char GRID[3][3],int dim)
{
      for(int i=0;i<dim;i++)
    {
         for(int j=0;j<dim;j++)
         {
        if (GRID[i][j]=='-')
            return 0;
         }

}
cout<<"\n GAME IS DRAW "<<endl<<endl;
return 1;
}


