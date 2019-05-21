#include<stdio.h>
int fqueue[100], front = 0, rear = -1, fsize, n, i, j, pH=0, pM=0, lru[100], k=99, l=99, PN[100];
int fqueueIsEmpty()
{
	for(int i=0; i<fsize; i++)
		if(fqueue[i] == -9)
			return 1;
	return 0;
}
void display()
{
	for(int i=0; i<fsize; i++)
	{
		if(fqueue[i] == -9)
			printf("-\n");
		else
			printf("%d\n", fqueue[i]);
	}
}
int pageHit(int page)
{
	for(int i=0; i<fsize; i++)
		if(fqueue[i] == page)
			return 1;
	return 0;
}
void solve(int choice)
{
	for(i=0; i<n; i++)
	{
		if(pageHit(PN[i]))
		{
			printf("\nPno.%d : Page Hit\n", PN[i]);
			pH++;
			if(choice == 2)
			{
				lru[k--] = PN[i];
				l--;
			}
			display();
			continue;
		}
		else
		{
			if(fqueueIsEmpty())
			{
				fqueue[++rear] = PN[i];
				lru[k--] = PN[i];
			}
			else
			{
				if(choice == 1)
				{
					rear = (rear+1)%fsize;
					fqueue[rear] = PN[i];
				}
				else
				{
					for(j=0; j<fsize; j++)
						if(fqueue[j] == lru[l])
						{
							fqueue[j] = PN[i];
							lru[k--] = PN[i];
							l--;
							break;
						}
				}
			}
			printf("\nPno.%d : Page Miss\n", PN[i]);
			pM++;
			display();
		}
	}
}
int main()
{
	printf("Enter frame size: ");
	scanf("%d", &fsize);
	printf("How many page numbers?: ");
	scanf("%d", &n);
	for(i=0; i<fsize; i++)
		fqueue[i] = -9;
	printf("Enter page those numbers: ");
	for(i=0; i<n; i++)
		scanf("%d", &PN[i]);
	int choice;
	printf("\nSelect\n1. FIFO\n2. LRU\n");
	scanf("%d", &choice);
	solve(choice);
}
