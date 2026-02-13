/***************************************************************************************************************************************************
*Author         :Jami Charan Teja
*Date           :Mon 2 March 2025 16:06:15 IST
*File           :display_database.c
*Title          :To display  the results.
*Description    :When all the words are searched the ouput list is formed. In this the file with max count
		:(representing maximum word match ) can be selected and displayed. For advanced searched,
		:(weightage of words stored in database linkedlist) can also be used. So the results will be more
		:accurate.
****************************************************************************************************************************************************/
#if 1

#include "inverted_search.h"

void display_database(H_table arr[])
{
	/* Definition here */
	printf(BLUE"------------------------------------------Data base----------------------------------------------\n"RESET);
	printf(GREEN"[index]	  [word]	[file_count]	File/s: file_name		word_count\n"RESET);
	printf(BLUE"-------------------------------------------------------------------------------------------------\n"RESET);
	for(int i = 0;i < 28;i++)
	{
		 
		if(arr[i].Mlink != NULL)
		{
			print_word_file_count(arr[i].Mlink,i);
		}
	}
	printf(BLUE"------------------------------------------------------------------------------------------------\n"RESET);
}

void print_word_file_count(Mnode *head,int index)
{
	
	while(head != NULL)
	{
		printf(CYAN"%-9d %-15s %-10d  file/s : "RESET,index,head->word,head->file_count);
		Snode *temp = head->Slink;
		while(temp)
		{
			printf(CYAN"File/s : %-10s 	%-4d	"RESET,temp->file_name,temp->word_count);
			temp = temp->sub_link;
		}
		printf("\n");
		head = head->main_link;
	}
	printf("\n");
}

#endif