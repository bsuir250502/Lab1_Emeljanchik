#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 25
#define M 12
#define SE 10
#define NE 8
#define FE 12
struct employee
{
	char surname[SE], name[NE], father_name[FE];
	int salary[M];
};
int f_sort_e (const void *a, const void *b)
{
		return strcmp((*(employee *) a).surname, (*(employee *) b).surname);
}
void flist (employee z)
{
	int q;
	for (q=0; q<SE && z.surname[q]!='\n' && z.surname[q]!='\0'; q++)
		printf ("%c", z.surname[q]);
	if (q<SE)
		for ( ; q<SE; q++)
			printf (" ");
	printf (" %c.", z.name[0]);
	printf (" %c.", z.father_name[0]);
	for (q=0; q<M; q++)
		printf ("%3d", z.salary[q]);
	puts ("");
}
int main ()
{
	int i, j;
	employee p[N];			//p - pointer
	for (i=0; i<N; i++)
	{
		fflush (stdin);
		printf ("vvedite familijy %d sotrudnika: ", i+1);
		fgets (p[i].surname, SE, stdin);
		fflush (stdin);
		printf ("vvedite imja %d sotrudnika: ", i+1);
		fgets (p[i].name, NE, stdin);
		fflush (stdin);
		printf ("vvedite otchestvo %d sotrudnika: ", i+1);
		fgets (p[i].father_name, FE, stdin);
		for (j=0; j<M; )
		{
			printf ("vvedite zarplaty za mesyac %d v milionah: ", j+1);
			if (!scanf ("%d", &(p[i].salary[j])))
				fflush (stdin);
			else j++;
		}
	}
	printf ("User surname, name, father name and salarys:\n");
	qsort (p, N, sizeof (employee), f_sort_e);
	for (i=0; i<N; i++)
		flist (p[i]);
}
