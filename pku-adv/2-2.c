#include <stdio.h>
int main()
{
    int a,b,c,d;//代表a、b、c、d四人说的话说对的数量。 
    int x,y,z,m;//代表鄱阳湖、洞庭湖、太湖、洪泽湖 的排名。1是最大，4是最小 
    for(x=1;x<=4;x++)
    {
        for(y=1;y<=4;y++)
        {
            if(x!=y)
            {
                for(z=1;z<=4;z++)
                {
                    if(z!=x&&z!=y)
                    {
                        m=10-x-y-z;
                        a=(y==1)+(m==4)+(x==3);
                        b=(m==1)+(y==4)+(x==2)+(z==3);
                        c=(m==4)+(y==3);
                        d=(x==1)+(z==4)+(m==2)+(y==3);
                        if(a*b*c*d==1)
                        {
                            printf("%d\n%d\n%d\n%d\n",x,y,z,m);
                            return 0;
                        }
                    }
                    
                }
            }    
        }
    }
    return 0;
}