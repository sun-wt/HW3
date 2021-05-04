#include "hw0302.h"

int main() 
{
    FILE	*pFile = NULL;
    char name[127];
    printf("Please open a season record: ");
    scanf("%s",name);
    if( ( pFile = fopen( name, "r" ) ) == NULL )
    {
        printf( "File could not be opened!\n" );
        return 0;
    }

    char line[600];
    char home[600][30];
    char away[600][30];
    char Hscore[600][2];
    char Ascore[600][2];
    int Hwin[600]={0};
    int Awin[600]={0};
    int Hrd[600]={0};
    int Ard[600]={0};
    int gap[600]={0};
    int draw[600]={0};
    int Hlose[600]={0};
    int Alose[600]={0};
	int h[600]={0};
    int a[600]={0};
    char *result = NULL;
    int l=0;
    while(fgets(line,600,pFile) != NULL)
    {
        result = strtok(line, ",");
        int i = 0;
        while( result != NULL ) 
        {
            if(i==1)
            {
                strcpy(home[l],result);
            }
            else if(i==2)
            {
                strcpy(away[l],result);
            }
            else if(i==3)
            {
                strcpy(Hscore[l],result);
                h[l] = (Hscore[l][0]-48);
                gap[l]+=(Hscore[l][0]-48);
            }
            else if(i==4)
            {
                strcpy(Ascore[l],result);
                a[l] = (Ascore[l][0]-48);
                gap[l]-=(Ascore[l][0]-48);
            }
            else if(i==5)
            {
                if(result[0]=='H')
                {
                    Hwin[l]=1;
                    Alose[l]=1;
                }
                else if(result[0]=='A')
                {
                    Awin[l]=1;
                    Hlose[l]=1;
                }
                else
                {
                    draw[l]=1;
                }
            }
            else if(i==20)
            {
                Hrd[l]=result[0]-48;
            }
            else if(i==21)
            {
                Ard[l]=result[0]-48;
            }
            i++;
            result = strtok(NULL, ",");
        }
        l++;
    }
    int count = 1;
    char team[600][30];
    int S[600] = {0};
    int L[600] = {0};
    int Win[600] = {0};
    int Rd[600] = {0};
    int HW[600] = {0};
    int AW[600] = {0};
    int D[600] = {0};
    int Lose[600] = {0};
    strcpy(team[0],home[1]);
    int p = 1;
    for(int i=2;i<l;i++)
    {   
        for(int j=2;j<i;j++)
        {   
            if(strcmp(home[i],team[j])==0)
            {
                count--;
                break;
            }
        }
        if(count == p)
        {
            strcpy(team[count],home[i]);
        }
        count++;
        p = count;
    }
    for(int i=0;i<count;i++)
    {
        for(int j=0;j<l;j++)
        {
            if(strcmp(team[i],home[j])==0)
            {
                S[i]+=(Hscore[j][0]-48);
                L[i]+=(Ascore[j][0]-48);
                Win[i]+=Hwin[j];
                HW[i]+=Hwin[j];
                Rd[i]+=Hrd[j];
                D[i]+=draw[j];
                Lose[i]+=Hlose[j];
            }
            if(strcmp(team[i],away[j])==0)
            {
                S[i]+=(Ascore[j][0]-48);
                L[i]+=(Hscore[j][0]-48);
                Win[i]+=Awin[j];
                AW[i]+=Awin[j];
                Rd[i]+=Ard[j];
                D[i]+=draw[j];
                Lose[i]+=Alose[j];
            }
        }
    }

	for(int i=0;i<l;i++)
    {
        gap[i] = abs( gap[i] );
    }
    
    printf("1)Who is the winner in this season?\n");
    printf("2)Which team gets the most scores?\n");
    printf("3)Which team gets the most red cards?\n");
    printf("4)Which team wins the most games at home?\n");
    printf("5)Which team wins the most games away from home?\n");
    printf("6)Which game has the most scoring gap?\n");
    printf("7)Team information.\n");
    printf("8)Quit\n");
    printf("-->");

    while(1)
    {
        printf("Choice (1-7, 8:exit):");
        int c = choice ();
        int C;
        char *t;
        switch( c )
        {
            case -1:
                break;
            case 1:
                Champion(team,Win,D,count);
                break;
            case 2:
                ScoreKing(team,S,count);
                break;
            case 3:
                RedCard(team,Rd,count);
                break;
            case 4:
                Court(team,HW,count);
                break;
            case 5:
                Court(team,AW,count);
                break;
            case 6:
                Gap(home,away,gap,h,a);
                break;
            case 7:                
                for(int C=0;C<count;C++)
                {
                    int point = Win[C]*3+D[C]*1;
                    printf("Team: %s\n",team[C]);
                    printf("Point : %d\n",point);
                    printf("Win/Draw/Lose: %d/%d/%d\n",Win[C],D[C],Lose[C]);
                    printf("Goal Scored/Goal Against: %d/%d\n",S[C],L[C]);
                    printf("\n");
                }
                break;
            case 8:
                return 0;
            default:
                break;
        }
         printf("\n");
        rewind( pFile );
    }
        

    fclose( pFile );
    return 0;
}
