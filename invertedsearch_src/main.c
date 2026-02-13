/***************************************************************************************************************************************************
*Author		:Jami Charan Teja
*Date		:Mon 2 March 2025 14:00:05 IST
*File		:main.c
*Title		:Driver function
*Description	:This function acts like the driver function for the project inverted search
****************************************************************************************************************************************************/
#include "inverted_search.h"
int create_flag = 0;
int update_flag = 0;
int main(int argc, char *argv[])
{

	 /*declaring and creating hash table*/
	 Slist *head = NULL;
	H_table arr[28];
	create_hashtable(arr);
	/*check wheather the files are included or not*/
	if(argc > 1)
	{
		//validating file type file empty or not duplicate files and adding file name to list.
		for(int i = 1;i<argc;i++)
		{
			if(validate_arg(argv[i]) == SUCCESS) //check .txt or not
			{
				//file is in .txt format
				 if(validate_file(argv[i]) == SUCCESS)
				 {
					//file is not empty
					if(check_duplicate(argv,i) == SUCCESS)
					{
						/*there is no duplecate files*/
						//printf("There is no duplicate filenames so adding %s to list\n",argv[i]);
						if(add_file_name_to_list(argv,i,&head) == SUCCESS)
						{
							printf("INFO :  %s file name is added to the list\n\n",argv[i]);
						}
						else
						{
							printf("INFO :  %s failed to add file name to list\n",argv[i]);
						}
					} 
				}
			}
		}
		printf("Validation of files and argument vectors is done\n\n");
		print_list(&head);

		if(head == NULL)
		{
			printf(CYAN"INFO : No files are available for inverted search\n"RESET);
			printf(RED"Creation is not possible\n");
			return 0;
		}
		else
		{
			int choice,flag = 0;
			char ch;
			do
			{
				printf(BLUE"Select your choice among following options :\n\n"RESET);
				printf("1. Create Database \n2. Display Database\n3. Update Database\n4. Search\n5. Save Database\n\n");
				printf(BLUE"Enter your choice \n"RESET);
				scanf("%d",&choice);
				switch(choice)
				{
					case 1 :
					if(head != NULL || update_flag == 0 && create_flag== 0)
					{
						create_database(head,arr);
						create_flag = 1;
						printf(GREEN"INFO : Creation of Database is successfull\n\n"RESET);
					}
					else
					{
						printf(RED"INFO : Database is already updated so creation is not possible\n\n"RESET);
					}
					break;

					case 2 :
					if(create_flag== 1 || update_flag == 1)
					{
						display_database(arr);
						printf(GREEN"INFO : displayed all the data from list\n\n"RESET);
					}
					else
					{
						printf(RED"INFO : Database is not created or updated\n\n"RESET);
					}
					break;

					case 3 :
					if(create_flag == 0 && update_flag == 0)
					{
						if(update_database(arr,&head) == SUCCESS)
						{
							update_flag = 1;
							printf(GREEN"INFO : Updating database is successfull\n\n"RESET);
						}
					}
					else if(create_flag == 1)
					{
						printf(CYAN"Creation of database is already done\n\n"RESET);

					}
					else 
					{
						printf("INFO : Updation of database is already done\n\n"RESET);
					}
					break;

					case 4 :
					search(arr);
					printf(GREEN"INFO : Searching word from files is done\n\n"RESET);
					break;

					case 5 :
					 
						if(save_database(arr) == SUCCESS)
						{
							printf(GREEN"INFO : Saving database is done\n\n"RESET);
						}
						else
						{
							printf(RED"INFO : Saving database is failed\n\n"RESET);
						}
					 
					break;

					default :
					{
					printf(RED"INFO : Enter valid option\n\n"RESET);
					flag = 1;
					}

				}
				if(flag == 1)
				{
					break;
				}
				 label1:
				printf(BLUE"Enter n/N to discontinue or y/Y to continue\n"RESET);
				scanf(" %c",&ch);
				 if(ch == 'n' || ch == 'N')
				 break;
				 if(ch != 'y' || ch == 'Y')
				 {
					printf(RED"Please enter valid option\n"RESET);
					goto label1;
				 }
			} while (1);
		}


	}
	else
	{
		printf(RED"Enter valid number of arguments\n"RESET);
		return 0;
	}
}

void create_hashtable(H_table *arr)
{
	for(int i = 0;i < 28;i++)
	{
		arr[i].index = i;
		arr[i].Mlink = NULL;
	}
}