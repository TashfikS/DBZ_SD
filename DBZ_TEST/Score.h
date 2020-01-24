#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

typedef struct Score Score;

struct Score
{
    int Sc;
    char name[100];


    void print(char name[],int sc)
    {

        printf("Name: %s\n",name);
        printf("CGPA: %d\n",sc);

    }
};

void CreateFile(char file_name[])
{
    FILE *fp;
    fp = fopen(file_name,"a");
    fclose(fp);
    printf("File Created...\n");
}

void storeStudent_database(char filename[],char stdname[],int Sc)
{
    FILE *fp;
    fp =fopen(filename,"a");

    fprintf(fp,"%s ",stdname);
    fprintf(fp,"%d\n",Sc);
    fclose(fp);
    printf("\nSuccessfully Stored in Database...\n");
}

void printDataBase(char filename[])
{
    int sc;
    Score z;

    char name[100];
    FILE *fp;
    fp =fopen(filename,"r");
    while(fscanf(fp,"%s %d",name,&sc)!=EOF)
    z.print(name,sc);
    fclose(fp);
}




#endif // SCORE_H_INCLUDED
