#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int *rank;
int SoNguoi;
int **Matrix;

void readfile()
{
	FILE *f = fopen("tiepxucGan.txt","r");;
	fscanf(f,"%d",&SoNguoi);
	rank = (int*)calloc(SoNguoi,sizeof(int));
	Matrix = (int**)malloc((SoNguoi)*sizeof(int*));
	for(int i=0;i<SoNguoi;i++)
		Matrix[i] = (int*)calloc((SoNguoi),sizeof(int));
	for(int i=0;i<SoNguoi;i++)
	{
		char x,m;
		fscanf(f," %c",&x);
		do
		{
			fscanf(f," %c",&m);
			Matrix[x-65][m-65] = 1;
			rank[x-65]++;
		}
		while(fgetc(f)!='\n');
	}
	fclose(f);
}
void print_list()
{
	for(int i=0;i<SoNguoi;i++)
	{
		printf("%c ",i+65);
		for(int j =0;j<SoNguoi;j++)
		{
			if(Matrix[i][j]) printf("%c ",j+65);
		}
		printf("\n");
	}
}
bool TiepXucGan(char x,char y)
{
	if(Matrix[x-65][y-65]) return true;
	return false;
}
void TiepXucGan_1(char x)
{
	for(int y = 0;y<SoNguoi;y++)
		if(Matrix[x-65][y]) printf("%c ",y+65);
}
int most_ranked()
{
	int max = rank[0];
	for(int i=1;i<SoNguoi;i++)
		if(rank[i]>max) max = rank[i];
	return max;
}
void most_ranked_print()
{
	for(int i=0;i<SoNguoi;i++)
		if(rank[i]==most_ranked()) printf("%c tiep xuc nhieu nguoi nhat\n ",i+65);
		
	printf(" Tiep xuc %d nguoi ",most_ranked());
}
void new_link(char x,char y)
{
	if(Matrix[x-65][y-65])printf("Da ton tai tiep xuc");
	else{
	Matrix[x-65][y-65] = Matrix[y-65][x-65] = 1;
	rank[x-65]++;
	rank[y-65]++;
	printf("Da cap nhat");}
}
void f1_f2(char x)
{
	int *checked = (int*)calloc(SoNguoi,sizeof(int));
	int *f1 = (int*)malloc(SoNguoi*sizeof(int));
	int count=0;
	checked[x-65] = 1;
	for(int y=0;y<SoNguoi;y++)
		if(Matrix[x-65][y])
		{
			checked[y] = 1;
			f1[count] = y;
			count++;
		}
	printf("F1: ");
	for(int i=0;i<count;i++)
		printf("%c ",f1[i]+65);
	printf("\nF2: ");
	for(int i=0;i<count;i++)
		for(int j=0;j<SoNguoi;j++)
			if(Matrix[f1[i]][j]){
				if(!checked[j])
				{
					checked[j] = 1;
					printf("%c ",j+65);
				}
			}
	free(checked);
	free(f1);
}

void write()
{
	FILE *f = fopen("ghifile.txt","w");
	fprintf(f,"Danh sach tiep xuc :");
	for(int i=0;i<SoNguoi;i++)
	{
		fprintf(f,"\n%c ",i+65);
		for(int j=0;j<SoNguoi;j++)
			if(Matrix[i][j]) fprintf(f,"%c ",j+65);
	}
	fclose(f);
}
int main()
{
	int choice,read=0;
	do
	{
		printf("\n=======================================");
		printf("\n1.Doc danh sach");
		printf("\n2.In Danh sach");
		printf("\n3.Check tiep xuc gan");
		printf("\n4.Danh sach tiep xuc gan cua 1 nguoi");
		printf("\n5.Tiep xuc gan nhieu nguoi nhat");
		printf("\n6.F1 va F2");
		printf("\n7.Bo sung");
		printf("\n8.Bo sung thong tin");
		printf("\n9.Ghi vao File");
		printf("\n10.Thoat");
		printf("\n=======================================");
		printf("\nYour choice: ");
		fflush(stdin);
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					readfile();
					break;
				}
			case 2:
				{
					print_list();
					break;
				}
			case 3:
				{
					char x,y;
					printf("Nguoi 1: ");
					fflush(stdin);
					scanf("%c",&x);
					printf("Nguoi 2: ");
					fflush(stdin);
					scanf("%c",&y);
					if(TiepXucGan(x,y)) printf("Tiep xuc gan");
					else printf("Khong tiep xuc");
					break;
				}
			case 4:
				{
					char x;
					printf("Nhap ten nguoi: ");
					fflush(stdin);
					scanf("%c",&x);
					TiepXucGan_1(x);
					break;
				}
			case 5:
				{
					most_ranked_print();
					break;
				}
			case 6:{
				char x;
				printf("Nhap F0: ");
				fflush(stdin);
				scanf("%c",&x);
				f1_f2(x);
				break;
			}
			case 7:{
				break;
			}
			case 8:{
				printf("Nhap nguoi 1:");
				char x,y;
				fflush(stdin);
				scanf("%c",&x);
				printf("Nhap nguoi 2:");
				fflush(stdin);
				scanf("%c",&y);
				new_link(x,y);
				break;
			}
			case 9:{
				write();
				break;
			}
			default:
				{
					break;
				}
			case 10:
				{
					break;
				}
		}
	}
	while(choice!=10);
	return 0;
}









