/***************************************************************************************************************************************************
*Author         :Jami Charan Teja
*Date           :Mon 2 March 2025 15:56:15 IST
*File           :search.c
*Title          :To search the words.
*Description    :Each word is now used to search in the linkedlist. The word has to be compared with
		:each word in the linked list. When found, the file details can be retrieved. Since the
		:linkedlist is in sorted order, the complexity of searching the word in the complete list
		:can be avoided. While string comparison, if the word in linkedlist is greater than the
		:word to be search, it shows the word doesnt exists in the list,
****************************************************************************************************************************************************/
#if 1

#include "inverted_search.h"

void search(H_table arr[])
{
	/* Definition here */
	char word[30];
	printf(YELLOW"Enter the word you want to search : "RESET);
	scanf("%s",word);
	int index = my_find_index(word[0]);
	if(arr[index].Mlink != NULL)
	{
		search_word_count(arr[index].Mlink,word);
	}
	else
	{
		printf("There is no [%s] word is present in any of the files\n",word);
	}

}
void search_word_count(Mnode *head,char *data)
{
	while(head != NULL)
	{
		if(strcmp(head->word,data) == 0)
		{
			printf(BLUE"Word  %s  is  present  in  %d  file/s\n\n"RESET,data,head->file_count);
			Snode *temp = head->Slink;
			while(temp)
			{
				printf("In File : %s 	%d	time/s\n",temp->file_name,temp->word_count);
				temp = temp->sub_link;
			}
			printf("\n");
			return ;
			
		}
		else
		{
			head = head->main_link;
		}
		 
	}
	printf("There is no [%s] word is present in any of the files\n",data);
}
#endif