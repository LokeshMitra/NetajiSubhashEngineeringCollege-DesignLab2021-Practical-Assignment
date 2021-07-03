#include<iostream>
using namespace std;


//checking function whether key is present or not
bool check(int *arr,int n,int key)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(key==arr[i])
			return true;
		}
	}
	return false;
}

int main()
{

int n,d,t;
cin>>n;
cin>>d;
int err[n];

//energy input index+1 represent friends
for(t=0;t<n;t++)
{
	cin>>err[t];
}
int friends[n][d];
int r=0,c=0;

//friends input
for(r=0;r<d;r++)
	{
		for(c=0;c<2;c++)
		{
			cin>>friends[r][c];
		}
	}


int no_need[n]; // This is the array of items that we dont need for evaluation of op


int f,item;
int i=0;
int index=0;// This index variable is used for appending to the no need array
for(f=0;f<n;f++)
{
	int j=0;
	for(item=0;item<d;item++)
	{
		if(j!=0)
			no_need[index++]=friends[i][j]; // all the col2 values are getting into noneed
		j+=1;           // here we are doing index ++ because
						// the values of col2 should go to noneed
						// which we are going to check later with all the friends
						//that are present i.e from 1 to n 
	}
	i+=1;
}
int OP=0; //output

int i2=0;
while(i2<n)
{
	if(check(no_need,n,i2+1)==false)  // i2+1 is the key since index+1 represented the friend of err array
									//check line 60
		OP+=err[i2];
	i2=i2+1;
	
}
cout<<OP;
}
