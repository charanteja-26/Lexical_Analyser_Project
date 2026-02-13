#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

/*colours-------------------------------------------------------*/
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
/*-----------------------------------------------------------*/
#define SUCCESS 1
#define FAILURE 0
#define FILEEMPTY -1

/* to store filenames in list after validating
-------------------------------------------------------------*/

typedef struct file_node
{
    char file_name[30];
    struct file_node *file_link;
}Slist;

/*-----------------------------------------------------------------*/

/*structure for hashtable mainnode and subnode*/
typedef struct subnode
{
    int word_count;
    char file_name[30];
    struct subnode *sub_link;
}Snode;

typedef struct mainnode
{
    int file_count;
    char word[30];
    Snode *Slink;
    struct mainnode *main_link;
}Mnode;

typedef struct hash_table
{
    int index;
    Mnode *Mlink;
}H_table;

 
int my_find_index(char word);
/*Creating database*/
//void create_database(FILE *filelist);

/*displaying*/
//void display_output(File* output_list);

/*search*/
//file* search (char *word, word *indexlist, file* output_list);

/*validate ".txt" files*/
int validate_arg(char *file_name);

/*validate file(present && empty or not)*/
int validate_file(char *file_name);

/*validate duplicate file names*/
int check_duplicate(char *argv[],int i);

/*adding filenames to list*/
int add_file_name_to_list(char *argv[], int i,Slist **head);

/*print file names in list*/
void print_list(Slist **head);

/*create hash table*/
void create_hashtable(H_table *arr);


/* Create database*/
void read_file_data(H_table arr[],char *file_name);

void create_database(Slist *head,H_table arr[]);

void insert_last_mnode(H_table arr[],int index,char *word,char *file_name);

int update_sub_node(char *file_name,Mnode **head);

/*--------------------------------------------------------------*/

/*Display database*/

void print_word_file_count(Mnode *head,int);

void display_database(H_table arr[]);

/*----------------------------------------------------------------*/

/*searching*/

void search(H_table arr[]);

void search_word_count(Mnode *head,char *data);

/*-----------------------------------------------------------------*/

/*update database*/
int validate_update_database_file(char *file_name);

int update_database(H_table arr[],Slist **head);

int file_validate(char *filename, Slist **head);


/*------------------------------------------------------------------*/

/*save database*/

int save_database(H_table arr[]);

/*--------------------------------------------------------------------*/
