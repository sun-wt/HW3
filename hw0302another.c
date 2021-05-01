#include "hw0302.h"

int choice()
{
    int choice=0;
    if(scanf("%d",&choice)==-1)
    {
        return -1;
    }
    else if(choice<1||choice>8)
    {
        return -1;
    }
    return choice;
}

void Champion(char team[600][30],int *win,int count)
{
    int max = 0;
    int times = 0;
    for(int i=0;i<count;i++)
    {
        if(win[i]>max)
        {
            max=win[i];
            times=i;
        }
    }
    for(int i=0;i<count;i++)
    {
        if(win[i]==max)
        {
            printf("%s\n",team[times]);
        }
    }
    return;
}

void ScoreKing(char team[600][30],int *score,int count)
{
    int max = 0;
    int times = 0;
    for(int i=0;i<count;i++)
    {
        if(score[i]>max)
        {
            max=score[i];
            times=i;
        }
    }
    for(int i=0;i<count;i++)
    {
        if(score[i]==max)
        {
            printf("%s,%d\n",team[times],max);
        }
    }
    
    return;
}

void RedCard(char team[600][30],int *rd,int count)
{
    int max = 0;
    int times = 0;
    for(int i=0;i<count;i++)
    {
        if(rd[i]>max)
        {
            max=rd[i];
        }
    }
    for(int i=0;i<count;i++)
    {
        if(rd[i]==max)
        {
            printf("%s,%d\n",team[i],max);
        }
    }
    return;
}

void Court(char team[600][30],int *win,int count)
{
    int max = 0;
    int times = 0;
    for(int i=0;i<count;i++)
    {
        if(win[i]>max)
        {
            max=win[i];
            times=i;
        }
    }
    for(int i=0;i<count;i++)
    {
        if(win[i]==max)
        {
            printf("%s,%d\n",team[i],max);
        }
    }
    return;
}

void Gap(char h[600][30],char a[600][30],int *gap)
{
    int max = 0;
    int times = 0;
    for(int i=0;i<600;i++)
    {
        if(gap[i]>max)
        {
            max=gap[i];
            times=i;
        }
    }
    for(int i=0;i<600;i++)
    {
        if(gap[i]==max)
        {
            printf("%s and %s ,%d point\n",h[i],a[i],gap[i]);
        }
    }
    return;
}
