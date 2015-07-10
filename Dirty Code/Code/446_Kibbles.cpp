#include<bits/stdc++.h>

using namespace std;

#define LLI long long int
long long p,de,ln,con,from,to,i,temp;
string input;
long long store[1000];
string output;
string convert( string input,int from ,int to )
{
    output.clear();
    ln=input.size();
    store[0]=1;
    for(i=1; i<ln; i++)
    {
        store[i]=store[i-1]*from;
    }
    de=0;
    p=ln-1;
    for(i=0; i<ln; i++)
    {
        if(input[i]>'9')
            con=input[i]-'A'+10;
        else con=input[i]-'0';
        de+=con*store[p];
        p--;
    }
    if(de==0)
        output+='0';
    else
    {
        i=0;
        while(de>0)
        {
            temp=de%to;
            de/=to;
            if(temp>9)
                temp+=55;
            output+=(temp+'0');
        }
        reverse(output.begin(),output.end());
    }
    return output;
}

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for( int t=1; t<=T; t++ )
    {
        getline(cin,input);
        cout<<convert(input,15,13)<<endl;
//        {
//            string str,st;
//            int pos;
//            for( int i=0; ; i++ )
//            {
//                if( input[i] == ' ' )
//                    break;
//                else
//                {
//                    str+=input[i];
//                    pos=i;
//                }
//            }
//            for( int i=pos+1; i<input.size(); i++ )
//            {
//                if( isalnum(input[i]) )
//                    st+=input[i];
//            }
//            string fst_bi=convert(str,16,2);
//            string tmp=fst_bi;
//            fst_bi.clear();
//            if( tmp.size() != 13 )
//            {
//                LLI val=13-tmp.size();
//                for( int i=0; i<val; i++ )
//                {
//                    fst_bi+='0';
//                }
//            }
//            fst_bi+=tmp;
//            string snd_bi=convert(st,16,2);
//            tmp=snd_bi;
//            snd_bi.clear();
//            if( tmp.size() != 13 )
//            {
//                LLI val=13-tmp.size();
//                for( int i=0; i<val; i++ ) snd_bi+='0';
//            }
//            snd_bi+=tmp;
//            if( input[pos+2] == '+' )
//                cout<<fst_bi<<" + "<<snd_bi;
//            else cout<<fst_bi<<" - "<<snd_bi;
//            fst_bi=convert(str,16,10);
//            snd_bi=convert(st,16,10);
//            LLI fst_dec,snd_dec;
//            stringstream ss;
//            ss<<fst_bi;
//            ss>>fst_dec;
//            ss.clear();
//            ss<<snd_bi;
//            ss>>snd_dec;
//            ss.clear();
//            if( input[pos+2] == '+' )
//                cout<<" = "<<fst_dec+snd_dec<<endl;
//            else cout<<" = "<<fst_dec-snd_dec<<endl;
//        }
//        input.clear();
    }
    return 0;
}
