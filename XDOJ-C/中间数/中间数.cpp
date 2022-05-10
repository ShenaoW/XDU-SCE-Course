#include <stdio.h>

#include <stdlib.h>




int main()

{

    int n,a[101],i,j,m,k,s = -1;

    scanf("%d",&n);

    for(i = 0;i<n;i++)

        scanf("%d",&a[i]);

    for(i = 0;i<n;i++)

    {

        k = 0;m = 0;

        for(j = 0;j<n;j++)

        {

            if(a[i]>a[j])

                k++;

            if(a[i]<a[j])

                m++;

        }

        if(m==k)

        {

            s = a[i];

            break;

        }

    }

    printf("%d",s);

    return 0;

}
