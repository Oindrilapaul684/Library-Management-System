#include <stdio.h>
#include <stdlib.h>
void main(){
struct reader{
    int id;
    char name[20];
    char due;
    int dbid;
} rdr[10]={0};
struct book{
    int id;
    char name[30];
    char author[20];
    char avbl;
    int rid;
} bk[20]={0};
int choice1,choice_admin,choice_reader, searchid, searchid1, n, m, i;
printf("\n\t\tWELCOME!\n");
printf("\n\tLibrary Management System\n\t=========================\n");
while(1)
    {
        printf("Enter 1 for READER & 2 for ADMIN & 3 for EXIT \n Enter your choice:");
        scanf("%d",&choice1);
    switch(choice1)
    {
        case 1:
        do{
            printf("\n\tLibrary Management System\n\t=========================\n1. Search book\t\t2. Add new reader\n3. Issue book\t\t4. Return book\n5. Delete reader\t6. List of books\n7. Exit\n\nEnter your choice: ");
            scanf("%d", &choice_reader);
            switch(choice_reader){
                case 1:
                    printf("Enter book ID: ");
                    scanf("%d", &searchid);
                    n=0;
                    for( i=0; i<20; i++){
                            if (searchid == bk[i].id){
                                printf("\n\tBook Information\nBook ID: %d\tBook Name:%s\nAuthor Name: %s\nAvailable: %c\tDue by Reader ID: %d\n", bk[i].id,bk[i].name, bk[i].author, bk[i].avbl, bk[i].rid);
                                n++;
                                }
                                }
                                if(n==0){
                                    printf("Book not found.\n\n");
                                    }
                    break;
                case 2:
                    for(i=0; i<10; i++){
                            if (rdr[i].id==0){
                                printf("Enter Reader's name: ");
                                scanf("%s", rdr[i].name);
                                printf("Enter Reader id: ");
                                scanf("%d", &rdr[i].id);
                                rdr[i].due='n';
                                rdr[i].dbid=0;
                                i=10;
                                printf("Reader added successfully.\n\n");
                            }

                    }
                    break;
                case 3:
                    printf("Enter book ID: ");
                    scanf("%d", &searchid);
                    printf("Enter reader ID: ");
                    scanf("%d", &searchid1);
                    n=0;
                    m=0;
                    for(i=0; i<20; i++){
                         if (searchid==bk[i].id && bk[i].avbl=='y'){
                                 bk[i].avbl='n';
                                 bk[i].rid=searchid1;
                                 n++;
                                 i=20;
                                 }
                                 }
                    for(i=0; i<10; i++){
                            if (searchid1==rdr[i].id && rdr[i].due=='n'){
                                rdr[i].due='y';
                                rdr[i].dbid=searchid;
                                m++;
                                i=10;
                                }
                                }
                    if(n==1 && m==1){
                            printf("Book issued successfully.\n\n");
                    }
                    else if(n==1 && m==0){
                            for( i=0; i<20; i++){
                                if (searchid==bk[i].id){
                                    bk[i].avbl='y';
                                    bk[i].rid=0;
                                    i=20;
                                    }
                                }
                                printf("Book not issued.\nReader has a due book.\n\n");
                            }
                    break;
                case 4:
                    printf("Enter book ID: ");
                    scanf("%d", &searchid);
                    for(i=0; i<20; i++){
                            if (searchid==bk[i].id){
                                bk[i].avbl='y';
                                searchid1=bk[i].rid;
                                bk[i].rid=0;
                                }
                            }
                    for(i=0; i<10; i++){
                            if (searchid1==rdr[i].id){
                                rdr[i].due='n';
                                rdr[i].dbid=0;
                                }
                            }
                            printf("Book ID %d submitted successfully.\n\n", searchid);
                    break;
                case 5:
                    printf("Enter reader ID to be deleted: ");
                    scanf("%d", &searchid);
                    n=0;
                    for(i=0; i<10; i++){
                            if (searchid==rdr[i].id){
                                for(i=i; i<10; i++){
                                    rdr[i]=rdr[i+1];
                                }
                                n++;
                            }
                    }
                    if(n!=0){
                            printf("Reader ID %d deleted.\n\n", searchid);
                    }
                    else
                        printf("Reader not found.\n\n");
                    break;
                case 6:
                    n=0;
                    for( i=0; i<20; i++){
                            if(bk[i].id != 0){
                                n++;
                    }
                    }
                    printf("\n\t\tBook list\tTotal books:%d\n\nID\tName\t\t\tAuthor\t\t\tAvailable\tReader ID\n\n", n);
                    for( i=0; i<20; i++){
                            if(bk[i].id != 0){
                                printf("%d\t%s\t\t%s\t\t%c\t\t%d\n", bk[i].id, bk[i].name,
                                       bk[i].author, bk[i].avbl, bk[i].rid);
                    }
                    }
                    break;
                case 7:
                    printf("......THANK TOU FOR CHOOSING OUR LIBRARY......\n");
                    break;
                default:
                    printf("INVALID CHOICE!!!PLEASE ENTER A NUMBER BETWEEN 1-7.");
                    }
        }while(choice_reader!=7);
        break;
    case 2:
        do{
            printf("\n\tLibrary Management System\n\t=========================\n1. Add a new book\t2. Search book\n3. Add new reader\t4. Search reader\n5. Delete book\t\t6. Delete reader\n7. List of books\t8. Exit\n\nEnter your choice: ");
            scanf("%d", &choice_admin);
            switch(choice_admin){
                case 1:
                    for( i=0; i<20; i++){
                            if (bk[i].id==0){
                                printf("Enter name of the book: ");
                                scanf("%s", bk[i].name);
                                printf("Enter name of the author: ");
                                scanf("%s", bk[i].author);
                                printf("Enter book ID: ");
                                scanf("%d", &bk[i].id);
                                bk[i].avbl='y';
                                bk[i].rid=0;
                                i=20;
                                printf("Book added successfully.\n\n");
                                }
                                }
                    break;
                case 2:
                    printf("Enter book ID: ");
                    scanf("%d", &searchid);
                    n=0;
                    for( i=0; i<20; i++){
                            if (searchid == bk[i].id){
                                printf("\n\tBook Information\nBook ID: %d\tBook Name:%s\nAuthor Name: %s\nAvailable: %c\tDue by Reader ID: %d\n", bk[i].id,bk[i].name, bk[i].author, bk[i].avbl, bk[i].rid);
                                n++;
                                }
                            }
                            if(n==0){
                                    printf("Book not found.\n\n");
                            }
                    break;
                case 3:
                    for(i=0; i<10; i++){
                            if (rdr[i].id==0){
                                printf("Enter Reader's name: ");
                                scanf("%s", rdr[i].name);
                                printf("Enter Reader id: ");
                                scanf("%d", &rdr[i].id);
                                rdr[i].due='n';
                                rdr[i].dbid=0;
                                i=10;
                                printf("Reader added successfully.\n\n");
                            }

                    }
                    break;
                case 4:
                    printf("Enter Reader ID: ");
                    scanf("%d", &searchid);
                    n=0;
                    for(i=0; i<10; i++){
                            if (searchid==rdr[i].id){
                                printf("\n\tReader Information\nReader ID: %d\tReaderName: %s\nDue: %c\t\tDue book ID: %d\n", rdr[i].id, rdr[i].name, rdr[i].due,rdr[i].dbid);
                                n++;
                    }
                    }
                    if(n==0){
                            printf("Reader not found.\n\n");
                    }
                     break;
                case 5:
                    printf("Enter book ID to be deleted: ");
                    scanf("%d", &searchid);
                    n=0;
                    for(i=0; i<20; i++){
                            if (searchid==bk[i].id){
                                for(i=i; i<20; i++){
                                    bk[i]=bk[i+1];
                    }n++;
                    }
                    }
                    if(n!=0){
                        printf("Book ID %d deleted.\n\n", searchid);
                        }
                    else
                        printf("Book not found.\n\n");
                    break;
                case 6:
                    printf("Enter reader ID to be deleted: ");
                    scanf("%d", &searchid);
                    n=0;
                    for(i=0; i<10; i++){
                            if (searchid==rdr[i].id){
                                for(i=i; i<10; i++){
                                    rdr[i]=rdr[i+1];
                                }
                                n++;
                            }
                    }
                    if(n!=0){
                            printf("Reader ID %d deleted.\n\n", searchid);
                    }
                    else
                        printf("Reader not found.\n\n");
                    break;
                case 7:
                    n=0;
                    for( i=0; i<20; i++){
                            if(bk[i].id != 0){
                                n++;
                    }
                    }
                    printf("\n\t\tBook list\tTotal books:%d\n\nID\tName\t\t\tAuthor\t\t\tAvailable\tReader ID\n\n", n);
                    for( i=0; i<20; i++){
                            if(bk[i].id != 0){
                                printf("%d\t%s\t\t%s\t\t%c\t\t%d\n", bk[i].id, bk[i].name,
                                       bk[i].author, bk[i].avbl, bk[i].rid);
                    }
                    }
                    break;
                case 8:
                    printf("......THANK YOU......\n");
                    break;
                default:
                    printf("INVALID CHOICE!!!PLEASE ENTER A NUMBER BETWEEN 1-8.");
                    }
        }while(choice_admin!=8);
    break;
    case 3:
          printf("THANK YOU");
          exit(0);
          break;
    default:
        printf("INVALID CHOICE!!!!PLEASE ENTER 1 OR 2");
    }
    }

}



