#include <stdio.h> 
#include <dirent.h> 

int main(void) 
{ 
	struct dirent *de; // Pointer for directory entry 

	// opendir() returns a pointer of DIR type. 
	DIR *dr = opendir("."); 

	if (dr == NULL) // opendir returns NULL if couldn't open directory 
	{ 
		printf("Could not open current directory" ); 
		return 0; 
	} 
	while ((de = readdir(dr)) != NULL) 
	{
		
			printf("%s\n", de->d_name); 
	}

	closedir(dr);	 

	// Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html 
	// for readdir() 
	while ((de = readdir(dr)) != NULL) 
	{
		
			//printf("%s\n", de->d_name); 
		//de->d_name this is the file name
		int value; 
			//char c[10];
			int i,t=0;
			char *c=de->d_name;
			while((*c)!='\0')
			{
				c++;
				t++;
			}
	// File name is changed here 
	value = rename(de->d_name, c); 

	// Print the result 
	if(!value) 
	{ 
		printf("%s", "File name changed successfully"); 
	} 
	else
	{ 
		perror("Error"); 
	} 

	}

	closedir(dr);	 
	return 0; 
} 
