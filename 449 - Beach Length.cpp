#include <iostream>  
#include <cstring>        
using namespace std;

int main()
{
	int i=0,beach=0;
	char king[55],kingdom[55][55];;
	while(cin.getline(king,55))
	{	
		int j;
		for( j=0; j<55; j++)  // king[j]!='\0'
		{
			kingdom[i][j]=king[j];
			/*
			if(i%2==0)
				kingdom[i][2*j]=king[j];   
			else
				kingdom[i][2*j+1]=king[j];   */ 
		}
	
		i++;
		
		if (cin.peek() =='\n')
		{
			for(int k=0; k<i; k++)
			{
				for(int m=0; m<j; m++)
				{
					if(k%2==0)
					{
						if(kingdom[k][m]=='#')
						{
							if(kingdom[k][m-1]=='.')
								beach++;
							if(kingdom[k][m+1]=='.')
								beach++;
							if(kingdom[k-1][m-1]=='.')
								beach++;
							if(kingdom[k-1][m]=='.')
								beach++;
							if(kingdom[k+1][m-1]=='.')
								beach++;
							if(kingdom[k+1][m]=='.')
								beach++;
						}
					}
					else
					{
						if(kingdom[k][m]=='#')
						{
							if(kingdom[k][m-1]=='.')
								beach++;
							if(kingdom[k][m+1]=='.')
								beach++;
							if(kingdom[k-1][m+1]=='.')
								beach++;
							if(kingdom[k-1][m]=='.')
								beach++;
							if(kingdom[k+1][m+1]=='.')
								beach++;
							if(kingdom[k+1][m]=='.')
								beach++;
						}
					}
					/*
					if(kingdom[k][m]=='#')
					{	
						if(kingdom[k][m-2]=='.')
							beach++;
						
						if(kingdom[k][m+2]=='.')
							beach++;
					
						if(kingdom[k-1][m-1]=='.')
							beach++;
						
						if(kingdom[k-1][m+1]=='.')
							beach++;
							
						if(kingdom[k+1][m-1]=='.')
							beach++;
						
						if(kingdom[k+1][m+1]=='.')
							beach++;
					} */
				}
			}
			
			cout<<beach<<endl;
			beach=0;
			memset(king,' ',sizeof(king));
			memset(kingdom,' ',sizeof(kingdom));
			i=-1;
		}
	}
	
	return 0;
}

/* 135, 494
..#.##.###.....#.
.#....#.###..#...
##....##..#.#..#.
#..#..#..##.###.#
#..###.#...#.#...
##...#.#.##.##.#.


.#..###.#.#..#.##.#.####.######.
#.#....###..######.#.#..##.#..#.
.#.####.#..#....#.#..#...##.#..#
#...#.##.#.###.#####.#..#....##.
##...#.#.#...#.#...#.##.#..####.
###.####.##.#.##..##.....#.#.###
#.....##.###..#.#..###....###..#
#.#.####.######.#...#####..##.##
#.##...####.#..#...#...####..##.
###.####......#...#..##..#####..
.#.#.######.#.#..#.....##..####.
*/
