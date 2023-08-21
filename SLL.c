#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

struct book {
    char name[20];
    char author[30];
    int id;
    int days;
    struct book *next;
};
typedef struct book node;
node *start_lib=NULL;
struct student{
    char name[20];
    char book[20];
    char a[20];
    int days;
    int id;
    struct student *next;
};
typedef struct student noode;
noode *start=NULL;
int key,pass=9;
node* initialize_lib(node* start_lib)
{
    node *ptr,*book1,*book2,*book3,*book4,*book5;
    book1=(node*)malloc(sizeof(node));
    book1->next=NULL;
    start_lib=book1;
    strcpy(book1->name,"The Alchemist");
    strcpy(book1->author,"Paulo Coelho");
    book1->id=101;
    book1->days=30;
    ptr=book1;

    book2=(node*)malloc(sizeof(node));
    book2->next=NULL;
    strcpy(book2->name,"Atomic Habits");
    strcpy(book2->author,"James Clear");
    book2->id=102;
    book2->days=30;
    ptr->next=book2;
    ptr=book2;   
    
    book3=(node*)malloc(sizeof(node));
    book3->next=NULL;
    strcpy(book3->name,"And Then There Will Be None");
    strcpy(book3->author,"Agata Christie");
    book3->id=103;
    book3->days=30;
    ptr->next=book3;
    ptr=book3;  

    book4=(node*)malloc(sizeof(node));
    book4->next=NULL;
    strcpy(book4->name,"The Kite Runner");
    strcpy(book4->author,"Khaled Hosseini");
    book4->id=104;
    book4->days=30;
    ptr->next=book4;
    ptr=book4; 

    book5=(node*)malloc(sizeof(node));
    book5->next=NULL;
    strcpy(book5->name,"Pride And Prejudice");
    strcpy(book5->author,"Jane Austen");
    book5->id=105;
    book5->days=30;
    ptr->next=book5;
    return start_lib;
}
noode* book_issue(noode* start)
{
    node *ptr;
    noode *ptr2,*student1;
    int i=1,id,flag=0;
    if(start_lib==NULL)
    {
        printf("\t .....LIBRARY IS EMPTY .....\n");
        
    }
    else
    {
        ptr=start_lib;
        printf("\n\t***** BOOKS AVAILABLE *****");
        while(ptr!=NULL)
        {
            printf("\n\t_______________________\n");
            printf("\n\t Book %d",i);
            printf("\n\tBook Title : %s",ptr->name);
            printf("\n\tName of Author : %s",ptr->author);
            printf("\n\tBook Id : %d",ptr->id);
            printf("\n\tDays left for Return : %d",ptr->days);
            printf("\n\t________________________\n");
            ptr=ptr->next;
            i++;
        }
        printf("\n\n\n Enter the Book ID :");
        scanf("%d",&id);
        ptr=start_lib;
        while(ptr!=NULL){
            if(ptr->id==id){
                flag=1;
                break;
            }
            ptr=ptr->next;
        }
        if(flag==1)
        {
            ptr=start_lib;
            while(ptr->id!=id){

                ptr=ptr->next;
            }
            student1=(noode*)malloc(sizeof(noode));
            printf("Enter the student Details :\n");
            printf("Enter Name :");
            scanf("%s",student1->name);
            strcpy(student1->book,ptr->name);
            strcpy(student1->a,ptr->author);
            student1->days=ptr->days;
            student1->id=ptr->id;
            student1->next=NULL;
            printf("\n\t Issue of Book ID %d done successfully !\n",student1->id);
            printf("\n\n\t*******************\n");
            if(start==NULL)
            {
                start=student1;
            }
            else{
                ptr2=start;
                while(ptr2->next!=NULL){
                    ptr2=ptr2->next;
                }
                ptr2->next=student1;
            }
            delete_book(student1->id);
            
        }
        else{
            printf("\n\n\t  ....Invalid Option !..\n");
            
        }
    }
    return start;
}
noode *book_return(noode *start){
    noode *ptr,*preptr;
    char bookname[30],authorname[30];
    int flag=0,id,identity,c=0,d=1,da,D;
    printf("\n\n\t****** Books Submission: *******\n");
    printf("\n\n\t Enter your Book ID: ");
    scanf("%d",&identity);
    printf("\n\n\t Enter the number of days the book was borrowed");
    scanf("%d",&da);
    ptr=start;
    while(ptr!=NULL){
        if(ptr->id==identity){
            flag=1;
            break;
        }
        ptr=ptr->next;
    }
    if(flag==1){
        ptr=start;
        while(ptr!=NULL){
            c++;
            ptr=ptr->next;
        }
        ptr=start;
        while(ptr->id!=identity){
                d++;
            ptr=ptr->next;
        }
        ptr=start;
        if( d==1 ){
            printf("\n\t_________________\n");
            printf("\n\t Student Name: %s",start->name);
            printf("\n\t Name of Book Issued: %s",start->book);
            if(da>ptr->days)
            {
                printf("\n\n\tPay FINE of 100 rupees");
            }
            else{
                printf("\n\n\t NO FINE");
            }
            printf("\n\t_________________\n");
            printf("\n\n\t Return of Book ID %d done successfully!\n",identity);
            printf("\n\n\t*****************\n");
            strcpy(bookname,start->book);
            strcpy(authorname,start->a);
            id=start->id;
            D=start->days;
            start=start->next;
            free(ptr);
          add_book(bookname,authorname,id,D);
        }else{
            ptr=start;
            while(ptr->id!=identity){
                preptr=ptr;
                ptr=ptr->next;
            }
            printf("\n\t_________________\n");
            printf("\n\t Student Name: %s",ptr->name);
            printf("\n\t Name of Book Issued: %s",ptr->book);
             if(da>ptr->days)
            {
                printf("\n\n\tPay FINE of 100 rupees");
            }
            else{
                printf("\n\n\t NO FINE");
            }
            printf("\n\t Book ID: %d",ptr->id);
            printf("\n\t_________________\n");
            strcpy(bookname,ptr->book);
            strcpy(authorname,ptr->a);
            id=ptr->id;
            D=ptr->days;
            preptr->next=ptr->next;
            free(ptr);
            add_book(bookname,authorname,id,D);
        }
        printf("\n\t Thank you! \n\t Do visit again! ");
        
    }else{
        printf("\n\tSorry the book doesn't exist! Please recheck the entered ID");
        
            }
    return start;
}
void display(noode *start){
    noode *ptr;
    ptr=start;
    printf("\n\t***** Details of Students: ******\n");
        printf("\n\t_________________\n");
    while(ptr!=NULL){
        
        printf("\n\t\t Student Name: %s",ptr->name);
        printf("\n\t\t Name of Book Issued: %s",ptr->book);
        printf("\n\t\t Book ID: %d",ptr->id);
        printf("\n\t_________________\n");
        printf("\n\n\t*****************\n");
        ptr=ptr->next;
    }
 
}

void delete_book(int id){
    node *ptr,*preptr;
    int c=0;
    ptr=start_lib;
    while(ptr!=NULL){
        c++;
        ptr=ptr->next;
    }
    if(c==1){
        ptr=start_lib;
        start_lib=NULL;
        free(ptr);
    }else if(start_lib->id==id){
        ptr=start_lib;
        start_lib=start_lib->next;
        free(ptr);
    }else{
        ptr=start_lib;
        while(ptr->id!=id){
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        free(ptr);
    }
    
}



    void add_book(char bookname[30],char authorname[30],int id,int D){
    node *ptr,*new_book;
    new_book=(node *)malloc(sizeof(node));
    strcpy(new_book->name,bookname);
    strcpy(new_book->author,authorname);
    new_book->id=id;
    new_book->days=D;
    new_book->next=NULL;
    if(start_lib==NULL){
        start_lib=new_book;
    }else{
        ptr=start_lib;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=new_book;
    }
    
}
void greetings(){
    printf("\n\n");
    printf("\t\t\t     **************\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *     ----------------------------     *\n");
    printf("\t\t\t     *      WELCOME TO STUDENT LIBRARY      *\n");
    printf("\t\t\t     *     ----------------------------     *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     **************\n");
    printf("\n\n");
    printf("\t\t\t     **************\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *       ------------------------       *\n");
    printf("\t\t\t     *           STUDENT LIBRARY            *\n");
    printf("\t\t\t     *       ------------------------       *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     **************\n");
    
}
void main_menu(){
    int choice;

    here:
    printf("\nEnter the password to enter\n");
    scanf("%d",&key);
    if(key==pass)
    {
    do{
        printf("\n\t\t\t    ***WELCOME***    \t\t\t\n");
        printf("\n\t\t\t*****************\n");
        printf("\n\t\t\t\t      MAIN MENU: ");
        printf("\n\t\t\t\t     1.ISSUE OF BOOKS ");
        printf("\n\t\t\t\t     2.RETURN OF BOOKS ");
        printf("\n\t\t\t\t     3.DISPLAY STUDENT DETAILS ");
        printf("\n\t\t\t\t     4.CHANGE PASSWORD ");
        printf("\n\t\t\t\t     5.EXIT\n ");
        printf("\n\t\t\t*****************\n");
        printf("\n\t\t\t\t      Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                start=book_issue(start);
                break;
            }
            case 2:{
                start=book_return(start);
                break;
            }
            case 3:{
                display(start);
                break;
            }

            case 4: lable:
                    printf("\nEnter your old password");
                    scanf("%d",&key);
                    if(key==pass)
                    {
                        printf("\nEnter the new password");
                        scanf("%d",&pass);
                        printf("password changed successfully");
                        
                    }
                    else
                    {
                        printf("INVALID PASSWORD");
                        goto lable;
                    }
                    break; 
            case 5:{
                exit(1);
            }
            default:{
                printf("\n\t\t\t\t      ...Invalid Option!...\n");
              
              
            }
        }
    }while(choice!=4);
    }
    else
    {
        printf("\nInvalid password");
        goto here;
    }
}
int main(){
    FILE *fp;
    fp=fopen("SLL.c","w+");
    start_lib=initialize_lib(start_lib);
    greetings();
    main_menu();
    fclose(fp);
    return 0;
}




