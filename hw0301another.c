#include "hw0301.h"

void lyric( FILE * pFile )
{
	char line[400]={0},Line[400][1000]={0};
    char people[20][30]={0};
    char *result = NULL;
    int printer[400]={0};
    double gap[400]={0};
    int count = 0,C = 0;
    int Lm = 0,Ls = 0,Lms = 0;
    int Nm = 0,Ns = 0,Nms = 0;
    int LineN = 0;
    int record[30]={0};
    while(fgets(line,400,pFile) != NULL)
    {
        strcpy(Line[LineN],line);
        LineN++;
        if(line[0]!='['&&line[strlen(line)-2]==':')
        {
            line[strlen(line)-2] = 0;
            line[strlen(line)-1] = 0;
            strcpy(people[count],line);
            record[count] = LineN;
            count++;
        }
        else if(line[0]=='['&&line[strlen(line)-2]!=']')
        {
            char l[400][1000];
            LineN--;
            strcpy(l[LineN],line);
            char *token = strtok(l[LineN],"]");
            token = strtok(NULL,"]");
            strcpy(Line[LineN],token);
            LineN++;
            Nm = (line[1]-48)*10+(line[2]-48);
            Ns = (line[4]-48)*10+(line[5]-48);
            Nms = (line[7]-48)*10+(line[8]-48);
            gap[C] = ((Nm-Lm)*60+(Ns-Ls))*1000000+(Nms-Lms);
            Lm = Nm,Ls = Ns,Lms = Nms;
        }
        else if(line[strlen(line)-2]!=':')
        {
            gap[C] = 0.1;
            Lm = Nm,Ls = Ns,Lms = Nms;
        }
        //printf("%s",Line[LineN]);
        C++;
    }
    record[count]=C;
    int Nnum = 0,max = 1;
    int P[20] = {0};
    for(int i=0;i<count;i++)
    {
        P[i] = -1;
    }
    P[0] = 0,P[1] = 1;
    for(int i=0;i<count;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(strcmp(people[i],people[j])==0)
            {
                P[i] = P[j];
                break;
            }
        }
        if(P[i]==-1)
        {
            P[i] = max+1;
            max++;
        }
    }    
    
    for(int i=0;i<LineN;i++)
    {
        if(gap[i]!=0)
        {
            usleep(gap[i]);
            for(int j=0;j<=count;j++)
            {
                if(i >= record[j] && i < record[j+1])
                {
                    int c = P[j];
                    if(c==0)
                    printf(RED"%s",Line[i]);
                    else if(c==1)
                    printf(YELLOW"%s",Line[i]); 
                    else if(c==2)
                    printf(LG"%s",Line[i]);    
                    else if(c==3)
                    printf(GREEN"%s",Line[i]); 
                    else if(c==4)
                    printf(BLUE"%s",Line[i]);  
                    else if(c==5)
                    printf(CYAN"%s",Line[i]);
                    else if(c==6)
                    printf(PURPLE"%s",Line[i]);
                    else if(c==7)
                    printf("%s",Line[i]);    
                }
            }
            
        }
    }
}
