#include <iostream>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include<conio.h>
using namespace std;
using namespace std;

void initializeGame(char [5][5], int,int &);
int  displayboard(char[5][5],int,int);
void updateboard(char [5][5],int ,int ,int ,int ,int ,char);


int horizontalCheck(int ,int,int,int );
int digonalCheck(int ,int ,int ,int );
int verticalCheck(int ,int ,int ,int );
int horizontal_free(char [5][5], int ,int ,int ,int );
int vertical_free(char [5][5], int ,int ,int ,int );
int digonal_free(char [5][5], int ,int ,int ,int );


int isvalidsource(char[5][5],int,int,int,int,char &);
int isvaliddestination(char[5][5],int,int,int,int,int,int,char);


void changeplayer(int &);
void taketurn(int&,int&);


int iswin(char Cboard[5][5],int player,int dim);
int ownchesspiece(char [5][5],int,int,int);

int main()
{

    int SC,SR;                        //declaration
    int DR,DC;
    char p;
    int count=0;
    char Cboard[5][5];
    int player,dim=5;

    cout << "bead  player 1 / player 2  row 0 to 5 and column 0 to 5 " << endl;
    initializeGame(Cboard,dim,player);
      system("color 0C");
   do

{
     system("CLS");

    displayboard( Cboard, dim,player);

    do
    {
         cout<<"enter source row and coulumn \n";
        taketurn(SR,SC);
    }while(isvalidsource(Cboard,dim,SR,SC,player,p)==0);

    do
    {
        cout<<"enter destination row and coulumn \n";
        taketurn(DR,DC);
    }while(isvaliddestination(Cboard,dim,SR,SC,DR,DC,player,p)==0);

       updateboard(Cboard,dim,SR,SC,DR,DC,p);

      changeplayer(player);
}while( iswin( Cboard, player,dim)==0);
cout<<"player  "<<player<<"wins";


}



    void initializeGame(char Cboard[5][5],int dim,int &player )
    {
          for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
        {
             Cboard[i][j]='-';
             if(i==1||i==0)
             {
                 Cboard[i][j]='X';
             }
               if(i==3||i==4)
             {
                 Cboard[i][j]='O';
             }
}
    }
player=1;
    }

int displayboard(char Cboard[5][5],int dim,int player) // displaying board
{
    /*
cout<<"player "<<player<<endl<<endl<<endl;
    int Count=0;

	for(int row=0;row<dim;row++)
    {
        for(int col=0;col<dim;col++)
        {
             cout<<Cboard[row][col];
        cout<<"              ";
        Count++;
        if(Count==dim)
        {
            cout<<endl<<endl<<endl<<endl;
            Count=0;
        }
        }

    }
    */

     cout<<"\t\t\tBead 12 (12 Tehniii)\n\n\n\t";
	for (int i = 0; i < dim; i++)
    {
        cout << i << "     ";
    }
	cout << "\n      -------------------------------\n";
	int k= 0;
	cout << "   " <<k<< "  |";

	for (int r=0; r<dim; r++)
	{
	    for(int c=0;c<dim;c++)
        {
            cout << "  " << Cboard[r][c] << "  " << '|';
            if ( (c+1)%dim==0)
            {
                cout << "\n      -------------------------------\n";
                cout << "   " << ++k << "  |";
                if(k==dim)
                    break;
            }
        }
	}
	//gotoRowCol(15,0);
	cout<<"--->Player "<<player<<" Turn...\n";
}


void taketurn(int &row,int &col)  // taking inputs
 {
     cout<<"enter inputs\n:";
     cin>>row;
     cin>>col;
 }



int isvaliddestination(char Cboard[5][5],int dim,int SR,int SC ,int DR,int DC,int player,char p)
{
    int x=0;
    if( Cboard[DR][DC]!='-')
  return 0;

  if(horizontalCheck(SR,SC,DR,DC)==1)
  {
      if(abs(SC-DC)==1)
        return 1;
      if(horizontal_free(Cboard,SR,SC,DR,DC)==0&&abs(SC-DC)==2)
      {
          if(DC>SC)
            x=SC+1;
            else
            x=SC-1;

          if(Cboard[DR][x]!=p)
            return 1;
          else
            return 0;
      }
      return 0;

  }


 else if(verticalCheck(SR,SC,DR,DC)==1)
  {
      if(abs(SR-DR)==1)
        return 1;
      if(vertical_free(Cboard,SR,SC,DR,DC)==0&&abs(SR-DR)==2)
      {
          if(DR>SR)
            x=SR+1;
            else
            x=SR-1;

          if(Cboard[x][DC]!=p)
            return 1;
          else
            return 0;
      }
      return 0;

  }


  else if(digonalCheck(SR,SC,DR,DC)==1)
  {
      if(abs(SR-DR)==1)
        return 1;
      if(vertical_free(Cboard,SR,SC,DR,DC)==0&&abs(SR-DR)==2)
      {
          x=abs(SR-DR);
          if(Cboard[DR][x]!=p)
            return 1;
          else
            return 0;
      }
      return 0;

  }



}
int isvalidsource(char Cboard[5][5],int dim,int SR,int SC,int player,char &p) // checking inputs validation
 {

    int x,y;

    if(player==1)
    {
     x=88;
    }
     else
    {
         x=79;
    }
    if(SR>=0&&SR<dim&&SC>=0&&SC<dim)
    {
   if(  Cboard[SR][SC]!='-')
   {

        p=Cboard[SR][SC];
        if(p==x)
        return 1;

   }
   else
    return 0;
    }
    return 0;
}
void changeplayer(int&player)   // changing player
{
     if(player==1)
    {
        player=2;
        system("color 09");
    }
    else if(player==2)
    {
        player=1;
        system("color 0C");
    }
}



int horizontalCheck(int SR,int SC,int DR,int DC)     // fuction for checking moves
{
    if(SR==DR&&SC!=DC)
        return 1;
    else
        return 0;
}


int horizontal_free(char Cboard[5][5], int SR,int SC,int DR,int DC)
{
    if(SC<DC)
    {
    for(int row=SR,col=SC+1;col<DC;col++)
    {
    if(Cboard[row][col]!='-')
        return 0;
}
        return 1;
    }
    else if(SC>DC)
    {
         for(int row=SR,col=SC-1;col>DC;col--)
    {
    if(Cboard[row][col]!='-')
        return 0;
}
        return 1;
    }
}




int verticalCheck(int SR,int SC,int DR,int DC)
{
    if(SC==DC&&SR!=DR)
        return 1;
    else
        return 0;
}


int vertical_free(char Cboard[5][5], int SR,int SC,int DR,int DC)
{
    if(SR<DR)
    {
    for(int row=SR+1,col=SC;row<DR;row++)
    {
    if(Cboard[row][col]!='-')
        return 0;
}
        return 1;
}
else if(SR>DC)
 {
    for(int row=SR-1,col=SC;row>DR;row--)
    {
    if(Cboard[row][col]!='-')
        return 0;
    }
        return 1;
}

}


int digonalCheck(int SR,int SC,int DR,int DC)
{
    if(abs(SR-DR)==abs(SC-DC))
        return 1;
        else
            return 0;
}

int digonal_free(char Cboard[5][5], int SR,int SC,int DR,int DC)
{

if(SR<DR)
{
    for(int row=SR+1,col=SC;row<DR;row++)
    {
        if(SC<DC)
        col++;
    else
        col--;
    if(Cboard[row][col]!='-')
        return 0;

}
        return 1;
}
else if(SR>DR)
{
    for(int row=SR-1,col=SC;row>DR;row--)
    {
         if(SC<DC)
        col++;
    else
        col--;
    if(Cboard[row][col]!='-')
        return 0;

}
        return 1;
}
}




void  updateboard(char Cboard[5][5],int dim,int SR,int SC,int DR,int DC,char p)   // overwriting board
{
    int x=0;
    Cboard[DR][DC]=p;
    Cboard[SR][SC]='-';
    if(abs(SC-DC)==2)
    {
         if(DC>SC)
            x=SC+1;
            else
            x=SC-1;
          Cboard[DR][x]='-';
    }

    if(abs(SR-DR)==2)
    {

         if(DR>SR)
            x=SR+1;
            else
            x=SR-1;
          Cboard[x][DC]='-';
    }

}
int iswin(char Cboard[5][5],int player,int dim)
{
    if(player==1)
    {
           for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
        {
            if( Cboard[i][j]=='O')
            return 0;
    }

}
return 1;
    }



 else if(player==2)
    {
           for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
        {
            if( Cboard[i][j]=='X')
            return 0;
    }

}
return 1;
    }
}
