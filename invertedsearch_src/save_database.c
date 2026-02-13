 #include"inverted_search.h"

 int save_database(H_table arr[])
 {
    //to store the filke name
    char file_name[30];
    //prompt the user to enter the file_name
    printf("Enter the file name : ");
    scanf("%s",file_name);
    if(validate_arg(file_name) == FAILURE)
    {
        printf(RED"INFO : Database file is entered without extention. Enter filename <.txt>\n\n"RESET);
        return FAILURE;
    }

    //open the file
    FILE *backup_fptr = fopen(file_name,"w");

    for (int i = 0; i < 28; i++)
    {
        Mnode *mn_temp = arr[i].Mlink;
        while(mn_temp != NULL)
        {
            fprintf(backup_fptr,"#%d;%s;%d;",i, mn_temp->word, mn_temp->file_count);
            Snode *sn_temp = mn_temp->Slink;
            if(sn_temp != NULL)
            {
                while(sn_temp != NULL)
                {
                    fprintf(backup_fptr,"%s;%d;",sn_temp->file_name, sn_temp->word_count);
                    sn_temp = sn_temp->sub_link;
                }
            }
            fprintf(backup_fptr,"#\n");
            mn_temp = mn_temp->main_link;
        }

    }
    
    fclose(backup_fptr);

    return SUCCESS;

 }

  