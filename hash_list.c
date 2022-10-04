#include <stdio.h>
#include <stdlib.h>
 
 /*1. insert a new node in middle of hash list
2. insert a new node at end of hash list
3. insert a new node at beginning of hash list
4. reorder/sort list in hash list
5. replace a node at middle ( delete existing node add new at same place) of hash list
6. insert node in ascending order in to hash list
7. insert node in descending order in the has list
8. write a function to convert to hash list

*/
struct node {

  struct node *next;

  int data;

};

typedef struct hash_node
{
  int index;
  struct node *hash_index_list;
  struct hash_node *next;

}hash_l;

hash_l *hash_head= NULL;
 

 int insert_newnode_mid(int data);
 int insert_newnode_end(int data);
 int insert_newnode_beginning(int data);
 int display(int node);
 int display_all();
 int sort_hashlist();
 int insert_ascending_order(int data);
 int insert_descending_order(int data);
 int replace_newnode_mid(int data);


 int main()
 {
  int option;
  int value;

  while(1)
  {

    printf("\n1. insert a new node in middle of hash list\n2. insert a new node at end of hash list\n3. insert a new node at beginning of hash list\n");
    printf("4. reorder/sort list in hash list\n5. replace a node at middle ( delete existing node add new at same place) of hash list\n");
    printf("6. insert node in ascending order in to hash list\n7. insert node in descending order in the has list\n8. write a function to convert to hash list\n");
    printf("9. display particular hash list\n10. Display all hash list\n\n Enter a options : ");

    scanf("%d", &option);


    switch(option)
    {

      case 1:
            printf("Enter a value: ");
            scanf("%d", &value);

            insert_newnode_mid(value);
            break;
      case 2:
            printf("Enter a value: ");
            scanf("%d", &value);

            insert_newnode_end(value);
            break;
      case 3:
            printf("Enter a value: ");
            scanf("%d", &value);

            insert_newnode_beginning(value);
            break;
      case 4:
            sort_hashlist();
            break;

      case 5:
            printf("Enter a value: ");
            scanf("%d", &value);

            replace_newnode_mid(value);
            break;

      case 6:
            printf("Enter a value: ");
            scanf("%d", &value);
            insert_ascending_order(value);

            break;
      case 7:
            printf("Enter a value: ");
            scanf("%d", &value);
            insert_descending_order(value);
            break;
      case 9:
            printf("Enter a node: ");
            scanf("%d", &value);
            display(value);
            break;

      case 10:
            display_all();
            break;

      default:
            printf("Select a valid Number\n");
            break;

    }
  }



  return 0;
 }


 int insert_newnode_end(int data)
 {
    int index;

    hash_l *hash_table = hash_head;
    hash_l *hash_table_prev= NULL; 
    hash_l *hash_new = NULL;
    struct node *sl_new=NULL;

    index = data%10;

    // if hash table is empty create table and list here
    if(hash_table == NULL)
    {
      
        hash_new = (hash_l *)malloc(sizeof(hash_l)); 
       
        hash_new->index = index;
        hash_new->next = NULL;
        hash_new->hash_index_list= NULL;
       
        sl_new = malloc(sizeof(struct node));
        sl_new->data = data;
        sl_new->next = NULL;
      
        hash_new->hash_index_list= sl_new;
        hash_head= hash_new;
        return 0;

    }

    //new list data 
    sl_new = (struct node *)malloc(sizeof(struct node));
    sl_new->data = data;
    sl_new->next = NULL;
    
    
    //here check the  hash table index is available or not created
    while(hash_table)
    {
      if(hash_table->index == index)
      {
        /* if index is smatch alredy index table is available just jump to list and add it end*/
        struct node *temp = hash_table->hash_index_list;
        struct node *prev= temp;
        if(temp == NULL)
        {
          hash_table->hash_index_list = sl_new;
          return 0;

        }
        while(temp)
        {
          prev= temp;
          temp = temp ->next;
        }
        prev->next = sl_new;
        return 0;
      }
      hash_table_prev = hash_table;
      hash_table = (hash_l *)hash_table->next;
    }

    hash_new = (hash_l *)malloc(sizeof(hash_l)); 
    hash_new->index = index;
    hash_new->next = NULL;
    hash_new->hash_index_list = sl_new;
    hash_table_prev->next = hash_new;

    return 0;


 }


 int display_all()
 {

    hash_l *hash_table = (hash_l *) hash_head;
    struct node *sl= NULL;
   
    if(hash_table == NULL)
    {
      printf("\nList Empty\n");
      return 0;

    }
    while(hash_table != NULL)
    {

      printf("hash Table index : %d \n", hash_table->index);
      sl= hash_table->hash_index_list;
      if(sl == NULL)
      {
        printf(" Hash list of this index is empty\n");
      } 
      printf("Hash List :\t");
      while(sl)
      {

        printf("%d\t", sl->data);
        sl= sl->next;
      }
      printf("\n");
      hash_table = (hash_l *)hash_table->next;   
    
    }
    return 0;
 }


 int insert_newnode_mid(int data)
 {
  int index;
    int flag =1;
    int count =1;

    hash_l *hash_table = hash_head;
    hash_l *hash_table_prev= NULL; 
    hash_l *hash_new = NULL;
    struct node *sl_new=NULL;

    index = data%10;

    // if hash table is empty create table and list here
    if(hash_table == NULL)
    {
      
        hash_new = (hash_l *)malloc(sizeof(hash_l)); 
       
        hash_new->index = index;
        hash_new->next = NULL;
        hash_new->hash_index_list= NULL;
       
        sl_new = malloc(sizeof(struct node));
        sl_new->data = data;
        sl_new->next = NULL;
      
        hash_new->hash_index_list= sl_new;
        hash_head= hash_new;
        return 0;

    }

    //new list data 
    sl_new = (struct node *)malloc(sizeof(struct node));
    sl_new->data = data;
    sl_new->next = NULL;
    
    
    //here check the  hash table index is available or not created
    while(hash_table)
    {
      if(hash_table->index == index)
      {
        /* if index is smatch alredy index table is available just jump to list and add it end*/
        struct node *temp = hash_table->hash_index_list;
        struct node *prev= temp;

        if(temp == NULL)
        {
          hash_table->hash_index_list = sl_new;
          return 0;

        }
        //here count the particular hash index hash list

        while(temp)
        {
          flag++;
          temp = temp->next;
        }

        temp = hash_table->hash_index_list;
        while(temp)
        {
          if((flag/2) == count)
          {
            break;
          }
          count++;
          prev= temp;
          temp = temp ->next;
        }
        sl_new->next =prev->next;
        prev->next = sl_new;
        return 0;
      }
      hash_table_prev = hash_table;
      hash_table = (hash_l *)hash_table->next;
    }

    hash_new = (hash_l *)malloc(sizeof(hash_l)); 
    hash_new->index = index;
    hash_new->next = NULL;
    hash_new->hash_index_list = sl_new;
    hash_table_prev->next = hash_new;

    return 0;

 }
 
 int insert_newnode_beginning(int data)
 {
    int index;

    hash_l *hash_table = hash_head;
    hash_l *hash_table_prev= NULL; 
    hash_l *hash_new = NULL;
    struct node *sl_new=NULL;

    index = data%10;

    // if hash table is empty create table and list here
    if(hash_table == NULL)
    {
      
        hash_new = (hash_l *)malloc(sizeof(hash_l)); 
       
        hash_new->index = index;
        hash_new->next = NULL;
        hash_new->hash_index_list= NULL;
       
        sl_new = malloc(sizeof(struct node));
        sl_new->data = data;
        sl_new->next = NULL;
      
        hash_new->hash_index_list= sl_new;
        hash_head= hash_new;
        return 0;

    }

    //new list data 
    sl_new = (struct node *)malloc(sizeof(struct node));
    sl_new->data = data;
    sl_new->next = NULL;
    
    
    //here check the  hash table index is available or not created
    while(hash_table)
    {
      if(hash_table->index == index)
      {
        /* if index is smatch alredy index table is available just jump to list and add it end*/
        struct node *temp = hash_table->hash_index_list;
        struct node *prev= temp;
        if(temp == NULL)
        {
          hash_table->hash_index_list = sl_new;
          return 0;

        }
        
        
        sl_new->next = hash_table->hash_index_list;
        hash_table->hash_index_list = sl_new;
       
        return 0;
      }
      hash_table_prev = hash_table;
      hash_table = (hash_l *)hash_table->next;
    }

    hash_new = (hash_l *)malloc(sizeof(hash_l)); 
    hash_new->index = index;
    hash_new->next = NULL;
    hash_new->hash_index_list = sl_new;
    hash_table_prev->next = hash_new;

    return 0;
 }

int display(int node)
{
  int node_count =1;

  hash_l *hash_table = (hash_l *) hash_head;
    struct node *sl= NULL;
   
    if(hash_table == NULL)
    {
      printf("\nList Empty\n");
      return 0;

    }
    while(hash_table != NULL)
    {

      if(node == node_count)
      {
          printf("hash Table index : %d \n", hash_table->index);
          sl= hash_table->hash_index_list;
          if(sl == NULL)
          {
            printf(" Hash list of this index is empty\n");
          } 
          printf("Hash List :\t");
          while(sl)
          {
            printf("%d\t", sl->data);
            sl= sl->next;
          }
          printf("\n");
          return 0;
      }
      node_count++;
      hash_table = (hash_l *)hash_table->next;   
    
    }
    printf("\n Node is not present...!!!\n");
    return 0;
}

int sort_hashlist()
{
  hash_l *hash_table = (hash_l *) hash_head;
  struct node *sl= NULL;
   
    if(hash_table == NULL)
    {
      printf("\nList Empty\n");
      return 0;
    }

    while(hash_table != NULL)
    {
          sl= hash_table->hash_index_list;
          if(sl == NULL)
          {
            printf(" Hash list of this index is empty\n");
          } 
          
          //here sort list
          struct node *nextlist =NULL;
          while(sl)
          {
            nextlist = sl->next;
            while(nextlist)
            {
                if(sl->data > nextlist->data)
                {
                  int temp_data = sl->data;
                  sl->data = nextlist->data;
                  nextlist->data = temp_data;
                }
                nextlist = nextlist->next;
            }
            sl= sl->next;
          }
          

      hash_table = (hash_l *)hash_table->next;   
    
    }
    
    return 0;
}


int insert_ascending_order(int data)
{

  int index;

    hash_l *hash_table = hash_head;
    hash_l *hash_table_prev= NULL; 
    hash_l *hash_new = NULL;
    struct node *sl_new=NULL;

    index = data%10;

    // if hash table is empty create table and list here
    if(hash_table == NULL)
    {
        hash_new = (hash_l *)malloc(sizeof(hash_l)); 
        hash_new->index = index;
        hash_new->next = NULL;
        hash_new->hash_index_list= NULL;
       
        sl_new = malloc(sizeof(struct node));
        sl_new->data = data;
        sl_new->next = NULL;
      
        hash_new->hash_index_list= sl_new;
        hash_head= hash_new;
        return 0;
    }

    //new list data 
    sl_new = (struct node *)malloc(sizeof(struct node));
    sl_new->data = data;
    sl_new->next = NULL;
    
    
    //here check the  hash table index is available or not created
    while(hash_table)
    {
      if(hash_table->index == index)
      {
        /* if index is smatch alredy index table is available just jump to list and add it end*/
        struct node *temp = hash_table->hash_index_list;
        struct node *prev= temp;
        
        //check the node is contain empty list
        if(temp == NULL)
        {
          hash_table->hash_index_list = sl_new;
          return 0;
        }
        else if(temp->data >= data)
        {
          sl_new->next = hash_table->hash_index_list;
          hash_table->hash_index_list = sl_new;
          return 0;

        }

        while(temp)
        {
          if(temp->data >= data)
          {
            sl_new->next = prev->next;
            prev->next = sl_new;
            return 0;
          }
          prev =temp;
          temp = temp->next;

        }
                
        prev->next = sl_new;   
        return 0;
      }
      hash_table_prev = hash_table;
      hash_table = (hash_l *)hash_table->next;
    }

    hash_new = (hash_l *)malloc(sizeof(hash_l)); 
    hash_new->index = index;
    hash_new->next = NULL;
    hash_new->hash_index_list = sl_new;
    hash_table_prev->next = hash_new;

    return 0;
}


int insert_descending_order(int data)
{
  int index;

    hash_l *hash_table = hash_head;
    hash_l *hash_table_prev= NULL; 
    hash_l *hash_new = NULL;
    struct node *sl_new=NULL;

    index = data%10;

    // if hash table is empty create table and list here
    if(hash_table == NULL)
    {
        hash_new = (hash_l *)malloc(sizeof(hash_l)); 
        hash_new->index = index;
        hash_new->next = NULL;
        hash_new->hash_index_list= NULL;
       
        sl_new = malloc(sizeof(struct node));
        sl_new->data = data;
        sl_new->next = NULL;
      
        hash_new->hash_index_list= sl_new;
        hash_head= hash_new;
        return 0;
    }

    //new list data 
    sl_new = (struct node *)malloc(sizeof(struct node));
    sl_new->data = data;
    sl_new->next = NULL;
    
    
    //here check the  hash table index is available or not created
    while(hash_table)
    {
      if(hash_table->index == index)
      {
        /* if index is smatch alredy index table is available just jump to list and add it end*/
        struct node *temp = hash_table->hash_index_list;
        struct node *prev= temp;
        
        //check the node is contain empty list
        if(temp == NULL)
        {
          hash_table->hash_index_list = sl_new;
          return 0;
        }
        else if(temp->data <= data)
        {
          sl_new->next = hash_table->hash_index_list;
          hash_table->hash_index_list = sl_new;
          return 0;

        }

        while(temp)
        {
          if(temp->data <= data)
          {
            sl_new->next = prev->next;
            prev->next = sl_new;
            return 0;
          }
          prev =temp;
          temp = temp->next;

        }
                
        prev->next = sl_new;   
        return 0;
      }
      hash_table_prev = hash_table;
      hash_table = (hash_l *)hash_table->next;
    }

    hash_new = (hash_l *)malloc(sizeof(hash_l)); 
    hash_new->index = index;
    hash_new->next = NULL;
    hash_new->hash_index_list = sl_new;
    hash_table_prev->next = hash_new;

    return 0;
}


int replace_newnode_mid(int data)
 {
  int index;
    int flag =1;
    int count =1;

    hash_l *hash_table = hash_head;
    hash_l *hash_table_prev= NULL; 
    hash_l *hash_new = NULL;
    struct node *sl_new=NULL;
    struct node *delete_midnode = NULL;

    index = data%10;

    // if hash table is empty create table and list here
    if(hash_table == NULL)
    {
      
        hash_new = (hash_l *)malloc(sizeof(hash_l)); 
       
        hash_new->index = index;
        hash_new->next = NULL;
        hash_new->hash_index_list= NULL;
       
        sl_new = malloc(sizeof(struct node));
        sl_new->data = data;
        sl_new->next = NULL;
      
        hash_new->hash_index_list= sl_new;
        hash_head= hash_new;
        return 0;

    }

    //new list data 
    sl_new = (struct node *)malloc(sizeof(struct node));
    sl_new->data = data;
    sl_new->next = NULL;
    
    
    //here check the  hash table index is available or not created
    while(hash_table)
    {
      if(hash_table->index == index)
      {
        /* if index is match alredy index table is available just jump to list and add it end*/
        struct node *temp = hash_table->hash_index_list;
        struct node *prev= temp;

        if(temp == NULL)
        {
          hash_table->hash_index_list = sl_new;
          return 0;

        }
        //here count the particular hash index hash list

        while(temp)
        {
          flag++;
          temp = temp->next;
        }

        temp = hash_table->hash_index_list;
        while(temp)
        {
          if((flag/2) == count)
          {
            break;
          }
          count++;
          prev= temp;
          temp = temp ->next;
        }

        delete_midnode = prev->next;
        sl_new->next =prev->next->next;
        prev->next = sl_new;
        free(delete_midnode);
        delete_midnode= NULL;
        return 0;
      }
      hash_table_prev = hash_table;
      hash_table = (hash_l *)hash_table->next;
    }

    hash_new = (hash_l *)malloc(sizeof(hash_l)); 
    hash_new->index = index;
    hash_new->next = NULL;
    hash_new->hash_index_list = sl_new;
    hash_table_prev->next = hash_new;

    return 0;
}