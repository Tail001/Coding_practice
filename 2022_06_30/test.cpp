
#include<iostream> 
using namespace std;

int num[1000000];
int n,m;
int binarySearch(int *num, int key, int index)
{
    int left = index;
    int right = m-1;
    while(left <= right)
    {
        int mid = (left+right)/2;
        if(num[mid]==key)
            return mid;
        else
        if(num[mid]>key)
           right = mid-1;
        else 
            left = mid+1;
    }
    return -1;//找不到 
    
}
int main()
{

    scanf("%d %d",&n,&m);
    for(int r=0; r<n; r++)
    {
        int ans = 0;
        for(int i=0; i<m; i++)
            scanf("%d",&num[i]);
            
        int index = 0;
        int i=0;
        for(i=0; i<m; i++)
        {
            int temp;
            scanf("%d",&temp);
            if(temp>num[m-1])
                break;
            if(temp<num[0])
                continue;
            //二元搜尋
            int p = binarySearch(num, temp, index);  // array /target / left
            if(p!=-1)
            {
                ans++;
                index = p;
            }
            
        }
        //把剩下的讀完 
        for(i=i+1; i<m; i++)
        {
            int temp;
            scanf("%d",&temp);
        }
        
        
        printf("%d\n",ans);
    }
}