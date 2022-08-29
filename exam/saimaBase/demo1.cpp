#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int n;
    double x, s;

    while (cin>>x>>s)
    {
        for(s = 0.0; n--; x = sqrt(x))
            s += x;
        printf("%.2lf\n", s);
    }   return 0;
}

#include <iostream>
using namespace std;
 
int main(){
    int A[100];
    int i = 0;
    for(i=0;;i++){
        cin>>A[i];
        if(getchar()=='\n')
            break;
    }
    for(int j=0;j<i+1;j++)
        cout<<A[j]<<endl;
    return 0;
}

#include <math.h>
#include <stdio.h>
int main()
{
    int n;
    double x, s;

    while (~scanf("%lf%d", &x, &n))
    {
        for(s = 0.0; n--; x = sqrt(x))
            s += x;
        printf("%.2lf\n", s);
    }   return 0;
}
