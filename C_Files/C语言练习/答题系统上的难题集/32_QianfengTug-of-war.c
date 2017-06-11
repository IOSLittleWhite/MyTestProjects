/*******************************************
 *作者：冯生伟
 *时间：2014
 *******************************************/
# include <stdio.h>
# include <math.h>

typedef struct mb{
	int id;
	int data;
}*pmember, member;

int find_replace(pmember arr, int index, int max, int tap);
void find_next(pmember arr, int index);
void combination(pmember arr, int len, int n);

int main()
{
	int len = 0;
	int i;
	int num;
	member arr[1024] = {0};
    
    scanf("%d", &len);
	for(i=0; i<len; i++)
	{
		scanf("%d", &arr[i].data);
		arr[i].id = i + 1;
 	}
    
	combination(arr, len, len/2 + len%2);
	
	return 0;
}

void combination(pmember arr, int len, int n)
{
	int i;
	int sub = n - 2;
	int tap = 1;
	int done = 0;
	int flag;
	int sum = 0;
	int team = 0;
	int temp = 0;
	int min;

	for(i=0; i<len; i++)
		sum += arr[i].data;
	min = sum;

	do
	{
		for(i=0; i<n; i++)
			temp += arr[i].data;
        
		if(abs(sum - 2*temp) < min)
		{
			min = abs(sum - 2*temp);
			team = temp;
        }
		temp = 0;
        
		if(arr[0].id == len - n + 1)
			done = 1;
        
		flag = 1;
		while(flag && (arr[0].id != len - n + 1))
		{
			flag = find_replace(arr, n-1, len, 0);
			if(flag)
			{
				while(flag)
				{
					flag = find_replace(arr, sub, len, tap);
					for(i=sub; i<sub+tap; i++)
						find_next(arr, i);
					if(flag)
					{
						tap++;
						sub--;
					}
				}
				sub = n - 2;
				tap = 1;
			}
		}
	}while(!done);
    
	printf("%d %d\n", team, sum - team);
}

int find_replace(pmember arr, int index, int max, int tap)
{
	int i = index + 1;
	member temp;
	while(arr[i].id != 0)
	{
		if((arr[i].id == arr[index].id + 1) && (arr[i].id <= max - tap))
		{
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
			return 0;
		}
		i++;
	}
	return 1;
}

void find_next(pmember arr, int index)
{
	int i = index + 2;
	member temp;
	if(arr[index].id + 1 != arr[index + 1].id)
	{
		while(arr[i].id != 0)
		{
			if(arr[i].id == arr[index].id + 1)
			{
				temp = arr[i];
				arr[i] = arr[index+1];
				arr[index+1] = temp;
			}
			i++;
		}
	}
}