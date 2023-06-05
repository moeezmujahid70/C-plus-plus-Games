#include <iostream>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include<conio.h>


using namespace std;

void initializeGame(char [8][8], int,int &);
int  displayboard(char[8][8],int,int);
void updateboard(char [8][8],int ,int ,int ,int ,int ,char);


int horizontalCheck(int ,int,int,int );
int digonalCheck(int ,int ,int ,int );
int verticalCheck(int ,int ,int ,int );
int horizontal_free(char [8][8], int ,int ,int ,int );
int vertical_free(char [8][8], int ,int ,int ,int );
int digonal_free(char [8][8], int ,int ,int ,int );


int isvalidsource(char[8][8],int,int,int,int,char &);
int isvaliddestination(char[8][8],int,int,int,int,int,int,char);


void changeplayer(int &);
void taketurn(int&,int&);


int iswin(char [8][8],int );
int ownchesspiece(char [8][8],int,int,int);

int main()
{
    int SC,SR;                        //declaration
    int DR,DC;
    char p;
    int count=0;
    char Cboard[8][8];
    int player,dim=8;

    cout << "Chess  player 1 / player 2  row 0 to 7 and column 0 to 7 " << endl;
    initializeGame(Cboard,dim,player);
    system("color 0C");
    do

{
   system("CLS");            // for clearing screen
    displayboard( Cboard, dim,player);

    do
    {
         count=0;
         previous:
         cout<<"enter source row and coulumn \n";
        taketurn(SR,SC);


    }while(isvalidsource(Cboard,dim,SR,SC,player,p)==0);
    do
    {
        cout<<"enter destination row and coulumn \n";
        taketurn(DR,DC);
        count++;
        if(count==3)
        {
            count=0;
            goto previous;        // if dc and dr are false 3 times it will goto sr sc function again
        }

    }while(isvaliddestination(Cboard,dim,SR,SC,DR,DC,player,p)==0);

     updateboard(Cboard,dim,SR,SC,DR,DC,p);

      changeplayer(player);
}while(1);
    /*


if(iswin(Cboard,dim)==1)
{
    break;
}
    }while(1);
    return 0;
}
*/
}
void initializeGame(char Cboard[8][8],int dim,int &player ) // initializing board row / col 0 t0 7
{
     for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
        {
             Cboard[i][j]='-';
             if(i==1)
             {
                 Cboard[i][j]='p';
             }
               if(i==6)
             {
                 Cboard[i][j]='P';
             }
             if(i==7)
             {
                 if(j==0||j==7)
                     Cboard[i][j]='R';
                 else if(j==1||j==6)
                    Cboard[i][j]='N';
                 else if(j==2||j==5)
                    Cboard[i][j]='B';
                      else if(j==3)
                    Cboard[i][j]='Q';
                     else if(j==4)
                    Cboard[i][j]='K';
             }
               if(i==0)
             {
                 if(j==0||j==7)
                     Cboard[i][j]='r';
                 else if(j==1||j==6)
                    Cboard[i][j]='n';
                 else if(j==2||j==5)
                    Cboard[i][j]='b';
                      else if(j==3)
                    Cboard[i][j]='q';
                     else if(j==4)
                    Cboard[i][j]='k';
             }

        }


}
player=1;

}
int displayboard(char Cboard[8][8],int dim,int player) // displaying board
{
    /*
cout<<"player "<<player<<" turn  Row col 0 t0 7 << "<<endl<<endl;
    int Count=0;

	for(int row=0;row<dim;row++)
    {
        for(int col=0;col<dim;col++)
        {
             cout<<Cboard[row][col];
        cout<<"       ";
        Count++;
        if(Count==dim)
        {
            cout<<endl<<endl;
            Count=0;
        }
        }

    }
*/


 cout<<"\t\t\tCHESS\n\n\n\t";
	for (int i = 0; i < 8; i++)
    {
        cout << i << "     ";
    }
	cout << "\n      -------------------------------------------------\n";
	int k= 0;
	cout << "   " <<k<< "  |";
	for (int i = 0; i<dim; i++)
	{
	    for(int j=0;j<dim;j++)
        {
        cout << "  " << Cboard[i][j] << "  " << '|';
            if ( (j+1)%dim==0)
            {
            cout << "\n      -------------------------------------------------\n";
            cout << "   " << ++k << "  |";
            if(k==dim)
            break;
            }
            }
         if(k==dim)
          break;
	}
	// gotoRowCol(21,0);
	cout<<"--->Player "<<player<<" Turn...\n";


}

 int isvalidsource(char Cboard[8][8],int dim,int SR,int SC,int player,char &p) // checking inputs validation
 {

    int x,y;

    if(player==1)
    {
     x=97;
     y=120;
    }
     else
    {
         x=65;
         y=90;
    }
    if(SR>=0&&SR<dim&&SC>=0&&SC<dim)
    {
   if(  Cboard[SR][SC]!='-')
   {

        p=Cboard[SR][SC];
        if(p>=x&&p<=y)
        return 1;

   }
   else
    return 0;
    }
    return 0;
}

int isvaliddestination(char Cboard[8][8],int dim,int SR,int SC ,int DR,int DC,int player,char p)
{
    if( Cboard[DR][DC]!='-')
    {
  int  check=ownchesspiece(Cboard,player,DR,DC);
  if(check==0)
  return 0;
    }

    if(p=='Q'||p=='q')                             // different functions for each piace
    {
        if(horizontalCheck( SR,SC,DR,DC)==1)
           {
               if(horizontal_free(Cboard,SR,SC,DR,DC)==1)
                return 1;
                else
                    return 0;
           }

           if(verticalCheck( SR,SC,DR,DC)==1)
           {
               if(vertical_free(Cboard,SR,SC,DR,DC)==1)
                return 1;
                else
                    return 0;
           }

            if(digonalCheck( SR,SC,DR,DC)==1)
           {
               if(digonal_free(Cboard,SR,SC,DR,DC)==1)
                return 1;
                else
                    return 0;
           }

           return 0;


    }
else if(p=='r'||p=='R')
    {
        if(horizontalCheck( SR,SC,DR,DC)==1)
           {
               if(horizontal_free(Cboard,SR,SC,DR,DC)==1)
                return 1;
                else
                    return 0;
           }

           if(verticalCheck( SR,SC,DR,DC)==1)
           {
               if(vertical_free(Cboard,SR,SC,DR,DC)==1)
                return 1;
                else
                    return 0;
           }

           return 0;

    }
    else if(p=='b'||p=='B')
        {
         if(digonalCheck( SR,SC,DR,DC)==1)
           {
               if(digonal_free(Cboard,SR,SC,DR,DC)==1)
                return 1;
                else
                    return 0;
           }
           return 0;

    }
    else if(p=='n'||p=='N')
    {
        if(abs(SR-DR)==1&&abs(SC-DC)==2||abs(SR-DR)==2&&abs(SC-DC)==1)
            return 1;
        else
            return 0;
    }
      else if(p=='k'||p=='K')
    {
        if(abs(SR-DR)<=1&&abs(SC-DC)<=1)
            return 1;
        else
            return 0;
    }

     else if(p=='p')
    {
          if(digonalCheck( SR,SC,DR,DC)==1&&DR-SR==1&&Cboard[DR][DC]!='-')
         {
             return 1;
         }
        if(verticalCheck(SR,SC,DR,DC)==1&&DR-SR==1&&Cboard[DR][DC]=='-')

            return 1;
        else
            return 0;
    }
 else if(p=='P')
    {
         if(digonalCheck( SR,SC,DR,DC)==1&&DR-SR==-1&&Cboard[DR][DC]!='-')
         {
             return 1;
         }
        if(verticalCheck(SR,SC,DR,DC)==1&&DR-SR==-1&&Cboard[DR][DC]=='-')

            return 1;
        else
            return 0;
    }

}

int horizontalCheck(int SR,int SC,int DR,int DC)     // fuction for checking moves
{
    if(SR==DR&&SC!=DC)
        return 1;
    else
        return 0;
}


int horizontal_free(char Cboard[8][8], int SR,int SC,int DR,int DC)
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


int vertical_free(char Cboard[8][8], int SR,int SC,int DR,int DC)
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

int digonal_free(char Cboard[8][8], int SR,int SC,int DR,int DC)
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


int ownchesspiece(char Cboard[8][8], int player,int DR,int DC)  // prevent killing own pieace
{
     int x,y;
     if(player==1)
     {
     x=97;
     y=120;
     }
     else
     {
         x=65;
         y=90;
     }
     for(int i=x;i<y;i++)
     {
     if( Cboard[DR][DC]==i)
         return 0;
     }
    return 1;
}



//int iswin(Cboard,dim)
//{
  //   cout<<"player 1 wins";
    // cout<<"player 2 wins ";
//}


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

void taketurn(int &row,int &col)  // taking inputs
 {
     cout<<"enter inputs\n:";
     cin>>row;
     cin>>col;
 }
void  updateboard(char board[8][8],int dim,int sr,int sc,int dr,int dc,char p)   // overwriting board
{
    board[dr][dc]=p;
    board[sr][sc]='-';
}

