#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int num = 0;

struct note
{
    char file_name[40];
    struct note *next;
}*head = NULL;


void choice()
{
    int n;
    printf("\n1 For Add A New Note\n2 For Display A Note\n3 For Edit A Note\n4 For Delete A Note\n5 For Search A Note\n6 For Show All Notes\n7 For Change Color\n8 For Exit.\n");

    printf("\nEnter Your Choice :");
    scanf("%d", &n);

    switch(n)
    {
    case 1:
        create();
        break;
    case 2:
        display();
        break;
    case 3:
        rewrite();
        break;
    case 4:
        delete1();
        break;
    case 5:
        search();
        break;
    case 6:
        listt();
        break;
    case 7:
        color_code();
        break;
    case 8:
        break;

    default:
    {
        system("cls");
        printf("\nWrong Choice!!!\n\n");
        system("pause");
        system("cls");
        choice();

    }
    }

}
void create()
{
    FILE *fp, *f;
    int i,a,b,n,p;
    char th[1000], ex[5] = ".txt";
    struct note *new_node, *current;
    p = 0;
    system("cls");
    do
    {
        new_node = (struct note*)malloc(sizeof(struct note));

        printf("Enter title name : ");
        scanf(" %[^\n]", new_node->file_name);
        strcat(new_node->file_name,ex);

        new_node->next = NULL;

        if(head == NULL)
        {
            num++;
            head = new_node;
            current = new_node;
        }
        else
        {
            num++;
            current->next = new_node;
            current = new_node;
        }

        f = fopen(new_node->file_name, "r");
        if(f==NULL)
        {
            p = 1;
        }
        fclose(f);
        if(p==1)
        {
            fp = fopen(new_node->file_name, "w");
            printf("Write your creative thought : ");
            getchar();
            fprintf(fp, gets(th));
            fclose(fp);
            printf("\nCongratulation your note is successfully saved\n\n");

        system("pause");

        printf("\nDo You Want To Add Another Note?\n1 for Yes\n2 for No\n");
        scanf("%d",&n);

        }
        else
    {
        printf("Oops !! You have already a file with this name :-) ");
        printf("\n\n");
        system("pause");
    }

    }
    while(n==1);

    system("cls");
    choice();

}


void display()
{
    FILE *fp;
    struct note *current;
    char ch, name[20], ex[5] = ".txt";
    int n,i, count = 0;

    system("cls");

    current = head;
    if(num>=1)
    {
        if(num>=1)
        {
            printf("\nMy note : \n");
            while(current!=NULL)
            {
                count++;
                printf("%d. %s\n",count,current->file_name);
                current = current->next;
            }
        }
    }
    else
    {
        printf("You have no file here\n");
        system("pause");
        system("cls");
        choice();

    }

    printf("Select a note : ");
    scanf("%d",&n);

    current = head;
    for(i=1; i<n; i++)
    {
        current = current->next;
    }

    fp = fopen(current->file_name, "r");
    while(1)
    {
        ch = fgetc(fp);
        if(ch==EOF)
        {
            break;
        }
        putchar(ch);
    }
    fclose(fp);
    printf("\n");
    system("pause");
    system("cls");
    choice();

}


void delete1()
{
    FILE *fp;
    struct note *add, *current, *temp,*temp1;
    char ch[40],ex[] = ".txt" ;
    int n = 0, pos,i, a,b, count = 0;

    system("cls");
    while(1)
    {

        int x = 0;
        current = head;
        if(num>=1)
        {
            printf("\nMy note : \n");
            while(current!=NULL)
            {
                count++;
                printf("%d. %s\n",count,current->file_name);
                current = current->next;
            }
        }
        else
        {
            printf("You have no file here\n");
            break;
        }
        printf("Select one for delete : ");
        scanf("%d", &a);

        current = head;
        for(i=1; i<a; i++)
        {
            current = current->next;
        }

        if(current == head)
        {
            strcpy(ch, current->file_name);
            remove(current->file_name);
            num--;
            head = current->next;
            printf("%s note is deleted successfully\n", ch);
            break;
        }
        else if(current->next == NULL)
        {
            strcpy(ch, current->file_name);
            remove(current->file_name);
            num--;
            current = head;
            for(i=1; i<=a-2; i++)
            {
                current = current->next;
            }

            current->next = NULL;

            printf("%s note is deleted successfully\n", ch);
            break;
        }
        else
        {
            num--;
            strcpy(ch, current->file_name);
            remove(current->file_name);
            temp = current->next;

            current = head;
            for(i=1; i<=a-2; i++)
            {
                current = current->next;
            }

            current->next = temp;


            printf("%s note is deleted successfully\n", ch);
            break;
        }

    }
    system("pause");
    system("cls");
    choice();
}
void rewrite()
{
    FILE *f,*p;
    struct note *current;
    char ch[40], w[1000],n[5] = ".txt",h;
    int a,c,b,i;

    system("cls");
    int count = 0;

    system("cls");
    current = head;
    if(num>=1)
    {
        printf("\nMy note : \n");
        while(current!=NULL)
        {
            count++;
            printf("%d. %s\n",count,current->file_name);
            current = current->next;
        }
    }
    else
    {
        printf("You have no file here\n");
    }
    printf("\n");
    printf("Select a note : ");
    scanf("%d", &b);

    current = head;
    for(i=1; i<b; i++)
    {
        current = current->next;
    }

    p = fopen(current->file_name, "r");

    printf("\n");
    while(1)
    {
        h = fgetc(p);
        if(h==EOF)
        {
            break;
        }
        putchar(h);
    }
    fclose(p);
    f = fopen(current->file_name, "a");
    getchar();
    fprintf(f, gets(w));
    fclose(f);

    printf("\n");
    printf("Note Is Succesfully Edited\n\n");
    system("pause");
    system("cls");
    choice();

}

void listt()
{
    struct note *current;
    int count = 0;

    system("cls");
    current = head;
    if(num>=1)
    {
        printf("\nMy note : \n");
        while(current!=NULL)
        {
            count++;
            printf("%d. %s\n",count,current->file_name);
            current = current->next;
        }
    }
    else
    {
        printf("You have no file here\n");
    }
    printf("\n");
    system("pause");
    system("cls");
    choice();

}

void search()
{
    FILE *fp,*p;
    struct note *current, *temp;
    char name[20],ex[5] = ".txt", ch,h,w[1000],dup[50];
    int a,b,pos = 0,n = 0,i;

    system("cls");
    printf("Insert a name wanna search : ");
    scanf(" %[^\n]", name);
    strcat(name,ex);

    current = head;
    while(current != NULL)
    {
        pos++;
        if(strcmp(current->file_name, name)==0)
        {
            n++;
            printf("\n%s is in the list at %d Position\n\n", current->file_name,pos);
            printf("What do you want to this file ?\n");
            printf("Press :\n1 to delete\n2 to display\n3 to rewrite\n");
            scanf("%d", &a);
            if(a==1)
            {
                if(current == head)
                {
                    strcpy(dup, current->file_name);
                    remove(current->file_name);
                    num--;
                    head = current->next;
                    printf("%s note is deleted successfully\n", dup);
                    break;
                }
                else if(current->next == NULL)
                {
                    strcpy(dup, current->file_name);
                    remove(current->file_name);
                    num--;
                    current = head;
                    for(i=1; i<=pos-2; i++)
                    {
                        current = current->next;
                    }

                    current->next = NULL;

                    printf("%s note is deleted successfully\n", dup);
                    break;
                }
                else
                {
                    num--;
                    strcpy(dup, current->file_name);
                    remove(current->file_name);
                    temp = current->next;

                    current = head;
                    for(i=1; i<=pos-2; i++)
                    {
                        current = current->next;
                    }

                    current->next = temp;


                    printf("%s note is deleted successfully\n", dup);
                    break;
                }
            }
            else if(a==2)
            {
                printf("\n");
                fp = fopen(name, "r");
                while(1)
                {
                    ch = fgetc(fp);
                    if(ch==EOF)
                    {
                        break;
                    }
                    putchar(ch);
                }
                fclose(fp);
                printf("\n");
            }
            else if(a==3)
            {
                p = fopen(current->file_name, "r");

                printf("\n");
                while(1)
                {
                    h = fgetc(p);
                    if(h==EOF)
                    {
                        break;
                    }
                    putchar(h);
                }
                fclose(p);
                fp = fopen(current->file_name, "a");
                getchar();
                fprintf(fp, gets(w));
                fclose(fp);
                printf("\nEdit successful\n");

            }
        }
        current = current->next;
    }

    if(n == 0)
        printf("Sorry , You have no file of this name\n");
    printf("\n");
    system("pause");
    system("cls");
    choice();
}

void color_code()
{
    system("cls");
    printf("\n    0 = Black       8 = Gray\n\
    1 = Blue        9 = Light Blue\n\
    2 = Green       A = Light Green\n\
    3 = Aqua        B = Light Aqua\n\
    4 = Red         C = Light Red\n\
    5 = Purple      D = Light Purple\n\
    6 = Yellow      E = Light Yellow\n\
    7 = White       F = Bright White\n ");

    char code[15] = "COLOR ";

    printf("\nEnter Color Code For Background : ");
    fflush(stdin);
    scanf("%c",&code[6]);
    printf("Enter Color Code For Text : ");
    fflush(stdin);
    scanf("%c",&code[7]);
    if(code[6]==code[7])
    {
        printf("Code Can't Be Same -_-\n");
        system("pause");
        system("cls");
        color_code();
    }
    else
    {
        system(code);
        system("cls");
        choice();
    }
}

int main()
{
    printf("----------------- Welcome <3 ------------------------\n        We Are Happy To See You Here\n           Powered By SEMICOLON\n");
    printf("-----------------------------------------------------\n\n\n       ");
    system("pause");
    system("cls");
    choice();

    return 0;

}
