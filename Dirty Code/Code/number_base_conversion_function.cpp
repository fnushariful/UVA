#include <bits/stdc++.h>

using namespace std;

char input[1000];
unsigned long long store[1000];
string output;
int main()
{
    long long p,dec,ln,con,from,to,i,temp;
    while(printf("Enter number:\t"))
    {
        scanf("%s",input);
        printf("\nEnter base of the number:\t");
        scanf("%lld",&from);
        printf("\nEnter base to conver:\t");
        scanf("%lld",&to);
        ln=strlen(input);
        store[0]=1;
        for(i=1; i<ln; i++)
        {
            store[i]=store[i-1]*from;
        }
        dec=0;
        p=ln-1;
        for(i=0; i<ln; i++)
        {
            if(input[i]>'9')
                con=input[i]-'A'+10;
            else con=input[i]-'0';
            dec+=con*store[p];
            p--;
        }
        if(dec==0)
            output+='0';
        else
        {
            i=0;
            while(dec>0)
            {
                temp=dec%to;
                dec/=to;
                if(temp>9)
                    temp+=55;
                if( temp > 9 )
                    output+=(temp);
                else output+=temp+'0';
            }
            printf("\nthe converted mnumber is:\t");
//            for(p=i-1; p>=0; p--)
//            {
//                if(output[p]>9)
//                    printf("%c",output[p]);
//                else printf("%llu",output[p]);
//            }
            cout<<output<<endl;
        }
        printf("\n\n");
        printf("if want to quit press 0,else 1:");
        scanf("%lld",&i);
        if(i==0)
            break;
    }
    return 0;
}



