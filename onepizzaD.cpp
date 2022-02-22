#include <bits/stdc++.h>
using namespace std;

void randomarr(int arr[], int size)
{
    srand(time(0));
    for(int i = 0; i<size; i++)
    {
        arr[i] = rand() %2;
    }
}
bool ishappy(int l, int likes[], int dislikes[], int pizza[] )
{
    int c=0;
    for(int i=0; i<500; i++)
    {
        if(likes[i] == 1 && pizza[i] == 1) c++;
        if(dislikes[i] == 1 && pizza[i] == 1)
        {
            return false;
        }
    }
    if(c == l) return true;
    else return false;
}



int main() 
{
	// your code goes here
	int pizza[500];
    randomarr(pizza, 500);
    cout<<pizza[0]<<pizza[1]<<pizza[2]<<endl;
    int t;
    cin>>t;
    int c = 0;;
    
    for(int k=0;k<t;k++)
    {
        int likes[500] = {0};
        int dislikes[500] = {0};
        int l,d;
        cin>>l;
        string templike;
        for(int i=0; i<l; i++)
        {
            cin>>templike;
            int a = (int)(templike[10] - 48);
            likes[a]++;
        }
        cin>>d;
        for(int i = 0; i<d; i++)
        {
            cin>>templike;
            int a = (int)(templike[10] - 48);
            dislikes[a]++; 
        }
        if(ishappy(l, likes, dislikes, pizza))
        {
            c++;
        }
        cout<<c<<'\n';
        int num = 0;
        for(int i=0; i<500; i++)
        {
            if(pizza[i] == 1)
            {
                num++;
            }
        }
        cout<<num<<" ";
        for(int i=0; i<500; i++)
        {
            if(pizza[i] == 1)
            {
                cout<<"ingredient"<<i<<" ";
            }
        }
    }
    return 0;
}