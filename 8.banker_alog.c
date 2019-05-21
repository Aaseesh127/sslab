#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n, r, i, j;
	int index=0, safe[n], k=0, flag=0;
	printf("Enter the no. of processes: ");
	scanf("%d", &n);
	printf("Enter the number of resources: ");
	scanf("%d", &r);
	int allocation[n][r], max[n][r], need[n][r], avail[r];
	int *finished = calloc(n, sizeof(int));
	printf("Enter the allocation matrix:\n");
	for(i=0; i<n; i++)
	{
		printf("Process P%d: ", i);
		for(j=0; j<r; j++)
			scanf("%d", &allocation[i][j]);
	}
	printf("Enter max matrix:\n");
	for(i=0; i<n; i++)
	{
		printf("Process P%d: ", i);
		for(j=0; j<r; j++)
		{
			scanf("%d", &max[i][j]);
			need[i][j] = max[i][j] - allocation[i][j];
		}
	}
	printf("Enter available resources: ");
	for(i=0; i<r; i++)
		scanf("%d", &avail[i]);

	int c;
	printf("Any immediate request? (1/0): ");
	scanf("%d", &c);
	if(c == 1)
	{
		int p, req[r];
		printf("Enter process no.: ");
		scanf("%d", &p);
		printf("Enter request in order of resources: ");
		for(i=0; i<r; i++)
			scanf("%d", &req[i]);

		for(i=0; i<r; i++)
			if(req[i] > need[p][i])
			{
				printf("Error\n");
				return 0;
			}
		for(i=0; i<r; i++)
			if(req[i] > avail[i])
				printf("Cannot process immediately, Wait for resources to be released\n");
		if(i == r)
		{
			printf("Can process\n");
			for(i=0; i<r; i++)
			{
				need[p][i] -= req[i];
				allocation[p][i] += req[i];
				avail[i] -= req[i];

				safe[k++] = p;
				finished[p] = 1;
				for(i=0; i<r; i++)
					avail[i] += allocation[index][i];
			}
		}

	}

	while(flag<100)
	{
		flag++;
		for(i=index; i<n; i++)
			if(!finished[i])
				break;
		if(i == n)
		{
			flag=0;
			break;
		}
		for(i=0; i<r; i++)
			if(need[index][i] > avail[i])
				break;
		if(i == r && !finished[index])
		{
			safe[k++] = index;
			finished[index] = 1;
			for(i=0; i<r; i++)
				avail[i] += allocation[index][i];
		}
		index = (index+1)%n;
	}
	if(flag == 0)
	{
		printf("Safe Sequence: ");
		for(i=0; i<n; i++)
		printf("%d ", safe[i]);
		printf("\n");
	}
	else
		printf("System is in unsafe state\n");
}
