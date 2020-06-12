#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int T;
int main(){
    cin >> T;
    if(T==1){
        cout << "I love Luogu!"<<endl;
    }
    else if(T==2){
        cout << 6 <<" "<<4<<endl;
    }
    else if(T==3){
        int x=14;int n=4;
        int avg = x/n;int left = x -avg*n;
        cout << avg  <<endl<<avg*n<<endl << left<<endl;
    }
    else if(T==4){
        double x=500;
        int n=3;
        printf("%3.3lf",x/n);
    }
    else if(T==5){
        int x,y,z,d;
        x= 260;y=220;z=12;d=20;
        cout << (x+y)/(z+d)<<endl;
    }
    else if(T==6)
    {
         cout << sqrt(6*6+9*9) <<endl;
    }
    else if(T==7){
        int x=100;
        x+=10;
        cout << x<<endl;
        x-=20;
        cout << x<<endl;
        cout << 0<<endl;
    }
    else if(T==8){
        double mpi = 3.141593;
        int r=5;
        cout << 2*mpi*r <<endl;
        cout << mpi*r*r<<endl;
        cout << 4.0*mpi*r*r*r/3.0<<endl;

    }
    else if(T==9)
    {
        int x=1;
        for(int i=1;i<=3;i++){
            x=(x+1)*2;
        }
        cout << x<<endl;
    }
    else if(T==10){
        cout << 116/12<<endl;
    }
    else if(T==11){

        cout << 100.0/(8.0-5.0)<<endl;
    }
    else if(T==12){
        cout << 'M'-'A'+1 << endl;
        cout << char('A'+18-1)  <<endl;
    }
    else if(T==13){
        double x1=4,x2=10;double mpi=3.141593;
        x1=x1*x1*x1*4.0/3.0*mpi;
        x2=x2*x2*x2*4.0/3.0*mpi;
        double l=0,r=1000;double x;
        double v=x1+x2;
        while(1){
            x=(l+r)/2.0;
            double tmp= x*x*x-v;
            if(fabs(tmp)<1e-8){
                break;
            }
            else if(tmp<0){
                l=x;
            }
            else{
                r=x;
            }
        }
        cout << int(x)<<endl;
    }
    else if(T==14){
        double l=10,r=60;
        double x;
        while(1){
            x=(l+r)/2;
            double tmp =x*x-120*x+3500;
            if(fabs(tmp)<1e-8){
                break;
            }
            else if(tmp>0){
                l=x;
            }
            else{
                r=x;
            }
        }
        int ans= floor(x+0.5);
        cout << ans<<endl;
    }
}