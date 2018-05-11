#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int character(FILE *fp);
int word(FILE *fp);
int row(FILE *fp);
int main(int argc,char *argv[])
{
	FILE *fp=NULL;
	if((fp=fopen(argv[2],"r"))==NULL)
	{
		printf("Please enter correct and available file name!\n");
		exit(0);
	}
	if(strcmp(argv[1],"-c")==0)
	printf("%d\n",character(fp));
	else if(strcmp(argv[1],"-w")==0)
	printf("%d\n",word(fp));
	else if(strcmp(argv[1],"-l")==0)
	printf("%d\n",row(fp));
	else
	printf("Please enter the available instruction you want!\n");
	fclose(fp);
	system("pause");
	return 0;
}
int character(FILE *fp)
{
	int count=0;
	while(!feof(fp))
	if(fgetc(fp)!=EOF)
	count++;
	return count;
}
int word(FILE *fp)
{
	short int flag=0;
	int count=0;
	while(!feof(fp))
	{
		if(fgetc(fp)<='Z'&&fgetc(fp)>='A'||fgetc(fp)<='z'&&fgetc(fp)>='a')
		flag=1;
		else
		{
			if(flag)
			count++;
			flag=0;
		}
	} 
	return count; 
}
int row(FILE *fp)
{
	int count=0;
	while(!feof(fp))
	if(fgetc(fp)=='\n')
	count++;
	return count;
}