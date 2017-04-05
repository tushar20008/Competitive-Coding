#include <iostream>
#include <cstring>
using namespace std;

int counter;
int CheckRow[9],CheckD1[9],CheckD2[9];

void Queen(int row[], int col, int r, int c)
{
	int temp;
	
	if(col>=8 && row[c]==r)
	{
		if(counter<9)
			cout<<" "<<++counter<<"      "<<row[0]+1;
		else
			cout<<++counter<<"      "<<row[0]+1;
		for(int j=1; j<8; j++)
			cout<<" "<<row[j]+1;
		
		cout<<endl;
		return;
	}
	else
	{
		for(temp=0; temp<8; temp++)
		{
			if(!CheckRow[temp] && !CheckD1[temp-col+8-1] && !CheckD2[temp + col])
			{
				row[col]=temp;
				
				if(col==c && row[col]!=r)
					continue;
				
				else
				{
					CheckRow[temp] = CheckD1[temp - col + 8 - 1] = CheckD2[temp + col] = true;
					
					Queen(row,col + 1,r,c);
					
					CheckRow[temp] = CheckD1[temp - col + 8 - 1] = CheckD2[temp + col] = false;
				}
			}
		}
	}
}
 
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int r,c;
		cin>>r>>c;
		
		int row[8];
		/*memset(row,0,sizeof(row));
		memset(CheckRow,0,sizeof(CheckRow));
		memset(CheckD1,0,sizeof(CheckD1));
		memset(CheckD2,0,sizeof(CheckD2));
*/
		cout<<"SOLN       COLUMN"<<endl;
		cout<<" #      1 2 3 4 5 6 7 8"<<endl<<endl;
		counter=0;
		Queen(row,0,r-1,c-1);
		
		if(n)
			cout<<endl;
	}
	return 0;
}
