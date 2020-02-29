#include<stdio.h>
#include<ctype.h>
#include<string.h>
void keyw(char *p);
int i=0;
int key=0,num=0,ide=0;
int iskyw=0;
char keys[18][10]={"break","case","char","const","continue","do","else","enum","float",
"for","goto","if","int","long","record","return","static","while"};
FILE *f2;
main()
{
	char ch,str[31],seps[15]=" \t\n,;(){}[]",oper[]="+-*/:";
	int j;
	FILE *f1;
    f1 = fopen("code.psi.txt","r");
    f2 = fopen("code.lex.txt","w");

	if(f1==NULL)
	{
	 printf("file not found");
	 exit(0);
	}
	while((ch=fgetc(f1))!=EOF)
	{
        ch=tolower(ch);
	    if(ch=='/')
        {
            FILE tempfile;
            tempfile = *f1;
            if(ch=fgetc(f1)=='*')
            {

                while(ch=fgetc(f1)!='/')
                {
                    ch=fgetc(f1);
                }
                ch=fgetc(f1);
            }
            else
            {
                *f1=tempfile;

                iskyw=1;

            }
	    }

        for(j=0;j<=5;j++)
        {
            char temp[2];

            if(ch==oper[j])
            {
                str[i]='\0';
                keyw(str);
                if(key==1)
                {
                    char s1[]="Keyword(",*s2=&s1;

                    while(*s2!='\0')
                    {
                        fputc(*s2,f2);
                        s2++;
                    }
                    char *s = &str;
                    while(*s!='\0')
                    {
                        fputc(*s,f2);
                        s++;
                    }
                    fputc(')',f2);
                    fputc('\n',f2);

                }
                else if(num==1)
                {
                    char s1[]="IntConst(",*s2=&s1;

                    while(*s2!='\0')
                    {
                        fputc(*s2,f2);
                        s2++;
                    }
                    char *s = &str;
                    while(*s!='\0')
                    {
                        fputc(*s,f2);
                        s++;
                    }
                    fputc(')',f2);
                    fputc('\n',f2);
                }
                else if(ide==1)
                {
                    char s1[]="Identifier(",*s2=&s1;

                    while(*s2!='\0')
                    {
                        fputc(*s2,f2);
                        s2++;
                    }
                    char *s = &str;
                    while(*s!='\0')
                    {
                        fputc(*s,f2);
                        s++;
                    }
                    fputc(')',f2);
                    fputc('\n',f2);
                }
                if(iskyw==1)
                {
                    char s1[]="Operator(/)";
                    char *s = &s1;
                    while(*s!='\0')
                    {
                        fputc(*s,f2);
                        s++;
                    }
                    fputc('\n',f2);
                    iskyw=0;
                }
                key=0;
                num=0;
                ide=0;

                temp[0]=ch;
                FILE tempfile;
                tempfile = *f1;
                ch = fgetc(f1);
                if(ch=='+'||ch=='-'||ch=='=')
                {
                    temp[1]=ch;
                }
                else
                {
                    *f1=tempfile;
                }
                if(temp[0]=='+' || temp[0]=='-' || temp[0]==':'||temp[0]=='/'||temp[0]=='*')
                {


                    char s1[]="Operator(";
                    char *s = &s1;
                    while(*s!='\0')
                    {
                        fputc(*s,f2);
                        s++;
                    }
                    fputc(temp[0],f2);
                    if(temp[1]!='\0')
                    {
                        fputc(temp[1],f2);
                    }
                    fputc(')',f2);
                    fputc('\n',f2);


                }
                temp[0]='\0';
                temp[1]='\0';
            }
        }

        if(ch=='"')
        {
            char s1[] ="String Constant(";
            char *s = &s1;
            while(*s!='\0')
            {
                fputc(*s,f2);
                s++;
            }

            do
            {
                ch=fgetc(f1);
                if(ch=='"')
                {
                    continue;
                }
                fputc(ch,f2);

            }while(ch!='"');
            if(ch=='"')
            {
                ch=fgetc(f1);
                fputc(')',f2);
                fputc('\n',f2);
            }
            else
            {
                printf("ERROR(STRING CONSTANT)");
                exit(0);
            }

        }

        for(j=0;j<=14;j++)
        {
            if(i==-1)
            {
                break;
            }

            if(ch==seps[j])
            {
                str[i]='\0';
                keyw(str);
                if(key==1)
                {
                    char s1[]="Keyword(",*s2=&s1;

                    while(*s2!='\0')
                    {
                        fputc(*s2,f2);
                        s2++;
                    }
                    char *s = &str;
                    while(*s!='\0')
                    {
                        fputc(*s,f2);
                        s++;
                    }
                    fputc(')',f2);
                    fputc('\n',f2);

                }
                else if(num==1)
                {
                    char s1[]="IntConst(",*s2=&s1;

                    while(*s2!='\0')
                    {
                        fputc(*s2,f2);
                        s2++;
                    }
                    char *s = &str;
                    while(*s!='\0')
                    {
                        fputc(*s,f2);
                        s++;
                    }
                    fputc(')',f2);
                    fputc('\n',f2);
                }
                else if(ide==1)
                {
                    char s1[]="Identifier(",*s2=&s1;

                    while(*s2!='\0')
                    {
                        fputc(*s2,f2);
                        s2++;
                    }
                    char *s = &str;
                    while(*s!='\0')
                    {
                        fputc(*s,f2);
                        s++;
                    }
                    fputc(')',f2);
                    fputc('\n',f2);
                }
                key=0;
                num=0;
                ide=0;
                if(seps[j]=='(')
                {
                    char s1[] ="LeftPar";
                    char *s = &s1;
                    while(*s!='\0')
                    {
                        fputc(*s,f2);
                        s++;
                    }
                    fputc('\n',f2);
                }
                else if(seps[j]==')')
                {
                    char s1[] ="RightPar";
                    char *s = &s1;
                    while(*s!='\0')
                    {
                        fputc(*s,f2);
                        s++;
                    }
                    fputc('\n',f2);
                }
                else if(seps[j]=='[')
                {
                    char s1[] ="LeftSquareBracket";
                    char *s = &s1;
                    while(*s!='\0')
                    {
                        fputc(*s,f2);
                        s++;
                    }
                    fputc('\n',f2);
                }
                else if(seps[j]==']')
                {
                    char s1[] ="RightSquareBracket";
                    char *s = &s1;
                    while(*s!='\0')
                    {
                        fputc(*s,f2);
                        s++;
                    }
                    fputc('\n',f2);
                }
                else if(seps[j]=='{')
                {
                    char s1[] ="LeftCurlyBracket";
                    char *s = &s1;
                    while(*s!='\0')
                    {
                        fputc(*s,f2);
                        s++;
                    }
                    fputc('\n',f2);
                }
                else if(seps[j]=='}')
                {
                    char s1[] ="RightCurlyBracket";
                    char *s = &s1;
                    while(*s!='\0')
                    {
                        fputc(*s,f2);
                        s++;
                    }
                    fputc('\n',f2);
                }
                else if(seps[j]==';')
                {
                    char s1[] ="EndOfLine";
                    char *s = &s1;
                    while(*s!='\0')
                    {
                        fputc(*s,f2);
                        s++;
                    }
                    fputc('\n',f2);
                }
            }
        }
        if(i!=-1)
        {
            str[i]=ch;
            i++;
        }
        else
        {
           i=0;
        }
	}

    printf("***Lexical Analyzer islemi yapilmistir. code.lex.txt dosyasi icine yazilmistir.***");
}
void keyw(char *p)
{
    int k,flag=0;
    for(k=0;k<=17;k++)
    {
        if(strcmp(keys[k],p)==0)
        {
            flag=1;
            key=1;
            num=0;
            ide=0;
            break;
        }
    }
    if(flag==0)
    {
        if(isdigit(p[0]))
        {
            key=0;
            num=1;
            ide=0;

        }
        else
        {
            if(p[0]!='\0')
            {
                key=0;
                num=0;
                ide=1;
            }
        }
    }
    i=-1;
}


