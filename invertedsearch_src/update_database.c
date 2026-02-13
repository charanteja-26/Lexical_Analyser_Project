 #if 1

 #include"inverted_search.h"

int update_database(H_table arr[],Slist **head)
{
    char up_file_name[30];
    printf(CYAN"Enter the update file name : "RESET);
    scanf("%s",up_file_name);
    if(validate_update_database_file(up_file_name) == FAILURE)
    {
        printf(RED"INFO : Updating database failure\n\n"RESET);
        return FAILURE;
    }
    FILE *fptr = fopen(up_file_name,"r");
    if(fptr == NULL)
    {
        printf("Opening file is failed\n\n");
        return FAILURE;
    }
    
    int index,file_count,word_count;
    char word[30],file_name[30];
     
    while(!feof(fptr))
    {
          
        fscanf(fptr,"#%d;%[^;];%d;",&index,word,&file_count);

        Mnode *new_Mnode = malloc(sizeof(Mnode));
        if(new_Mnode == NULL)
        {
            printf("Allocating memory is failed\n\n");
            return FAILURE;
        }
        new_Mnode->main_link = NULL;
        new_Mnode->Slink = NULL;
        strcpy(new_Mnode->word,word);
        new_Mnode->file_count = file_count;
        if(arr[index].Mlink == NULL)
        {
            arr[index].Mlink = new_Mnode;
        }
        else
        {
            Mnode *m_temp = arr[index].Mlink;
            while(m_temp->main_link != NULL)
            {
                m_temp = m_temp->main_link;
            }
            m_temp->main_link = new_Mnode;
        }
        
        for(int i = 0; i < file_count;i++)
        {
            fscanf(fptr,"%[^;];%d;",file_name,&word_count);
            file_validate(file_name,head);

            Snode *new_Snode = malloc(sizeof(Snode));
            if(new_Snode == NULL)
            {
                printf("Allocating memory is failed\n\n");
                return FAILURE;
            }
            new_Snode->sub_link = NULL;
            strcpy(new_Snode->file_name,file_name);
            new_Snode->word_count = word_count;
            if(new_Mnode->Slink == NULL)
            {
                new_Mnode->Slink = new_Snode;
            }
            else
            {
                Snode *s_temp = new_Mnode->Slink;
                while(s_temp->sub_link != NULL)
                {
                    s_temp = s_temp->sub_link;
                }
                s_temp->sub_link = new_Snode;
            }
        }
        fscanf(fptr,"#\n");
        printf("\n");
    }
    printf("\n");
    return SUCCESS;
   
}

int validate_update_database_file(char *file_name)
{
    /*validating ".txt or not"*/
    char *val =strchr(file_name,'.');
       //printf("\n\n");
        if(val && (strcmp(val,".txt") != 0))
         {
            printf(RED"INFO :  %s is not .txt file\n\n"RESET,file_name);
            return FAILURE;
        }
        /*---------------------------------------------------------------------------*/

/*checking file empty or not*/
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
         
    }
    /*---------------------------------------------------------------*/

    /*to check the given file is database file or not*/
    rewind(fptr);
    if(fgetc(fptr) == '#') 
    {

        fseek(fptr,-2,SEEK_END);
        char var = fgetc(fptr);
        // printf("%c\n",var);
         
        if(var == '#')
        {
            printf("INFO : %s is a database file\n\n",file_name);
        }
        else
        {
            printf("INFO : %s is not a database file\n\n",file_name);
            return FAILURE;
        }
    }
    else
    {
        printf("INFO : %s is not a database file\n\n",file_name);
        return FAILURE;
    }
    /*------------------------------------------------------------------------------*/
    fclose(fptr);
    return SUCCESS;
     
}

 
 
int file_validate(char *filename, Slist **head)
{

    Slist *temp = *head;
    Slist *prev = NULL;

    // Traverse and find the matching filename node
    while (temp) 
    {
        if (strcmp(temp->file_name, filename) == 0)
        {
            // Remove the node from the list
            if (prev) 
            {
                prev->file_link = temp->file_link;
            } 
            else 
            {
                *head = temp->file_link;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->file_link;
    }
    return SUCCESS;
}

#endif