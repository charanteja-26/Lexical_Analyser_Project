/***************************************************************************************************************************************************
*Author         :Jami Charan Teja
*Date           :Mon 2 March 2025 14:04:05 IST
*File           :create_database.c
*Title          :To create the database
*Description    :The list of the files can be provided by storing all the file names in another file, FileList the names of the files which 
		:are to be documented are provided by this file. When a file is added or removed, FileList is changed accordingly.
		:So read the file names and start indexing.
****************************************************************************************************************************************************/
#if 1
int flag ;
#include "inverted_search.h"

void create_database(Slist *head,H_table arr[])
{
	/* Definition here */
	 while(head)
	 {
		read_file_data(arr,head->file_name);
		head = head->file_link;
	 }

}

void read_file_data(H_table arr[],char *file_name)
{
	//open file in read mode
	FILE *fptr = fopen(file_name,"r");
	//buffer string to store word
	char word[30];
	int index;
	while((fscanf(fptr,"%s",word)) != EOF)
	{
		//finding the index of word to store in hash table
		 int index = my_find_index(word[0]);
		//---------------------------------------------------------------------
		insert_last_mnode(arr,index,word,file_name);
	}
	fclose(fptr);
}

int my_find_index(char word)
{
	int index = 0;
	if(isdigit(word))
	{
		index = 26;
	}
	else if(!isalpha(word))
	{
		index = 27;
	}
	else
	{
		index = tolower(word) - 'a';
	}
	return index;
}
void insert_last_mnode(H_table arr[],int index,char *word,char *file_name)
{
	Mnode *new = malloc(sizeof(Mnode));
	if(new == NULL)
	{
		return ;
	}
	//new->file_count = 1;
	strcpy(new->word,word);
	//printf("word = %s\n", new->word);
	new->Slink = NULL;
	new->main_link = NULL;
	if(arr[index].Mlink == NULL)
	{
		new->file_count = 1;
		arr[index].Mlink = new;
		update_sub_node(file_name,&new);
		return ;
	}
	else
	{
		Mnode *temp = arr[index].Mlink;
		Mnode *prev;
		while(temp)
		{
			if(strcmp(temp->word,word)==0)
			{
				free(new);
				update_sub_node(file_name,&temp);
				if(flag == 1)
				{
					temp->file_count = temp->file_count + 1;
					flag = 0;
				}
				return ;
			}
			else
			{
				prev = temp;
				temp = temp->main_link;
			}
		}
		new->file_count = 1;
		update_sub_node(file_name,&new);
		prev->main_link = new;
		 
		return ;


	}

}

int update_sub_node(char *file_name,Mnode **head)
{
	Snode *new = malloc(sizeof(Snode));
	 
	if (new == NULL)
	{
		return FAILURE;
	}
	
	strcpy(new->file_name,file_name);
	new->sub_link = NULL;
	if((*head)->Slink == NULL)
	{
		new->word_count = 1;
		(*head)->Slink = new;
		return SUCCESS;
	}
	else
	{
		Snode *temp = (*head)->Slink;
		Snode *prev;
		while(temp)
		{
			if(strcmp(temp->file_name,file_name) == 0)
			{
				free(new);
				temp->word_count = temp->word_count+1;
				return SUCCESS;
			}
			else
			{
				prev = temp;
				temp = temp->sub_link;
			}
		}
		new->word_count = 1;
		prev->sub_link = new;
		flag = 1;
		return SUCCESS;
	}

}
#endif