/*6. В головном модуле вводится список сотрудников (не более 25): фамилия, имя, отчество и зарплата в виде чисел по месяцам (не более 12) для каждого
сотрудника. В первой функции рассортировать список каждого отдела по алфавиту. Во второй функции для каждого отдела создать матрицу из полученного списка
сотрудников. Строка матрицы соответствует одному сотруднику: сначала идет фамилия и инициалы, а затем зарплата по месяцам. Полученную матрицу вывести
на экран в головном модуле. Глобальные переменные, системные функции, за исключением ввода-вывода, не использовать.*/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define N 25
#define M 12
#define SE 10
#define NE 8
#define FE 12
struct employee
{
	char sername[SE], name[NE], father_name[FE];
	int salary[M];
};
employee f_sort_e (employee **);
void flist (employee **);
int main ()
{
	int i, j;
	employee **p;			//p - pointer
	if (!(p=(employee**)malloc((N+1)*sizeof(employee*))))
			return 0;
	for (i=0; i<N; i++)
		if (!(p[i]=(employee*)malloc(sizeof(employee))))
		{
			for ( ; i>-1; i--)
				free (p[i]);
			free (p);
			return 0;
		}
	for (i=0; i<N; )
	{
		fflush (stdin);
		printf ("vvedite familijy(10), imja i otchestvo %d sotrudnika:\n(svobodnoe mesto v familii zapolnit probelami inache sobetsja matrica\nvvodite na anglijskom jazike)\n", i+1);
		fgets (p[i]->sername, SE, stdin);
		fflush (stdin);
		fgets (p[i]->name, NE, stdin);
		fflush (stdin);
		fgets (p[i]->father_name, FE, stdin);
		for (j=0; j<M; )
		{
			printf ("vvedite zarplaty za mesyac %d v milionah: ", j+1);
			if (!scanf ("%d", &(p[i]->salary[j])))
				fflush (stdin);
			else j++;
		}
		i++;
	}
	printf ("User name       1  2  3  4  5  6  7  8  9  10  11  12\n");
	f_sort_e (p);
	flist (p);
	for (i=0; i<N; i++)
		free (p[i]);
	free (p);
	getch ();
}
employee f_sort_e (employee **z)
{
	int q=1, e, r, w;
	for  (q=0; q<N-1; q++)
	{
		if (*(z[q]->sername)>='a' && *(z[q]->sername)<='z')
			r=q;
		else r=-1;
		if (*(z[q]->sername)>='A' && *(z[q]->sername)<='Z')
			w=q;
		else w=-1;
		for (e=q+1; e<N; e++)
		{
			if (*(z[e]->sername)>='a' && *(z[e]->sername)<='z')
			{
				if (*(z[e]->sername)<*(z[r]->sername) && r!=-1)
				{
					r=e;
					continue;
				}
				if (*(z[e]->sername)-'a'<*(z[w]->sername)-'A' && w!=-1)
				{
					w=e;
					continue;
				}
			}
			if (*(z[e]->sername)>='A' && *(z[e]->sername)<='Z')
			{
				if (*(z[e]->sername)-'A'<*(z[r]->sername)-'a' && r!=-1)
				{
					r=e;
					continue;
				}
				if (*(z[e]->sername)<*(z[w]->sername) && w!=-1)
				{
					w=e;
					continue;
				}
			}
		}
		if (r!=-1)
		{
			z[N]=z[q];
			z[q]=z[r];
			z[r]=z[N];
			continue;
		}
		if (w!=-1)
		{
			z[N]=z[q];
			z[q]=z[w];
			z[w]=z[N];
		}
	}
	return *z[0];
}
void flist (employee **z)
{
	int q, w;	
	for (w=0; w<N; w++)
	{
		printf ("\n%s %c. %c.", z[w]->sername, *(z[w]->name), *(z[w]->father_name));
		for (q=0; q<M; q++)
			printf ("%3d", z[w]->salary[q]);
	}
}
