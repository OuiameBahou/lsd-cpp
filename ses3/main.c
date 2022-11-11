#include "read_lines.h"


void strconcatenate (char* s1, char* s2)
{
	int e= strlen (s2);
	int f=strlen (s1);
	for (int i=0;i<e;i++)
		s1[f+i]=s2[i];
	    
	
	return ;
}

int check(char* s2)
{
	int j=0;
	while (s2[j] != '\0')
	{
		if (s2[j] == '\n'){
			return 1;}
		j++;
	}
	return 0;
}

void read_file(int fd )
{
	int n;
	char * buffer= (char*)malloc((BUFFER_SIZE+1) * sizeof(char));
	while(n=read(fd,buffer,BUFFER_SIZE) != 0)
	{
		if (n == -1)
		{
			free(buffer);
			exit(EXIT_FAILURE);
		}
		strconcatenate(fixed,buffer);
    int i=0;
        while ( fixed[i] !='\0')
	{
		
		i++;
	}
   
		if(check(fixed))
			break;
	}
	return ;
}

char* get_line ()
{
	int i=0;
	while (fixed[i] != '\n' && fixed [i] != '\0')
		i++;
	if (fixed[i] == '\n')
		i++;
	char* line =(char*)malloc(sizeof(char) *(i+1));
	for(int j=0;j<i;j++)
	{
		line[j] = fixed[j] ;
	}
	line [i]='\0';
	return line;
}

char* keep() 
{
	int n=0, m=1;
	while (fixed[n] != '\0' ){
		n++;
	}
	while (fixed[m] != '\n' ){
		m++;
	}
	int size= n-m +1 ;
	char* k = (char*)malloc (sizeof(char) * size );
	for (int i=0; i<size-1 ; i++){
		k[i]= fixed[i+m+1];
	}
	k[size-1] = '\0';
	return k;
}


char* read_lines(int fd)
{
	
	
	read_file (fd);
	if (fixed == NULL){              //if the line that we are currently reading is NULL it exits
		exit(EXIT_FAILURE);
	    
	}
	char* line = get_line(fixed);
	char* k= keep(fixed);

	int n=0;
	while ( line[n] !='\0')
	{
		printf("%c", line[n]);
		n++;
	}
    
    memset(fixed,0,strlen(fixed)); //we added this function so we can fill the lines read with zeros so the read_lines won't read the same lines again
   
	 int m=0;
	while( k [m]!= '\0')
	{
		k[m] = k [m];
        m++;
	} 
    
	return line;
	
}
int main()
{ 
  int fd = open("text.txt",O_RDONLY );
  while(fd)                                       //the function read_lines returns only lines that are not null that's why the while works just fine
   {
    char * s2=read_lines(fd);
    
   }
   return 0;
  
}
