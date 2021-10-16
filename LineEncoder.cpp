#include<graphics.h>
#include<iostream>
#include<algorithm>
#include<time.h>
#include<windows.h>

using namespace std;

int num()
{
    int n;
    cout << "Enter the number of bits: ";
    cin >> n;
    return n;
}
string lcs(string &X, string &Y)
{
    int m = X.length(),n = Y.length();
    int L[m+1][n+1];

    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    int index = L[m][n];
    string lcs(index+1, '\0');

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i-1] == Y[j-1])
        {
            lcs[index-1] = X[i-1];
            i--;
            j--;
            index--;
        }
        else if(L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }
    return lcs;
}
string LPS(string &str)
{
    string rev = str;
    reverse(rev.begin(), rev.end());
    return lcs(str, rev);
}
void NRZ_L(string s)
{
    int x=30, y=180,one=0,zero=0;
    cout << "Encoded value: ";
    for(int i=0;i<s.length();i++)
    {
        delay(100);
        if(s[i]=='0')
        {
            line(x,280,x+50,280);
            settextstyle(8, 0, 3);
            outtextxy(x+30, 70, "0");

            if(one == 1)
            {
                line(x,280,x,80);
            }
            one = 0;
            zero = 1;
            x += 50;
            cout << "0 ";
        }
        else
        {
            line(x,80,x+50,80);
            settextstyle(8, 0, 3);
            outtextxy(x+30, 70, "1");
            if(zero == 1)
            {
                line(x,80,x,280);
            }
            zero = 0;
            one = 1;
        x += 50;
        cout << "1 ";
        }
    }
    settextstyle(8, 0, 5);
    outtextxy(400, 385, "NRZ_L");
    cout << endl;
}
void NRZ_I(string s)
{
    int x=30, y=80,count=0,sch;
    if(s[0]=='1')
        sch = 1;
    else
        sch = 0;
    cout << "Encoded value: ";
    for(int i=0;i<s.length();i++)
    {
        delay(100);
        if(sch==1){
            if(s[i]=='1')
            {
                count++;
                {
                   if(count%2==1)
                   {
                       line(x,80,x,280);
                       line(x,80,x+50,80);
                       settextstyle(8, 0, 3);
                       outtextxy(x+30, 70, "1");
                       cout << "1 ";
                   }
                   else
                   {
                       line(x,280,x,80);
                       line(x,280,x+50,280);
                       settextstyle(8, 0, 3);
                       outtextxy(x+30, 70, "1");
                       cout << "0 ";
                   }
                   x+=50;
            }}
            else
            {
                    if(count%2==1)
                    {
                        line(x,80,x+50,80);
                        settextstyle(8, 0, 3);
                        outtextxy(x+30, 70, "0");
                        cout << "1 ";
                    }
                    else
                    {
                        line(x,280,x+50,280);
                        settextstyle(8, 0, 3);
                        outtextxy(x+30, 70, "0");
                        cout << "0 ";
                    }
                    x+=50;
            }}
        else
        {
            if(s[i]=='1'){
            count++;
            {
               if(count%2==0)
               {
                   line(x,80,x,280);
                   line(x,80,x+50,80);
                   settextstyle(8, 0, 3);
                   outtextxy(x+30, 70, "1");
                   cout << "1 ";
               }
               else
               {
                   line(x,280,x,80);
                   line(x,280,x+50,280);
                   settextstyle(8, 0, 3);
                   outtextxy(x+30, 70, "1");
                   cout << "0 ";
               }
               x+=50;
            }}
        else
        {
            if(count%2==0){
                line(x,80,x+50,80);
                settextstyle(8, 0, 3);
                outtextxy(x+30, 70, "0");
                cout << "1 ";
            }
            else{
                line(x,280,x+50,280);
                settextstyle(8, 0, 3);
                outtextxy(x+30, 70, "0");
                cout << "0 ";
            }
            x+=50;
    }}}
    settextstyle(8, 0, 5);
    outtextxy(400, 385, "NRZ_L");
    cout << endl;
}
void Manch(string s)
{
    int x=30, y=180,prev;
    if(s[0] == '0')
        prev = 0;
    prev = 1;
    cout << "Encoded value: ";
    for(int i=0;i<s.length();i++)
    {
        delay(100);
        if(s[i] == '0'){
            if(prev == 0)
            {
                line(x,280,x,80);
            }
            line(x,80,x+25,80);
            x+=25;
            line(x,80,x,280);
            line(x,280,x+25,280);
            x += 25;

            prev = 0;
            settextstyle(8, 0, 3);
            outtextxy(x-15,70, "0");
            cout << "10 " ;
        }
        else{
            if(prev == 1)
            {
                line(x,80,x,280);
            }
            line(x,280,x+25,280);
            x+=25;
            line(x,280,x,80);
            line(x,80,x+25,80);
            x +=25;
            prev = 1;
            settextstyle(8, 0, 3);
            outtextxy(x-15, 70, "1");
            cout << "01 ";
        }
    }
    settextstyle(8, 0, 5);
    outtextxy(400, 385, "MANCHESTER");
    cout << endl;
}
void Diff_Manch(string s)
{
    int x=30,y=80,flag;
    cout << "Encoded value: ";
    if(s[0]=='1'){
        delay(100);
        line(x,80,x+25,80);
        x+=25;
        line(x,80,x,280);
        line(x,280,x+25,280);
        x+=25;
        settextstyle(8, 0, 3);
        outtextxy(x-15,70, "1");
        flag=1;
        cout << "10 ";
    }
    else{
        delay(100);
        line(x,280,x+25,280);
        x+=25;
        line(x,280,x,80);
        line(x,80,x+25,80);
        x+=25;
        settextstyle(8, 0, 3);
        outtextxy(x-15,70, "0");
        flag=0;
        cout << "01 ";
    }
    for(int i=1;i<s.length();i++)
    {
        delay(100);
        if(s[i]=='1')
        {
            if(flag==1)
            {
                line(x,280,x+25,280);
                x+=25;
                line(x,280,x,80);
                line(x,80,x+25,80);
                x+=25;
                flag = 0;
                cout << "01 ";
            }
            else
            {
                line(x,80,x+25,80);
                x+=25;
                line(x,80,x,280);
                line(x,280,x+25,280);
                x+=25;
                flag = 1;
                cout << "10 ";
            }
        settextstyle(8, 0, 3);
        outtextxy(x-15,70, "1");
        }
        else
        {
            if(flag==1)
            {
                line(x,280,x,80);
                line(x,80,x+25,80);
                x+=25;
                line(x,80,x,280);
                line(x,280,x+25,280);
                x+=25;
                cout << "10 ";
            }
            else
            {
                line(x,80,x,280);
                line(x,280,x+25,280);
                x+=25;
                line(x,280,x,80);
                line(x,80,x+25,80);
                x+=25;
                cout << "01 ";
            }
        settextstyle(8, 0, 3);
        outtextxy(x-15,70, "0");
    }}
    settextstyle(8, 0, 5);
    outtextxy(640, 385, "DIFFERENTIAL MANCHESTER");
    cout << endl;
}
void B8ZS(string s)
{
    int count=0,i,pos=0,x=30,y=180,k;
    while((i = s.find("00000000", pos)) != string::npos) {
          s.replace(i,8,"000VB0VB");
          pos = i + 8;
        }
    cout << "Scrambled value: ";
   for(int i=0;i<s.length();i++)
   {
        delay(100);
        if(s[i] == '0')
        {
            line(x,180,x+50,180);
            x+=50;
            settextstyle(8, 0, 3);
            outtextxy(x-15,70, "0");
            cout << "0 ";
        }
        else if(s[i] == '1'|| s[i] == 'B'){
            count++;
            if(count%2==1)
            {
                line(x,180,x,80);
                line(x,80,x+50,80);
                x+=50;
                line(x,80,x,180);
                if(s[i]=='B')
                {
                settextstyle(8, 0, 3);
                outtextxy(x-15,130, "B");
                }
            }
            else
            {
                line(x,180,x,280);
                line(x,280,x+50,280);
                x+=50;
                line(x,280,x,180);
                if(s[i]=='B')
                {
                settextstyle(8, 0, 3);
                outtextxy(x-15,230, "B");
                }
            }
            settextstyle(8, 0, 3);
            if(s[i]=='1'){
                outtextxy(x-15,70, "1");
                cout << "1 ";
            }
            else{
                outtextxy(x-15,70, "0");
                cout << "B ";
        }}
        else if(s[i]=='V')
        {
            if(count%2==1)
            {
                line(x,180,x,80);
                line(x,80,x+50,80);
                x+=50;
                line(x,80,x,180);
                settextstyle(8, 0, 3);
                outtextxy(x-15,130, "V");
            }
            else
            {
                line(x,180,x,280);
                line(x,280,x+50,280);
                x+=50;
                line(x,280,x,180);
                settextstyle(8, 0, 3);
                outtextxy(x-15,230, "V");
            }
                settextstyle(8, 0, 3);
                outtextxy(x-15,70, "0");
                cout << "V ";
    }}
    settextstyle(8, 0, 5);
    outtextxy(400, 385, "B8ZS");
    cout << endl;
}
void HDB3(string s){
   int count=0,i,pos=0,x=30,y=180,flag = 0;
    while((i = s.find("0000", pos)) != string::npos) {
      s.replace(i,4,"KKKK");
      pos = i + 4;
   }
   cout << "Scrambled value: " <<endl;
   for(int i=0;i<s.length();i++)
   {
       delay(100);
       if(s[i]=='K')
       {
           if(count%2==0)
           {
               if(flag==0)
               {
               line(x,180,x,80);
               line(x,80,x+50,80);
               x+=50;
               settextstyle(8, 0, 3);
               outtextxy(x-15,130, "B");
               settextstyle(8, 0, 3);
               outtextxy(x-15,70, "0");
               line(x,80,x,180);
               line(x,180,x+50,180);
               x+=50;
               settextstyle(8, 0, 3);
               outtextxy(x-15,70, "0");
               line(x,180,x+50,180);
               x+=50;
               settextstyle(8, 0, 3);
               outtextxy(x-15,70, "0");
               line(x,180,x,80);
               line(x,80,x+50,80);
               x+=50;
               settextstyle(8, 0, 3);
               outtextxy(x-15,130, "V");
               line(x,80,x,180);
               flag = 1;
               }
               else
               {
               line(x,180,x,280);
               line(x,280,x+50,280);
               x+=50;
               settextstyle(8, 0, 3);
               outtextxy(x-15,230, "B");
               outtextxy(x-15,70, "0");
               line(x,280,x,180);
               line(x,180,x+50,180);
               x+=50;
               settextstyle(8, 0, 3);
               outtextxy(x-15,70, "0");
               line(x,180,x+50,180);
               x+=50;
               settextstyle(8, 0, 3);
               outtextxy(x-15,70, "0");
               line(x,180,x,280);
               line(x,280,x+50,280);
               x+=50;
               settextstyle(8, 0, 3);
               outtextxy(x-15,230, "V");
               line(x,280,x,180);
               flag = 0;
                }
           cout << "B 0 0 V " ;
            }
            else
            {
            if(flag==1){
               line(x,180,x+50,180);
               x+=50;
               settextstyle(8, 0, 3);
               outtextxy(x-15,70, "0");
               line(x,180,x+50,180);
               x+=50;
               settextstyle(8, 0, 3);
               outtextxy(x-15,70, "0");
               line(x,180,x+50,180);
               x+=50;
               settextstyle(8, 0, 3);
               outtextxy(x-15,70, "0");
               line(x,180,x,80);
               settextstyle(8, 0, 3);
               outtextxy(x+25,230, "V");
               line(x,80,x+50,80);
               x+=50;
               line(x,80,x,180);
                }
            else{
               line(x,180,x+50,180);
               x+=50;
               settextstyle(8, 0, 3);
               outtextxy(x-15,70, "0");
               line(x,180,x+50,180);
               x+=50;
               settextstyle(8, 0, 3);
               outtextxy(x-15,70, "0");
               line(x,180,x+50,180);
               x+=50;
               settextstyle(8, 0, 3);
               outtextxy(x-15,70, "0");
               line(x,180,x,280);
               settextstyle(8, 0, 3);
               outtextxy(x+25,230, "V");
               line(x,280,x+50,280);
               x+=50;
               line(x,280,x,180);
                }
            cout << "0 0 0 V ";
            }
            count = 0;
            i+=3;
            settextstyle(8, 0, 3);
            outtextxy(x-15,70, "0");
        }
        else if(s[i]=='0')
        {
            line(x,180,x+50,180);
            x+=50;
            settextstyle(8, 0, 3);
            outtextxy(x-15,70, "0");
            cout << "0 ";
        }
        else if(s[i]=='1')
        {
           count++;
           if(flag==1)
           {
               line(x,180,x,280);
               line(x,280,x+50,280);
               x+=50;
               line(x,280,x,180);
               flag = 0;
           }
           else if(flag==0)
           {
               line(x,180,x,80);
               line(x,80,x+50,80);
               x+=50;
               line(x,80,x,180);
               flag = 1;
           }
            settextstyle(8, 0, 3);
            outtextxy(x-15,70, "1");
            cout << "1 ";
        }}
    settextstyle(8, 0, 5);
    outtextxy(400, 385, "HDB3");
    cout << endl;
}
void AMI(string s)
{
    int x=30,y=80,count=0;
    cout << "Encoded value: ";
    for(int i=0;i<s.length();i++)
    {
        delay(100);
        if(s[i]=='0')
        {
            line(x,180,x+50,180);
            x+=50;
            settextstyle(8, 0, 3);
            outtextxy(x-15,70, "0");
            cout << "0 " ;
        }
        else
        {
            count++;
            if(count%2==1)
            {
                line(x,180,x,80);
                line(x,80,x+50,80);
                x+=50;
                line(x,80,x,180);
                cout << "+ ";
            }
            else
            {
                line(x,180,x,280);
                line(x,280,x+50,280);
                x+=50;
                line(x,280,x,180);
                cout << "- ";
            }
            settextstyle(8, 0, 3);
            outtextxy(x-15,70, "1");
        }
    }
    settextstyle(8, 0, 5);
    outtextxy(400, 385, "AMI");
    cout << endl;
}
void AMI_SCR(string s)
{
    cout << "Do you need scrambling?(Y/N)";
    char ch;
    cin >> ch;
    if(ch=='Y' || ch=='y')
    {
        scrambling:
        cout << "Choose the type of scrambling:\n1.HDB3     2.B8ZS\n";
        cout << "Enter your choice: ";
        int x,k;
        cin >> x;
        if(x==1)
        {
           HDB3(s);
        }
        else if(x==2)
        {
           B8ZS(s);
        }
        else
        {
            cout << "Enter a valid option!\n";
            goto scrambling;
        }}
    else
    {
        AMI(s);
}}
int choice2 (string s)
{
    Choice2:
    cout << "\nChoose the type of Line Encoding Scheme:\n1. NRZ-L   2. NRZ-I   3. Manchester\n4. Differential Manchester    5. AMI      6. Choose a different String?"<<endl;
    cout << "\nEnter your choice: " ;
    int x2;
    cin >> x2;
    if(x2==1)
    {
        NRZ_L(s);
    }
    else if(x2==2)
    {
        NRZ_I(s);
    }
    else if(x2==3)
    {
        Manch(s);
    }
    else if(x2==4)
    {
        Diff_Manch(s);
    }
    else if(x2==5)
    {
        AMI_SCR(s);
    }
    else if(x2==6)
    {
        return 6;
    }
    else
    {
        cout << "Enter valid option!" <<endl;
        goto Choice2;
}}
int mainplot()
{
    settextstyle(8, 1, 3);
    outtextxy(30, 130, "Amplitude");
    settextstyle(8, 0, 3);
    outtextxy(30, 70, "+A");
    settextstyle(8, 0, 3);
    outtextxy(30, 310, "-A");
    setlinestyle(1,0,0.5);
    int x = 30;
    for(int i=0;i<18;i++)
    {
        line(x,50,x,300);
        x+=50;
    }
    setlinestyle(3,0,1);
    line(30,180,960,180);
    setlinestyle(0,0,1);
    line(30,30,30,330);
    setlinestyle(0,0,3);
}
int main()
{
    srand(time(0));
    initwindow(1000,400);
    setbkcolor(WHITE);
    setcolor(BLACK);

    bool x = true;
    start:
    while(x)
    {
        cleardevice();
        Choice1:
        cout << "\n------------------------------------------------------------------------\n";
        cout << "\nChoose the type of string:\n0. Quit\n1. A random string\n2. A random 16 bit sequence with fixed-subsequences\n3. A Custom User input string" <<endl;
        cout << "\nEnter your choice: ";
        int x1;
        cin >> x1;
        if(x1==0)
        {
            x = false;
            cout << "You have left the program!" <<endl;
            goto start;
        }
        else if(x1==1)
        {
            mainplot();
            int n;
            n = num();
            int arr[n];
            for(int i=0;i<n;i++)
            {
                arr[i] = rand()%2;
            }
            cout << "The sequence is: " ;
            for(int i=0;i<n;i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            string s;
            for (int i: arr)
            {
                s += to_string(i);
            }
            string arr1 = LPS(s);
            cout << "LPS is: " << arr1 << endl;

            //option for encoding
            int temp = choice2(s);
            if(temp==6)
            goto Choice1;

            cout << "continue?(Y/N)" ;
            char ch;
            cin >> ch;
            if(ch == 'Y' || ch == 'y')
            {
                cleardevice();
                goto Choice1;
            }
            else
            {
                x = false;
                goto start;
            }
        }
        else if(x1==2)
        {
            mainplot();
            int n=16;
            int arr[n];
            for(int i=0;i<4;i++)
            {
                arr[i] = 0;
            }
            for(int i=4;i<8;i++)
            {
                arr[i]=rand()%2;
            }
            for(int i=8;i<16;i++)
            {
                arr[i]=0;
            }
            cout << "The sequence is: ";
            for(int i=0;i<n;i++)
            {
                cout << arr[i] <<  " ";
            }
            cout << endl;
            string s;
            for (int i: arr) {
                s += to_string(i);
            }
            string arr1 = LPS(s);
            cout << "LPS is: " << arr1 << endl;

            //Option for encoding Scheme
            int temp = choice2(s);
            if(temp==6)
            goto Choice1;

            cout << "continue?(Y/N)" ;
            char ch;
            cin >> ch;
            if(ch == 'Y' || ch == 'y')
            {
                cleardevice();
                goto Choice1;
            }
            else
            {
                x = false;
                goto start;
            }
        }
        else if(x1==3)
        {
            mainplot();
            int n;
            n = num();
            string s;
            cout << "Enter your sequence: ";
            cin >> s;
            cout << "The sequence is: " ;
            for(int i=0;i<n;i++)
            {
                cout << s[i] << " ";
            }
            cout << endl;
            string arr1 = LPS(s);
            cout << "LPS is: " << arr1 << endl;
                        int temp = choice2(s);
            if(temp==6)
            goto Choice1;

            cout << "continue?(Y/N)" ;
            char ch;
            cin >> ch;
            if(ch == 'Y' || ch == 'y')
            {
                cleardevice();
                goto Choice1;
            }
            else
            {
                x = false;
                goto start;
            }
        }
        else
        {
            cout << "Enter valid option!" <<endl;
            goto Choice1;
}}}

