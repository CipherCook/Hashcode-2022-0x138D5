#include <bits/stdc++.h>
using namespace std;

void toArr(int size, string arr[], int likes[])
{
    //0-basil 1-cheese 2-mushroom 3-peppers 4-pineapple 5-tomatoes
    for(int i = 0; i < size; i++)
    {
        if (arr[i] == "basil") likes[0]++;
        if (arr[i] == "cheese") likes[1]++;
        if (arr[i] == "mushroom") likes[2]++;
        if (arr[i] == "peppers") likes[3]++;
        if (arr[i] == "pineapple") likes[4]++;
        if (arr[i] == "tomatoes") likes[5]++;
    }
    return;
}
bool ishappy(int l, int likes[], int dislikes[], int pizza[] )
{
    int c=0;
    for(int i=0; i<6; i++)
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
void fillall(int input[64][6])
{
    
    for(int i =0; i<64; i++)
    {
        int index = 5;
        int n = i;
        while(index>=0)
        {
            input[i][index] = n%2;
            // cout<<"n: "<<n<<" index: "<<index<<"  ";
            // cout<<"value: "<<output[n][index]<<" ";
            n/=2;
            index--;
        }
        // cout<<output[i][0]<<output[i][1]<<output[i][2]<<output[i][3]<<output[i][4]<<output[i][5]<<endl;
    }
    
}


int main() {
	// your code goes here
	int all[64][6];
    fillall(all);
    int t;
    cin>>t;
    int maxcount =0;
    int bestindex=0;
    int likes[t][6] = {0};
    int dislikes[t][6] = {0};
    int l[t], d[t];
    for(int k=0;k<t;k++)
    {
        
    	cin>>l[k];
    	string likenames[6];
    	string dislikenames[6];
    	for(int i=0;i<l[k];i++)
    	{
    	    cin>>likenames[i];
    	}
    	cin>>d[k];
    	for(int i =0; i<d[k]; i++)
    	{
    	    cin>>dislikenames[i];
    	}
    	toArr(l[k],likenames,likes[k]);
    	toArr(d[k],dislikenames,dislikes[k]);
    	//input is done till here	
    }
    for(int i =0; i<64; i++)
    {
        int maxyet = 0;
        for(int k=0; k<t; k++)
        {
            if(ishappy(l[k], likes[k], dislikes[k], all[i]))
            {
                maxyet++;
            }
        }
        if (maxyet > maxcount)
        {
            maxcount = maxyet;
            bestindex = i;
        }
        
    }
    cout<<bestindex;
    
     
	return 0;
}
