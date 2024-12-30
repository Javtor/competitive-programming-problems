#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    if(n % 2 == 0){
        printf("%d\n", -1);
    } else{
        for (int i = 0; i < n; i++)
        {
            if(i == 0)
            printf("%d", i);
            else
            {
                printf(" %d", i);
            }
            
        }
        printf("\n");
        for (int i = 0; i < n; i++)
        {
            if(i == 0)
            printf("%d", i);
            else
            {
                printf(" %d", i);
            }
            
        }
printf("\n");
        for (int i = 0; i < n; i++)
        {
            if(i == 0)
            printf("%d", (i+i)%n);
            else
            {
                printf(" %d", (i+i)%n);
            }
            
        }
        printf("\n");
        
    }
    

    

    return 0;
}
