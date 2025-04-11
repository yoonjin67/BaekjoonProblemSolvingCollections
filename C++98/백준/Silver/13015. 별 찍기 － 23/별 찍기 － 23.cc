#include<iostream>
using namespace std;
int main()
{
        short x;
        cin >> x; 
        register int i,ii,y=x*2-3,z=0,xx=x-2;
        for(i=0;i<x*2-1;i++)
        {
                if (i==x-1)
                        {
                        for(ii=0;ii<z;ii++)
                                cout << " ";
                        cout << "*" ;
                        for(ii=0;ii<xx;ii++)
                                cout << " ";
                        cout << "*" ;
                        for(ii=0;ii<xx;ii++)
                                cout << " ";
                        cout << "*" ;
                        goto whenmid;
                        }
                if(i==(x-1)*2 | i==0)
                        {
                                for(ii=0;ii<x;ii++)
                                        cout << "*" ;
                                for(ii=0;ii<x*2-3;ii++)
                                        cout << " ";
                                for(ii=0;ii<x;ii++)
                                        cout << "*" ;
                        }
                else
                        {
                        for(ii=0;ii<z;ii++)
                                cout << " ";
                        cout << "*" ;
                        for(ii=0;ii<xx;ii++)
                                cout << " ";
                        cout << "*" ;
                        for(ii=0;ii<y;ii++)
                                cout << " ";
                        cout << "*" ;
                        for(ii=0;ii<xx;ii++)
                                cout << " ";
                        cout << "*" ;
                        }
                whenmid:
                if(i<x-1)
                        z++;
                else
                        z--;
                if(i<x-1)
                        y-=2;
                else
                        y+=2;
                cout << endl;
        }
        return 0;
}