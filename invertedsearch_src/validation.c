#include"inverted_search.h"


/* validating the command line arguments and files                                        
-------------------------------------------------------------------------------------------------------------------*/
int validate_arg(char *file_name)
{
    
      // printf("%s\n",argv[i]);
        char *val =strchr(file_name,'.');
       //printf("\n\n");
        if(val && (strcmp(val,".txt") == 0))
        { 
            return SUCCESS;
        }
        else
        {
            printf(RED"INFO :  %s is not .txt file\n\n"RESET,file_name);
            return FAILURE;
        }
    
}

int validate_file(char *file_name)
{
    FILE *fptr = fopen(file_name,"r");
    if(fptr == NULL)
    {
        printf("INFO :  %s file is not available\n\n",file_name);
        return FAILURE;
    }
    else
    {
         if(fgetc(fptr) == EOF)
         {
            fclose(fptr);
            printf("INFO :  %s file is empty\n\n",file_name);
            return FILEEMPTY;
         }
         else
         {
            return SUCCESS;
         }
    }
}

int check_duplicate(char *argv[],int i)
{
   // printf("%d\n",i);
    for(int j = 1;j < i;j++)
    {
        //printf("==>hii\n");
        if(strcmp(argv[i],argv[j]) == 0)
        {
            printf(RED"INFO :  %s file is already existed/repeated at index %d\n\n"RESET,argv[i],j);
            return FAILURE; 
        }
    }
    
    return SUCCESS;
}


/*-------------------------------------------------------------------------------------------------------------------*/

//adding and printing file_names  =>single linked list

/*-------------------------------------------------------------------------------------------------------------------*/

int add_file_name_to_list(char *argv[], int i,Slist **head)
{
    Slist *new = malloc(sizeof(Slist));
    if(new == NULL)
    {
        printf(RED"Memory is not allocated to add node\n\n"RESET);
        return FAILURE;
    }
    strcpy(new->file_name,argv[i]);
    new->file_link = NULL;
    Slist *temp ;
    temp = *head;
    if(*head == NULL)
    {
        *head = new;
    }
    else
    {
        while(temp->file_link != NULL)
        {
            temp = temp->file_link;
        }
        temp->file_link = new;
    }
    printf("INFO :  Successfull inserting file name %s into file linked list\n\n",argv[i]);
    return SUCCESS;
}

void print_list(Slist **head)
{
    Slist *temp = *head;
	if (temp == NULL)
	{
		printf(RED"INFO : List is empty\n\n"RESET);
	}
    else
    {
	    while (temp)		
	    {
		    printf("%s -> ", temp -> file_name);
		    temp = temp -> file_link;
	    }

	    printf("NULL\n");
    }
}

/*--------------------------------------------------------------------------------------------------------------*/