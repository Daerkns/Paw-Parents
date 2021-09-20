#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>

void choice();
void achoice();
void fileloader();
///Logic Functions, admin

/// Update & Insert Function,
void insertfirst(int data, char productname[25], int quantity, float price);
void insertmid(int pos, int data, char productname[25], int quantity, float price);
void insertend(int data, char productname[25], int quantity, float price);
void updateproduct(int udata, int uquantity);

/// Display Function
void item_list();
void order_view(int order, int quantity, int or_no);
void main_menu();

///Delete & Count Function
void deleteproduct(int serial);
int countitem();

///extra design Function for printing in particular places
void cls();
void echo(char print[]);
void linebreak(int line);
void pre(int tab);
void gap(void);
void backuploader(void);

struct Node
{
    char productname[50];
    int quantity;
    float price;
    int data;
    struct Node *next;
};

typedef struct Node node ;
node *head, *list;

struct cust
{
    char name[50];
    char address[100];
    char phone[11];
    int money;
    char item[100];
    int quantity;
};
struct cust ct;

char item[100];
int quantity;
char item[100];
int c=0;
int any;
int cardno[100];
float cardmoney[100];
float totalmoney = 0;
int total_order[100];
int order_quantity[100];
int order=0;
int uquantity;
int citem;

int main()//RAOMI & NASIHA
{
    system("PAW PARENTS");
	fileloader();
    cls();
    Sleep(300);
    cls();
	int get_product_choice;
	int cho;
    head = NULL;

	linebreak(1);
    main_menu();

    FILE *sale;
    sale=fopen("sales.txt", "a+");
	printf("\t\tTo buy things press 1\n\t\tTo exit press 0     ");
	fflush(stdin);
	scanf("%d", &cho);
	if(cho==0)
	{
		main();
	}
	else
	{
		goto sell;
	}
sell:
    printf("\t\t\n<<Enter details to order your item>>\n\n\n");

    printf("\n\t\tName: ");
    scanf("%s", ct.name);
    printf("\n\t\tAddress: ");
    scanf("%s", ct.address);
    printf("\n\t\tPhone: ");
    scanf("%s", ct.phone);

    linebreak(2);
    pre(2);
    fflush(stdin);
    printf("Place Your Order: ") ;
    scanf("%d", &get_product_choice);

    if(get_product_choice==0)
    {
        main_menu();
    }

    node *temp;
    temp = list ;

    while(temp->data != get_product_choice)
    {
        temp = temp->next;
        if(temp==NULL)
        {
            linebreak(2);
            pre(3);
            echo("Please Choose From List: ");
            linebreak(2);
            Sleep(1000);
            item_list();
        }
    }
    if(get_product_choice == temp->data)
    {
        strcpy(ct.item, temp->productname);
        linebreak(2);
        pre(2);
        printf("Enter Item Quantity : ");

        int fcquantity;

        fflush(stdin);
        scanf("%d",&fcquantity);
        ct.quantity=fcquantity;
        cls();

        if(fcquantity==0)
        {
            cls();
            gap();
            pre(3);
            printf("Quantity Can not be Zero ");
            Sleep(2000);
            cls();
            item_list();
        }
        else if(fcquantity>temp->quantity)
        {
            cls();
            gap();
            pre(3);
            printf("Out of Stock ! ");
            Sleep(2000);

            item_list();
        }
        gap();
        pre(4);
        ct.money=temp->price*fcquantity;

        printf("Choose item:%s  price: %0.2f \n\n",temp->productname,temp->price*fcquantity);
        pre(4);
        printf("1. Confirm to purchase product: \n\n");
        pre(4);
        printf("2. Item List \n\n");
        printf("Press 1 to confirm and 2 to go back to list :");

confirm:
		;
        int confirm;

        fflush(stdin);
        scanf("%d",&confirm);

        if(confirm == 1 )
        {
            linebreak(2);
            pre(4);
            printf(" 1. Cash ");
            linebreak(2);
            pre(4);
            printf(" 2. Credit\n");
            printf("Select Method Of payment 1-2: ");
payment:
            ;
            int payment;

            fflush(stdin);
            scanf("%d",&payment);

            if(payment==1)
            {
                totalmoney += temp->price*fcquantity;
                order++;
                total_order[order]=get_product_choice;
                order_quantity[order]=fcquantity;
                uquantity = temp->quantity - fcquantity;

                updateproduct(get_product_choice,uquantity);

                cls();
                gap();
                pre(4);
                printf("----->THANK YOU<-----");
                linebreak(2);
                pre(4);
                printf("Item Ordered Successfully ...");
                linebreak(2);
                pre(4);
                printf("1. Wanna Buy Another Item? ");
                linebreak(2);
                pre(4);
                printf("2. Main Menu \n");
                linebreak(2);
                pre(4);
                printf("Select: ");
psmenu:
                ;
                int ps_menu;

                fflush(stdin);
                scanf("%d",&ps_menu);

                if(ps_menu==1)
                {
                    fprintf(sale, "%s %s %s %s %d %d\n", ct.name, ct.address, ct.phone, ct.item, ct.money, ct.quantity);
                    fclose(sale);
                    main();
                }
                else if(ps_menu==2)
                {
                    fprintf(sale, "%s %s %s %s %d %d\n", ct.name, ct.address, ct.phone, ct.item, ct.money, ct.quantity);
                    fclose(sale);
                    main_menu();
                }
                else
                {
                    linebreak(2);
                    pre(4);
                    printf("Please Choose from list : ");
                    goto psmenu;
                }
            }
            ///Credit Card Option
            else if(payment==2)
            {
                int card_number[100];

                c++;

                cls();
                gap();
                pre(4);
                printf("Enter Your Card No : ");

                fflush(stdin);
                scanf("%d",&card_number[c]);

                cardno[c] = card_number[c];

                int pin;

                linebreak(2);
                pre(2);
                printf("Enter Your Card Pin [we never save your pin]  : ");

                fflush(stdin);
                scanf("%d",&pin);

                cardmoney[c] = temp->price*fcquantity;

                totalmoney += temp->price*fcquantity;
                order++;
                total_order[order]=get_product_choice;
                order_quantity[order]=fcquantity;

                uquantity = temp->quantity - fcquantity;

                updateproduct(get_product_choice,uquantity);

                linebreak(2);
                pre(4);
                printf("Payment Success...");

                linebreak(2);
                pre(4);
                printf("1. Buy another Product ");
                linebreak(2);
                pre(4);
                printf("2. Main Menu \n");
                linebreak(2);
                pre(4);
                printf("select: ");
psmenu2:
                ;
                int ps_menu2;

                scanf("%d",&ps_menu2);

                if(ps_menu2==1)
                {
                    fprintf(sale, "%s %s %s %s %d %d\n", ct.name, ct.address, ct.phone, ct.item, ct.money, ct.quantity);
                    fclose(sale);
                    main();
                }
                else if(ps_menu2==2)
                {
                    fprintf(sale, "%s %s %s %s %d %d\n", ct.name, ct.address, ct.phone, ct.item, ct.money, ct.quantity);
                    fclose(sale);
                    main();
                }
                else
                {
                    linebreak(2);
                    pre(4);
                    printf("Please Choose from list : ");
                    goto psmenu2;
                }
            }
            else
            {
                linebreak(2);
                pre(4);
                printf("Enter Choose from List : ");
                goto payment;
            }
        }    ///END Confirm Y/y
        else if(confirm == 2)
        {
            fprintf(sale, "%s %s %s %s %d %d\n", ct.name, ct.address, ct.phone, ct.item, ct.money, ct.quantity);
            fclose(sale);
            main_menu();
        }
        else
        {
            linebreak(2);
            pre(4);
            printf("Enter Choise from List : ");
            goto confirm;
        }  ///end confirm;
    }  ///end get product choice if line
    else
    {
        linebreak(2);
        pre(4);
        echo("Please Choose From List ");
        linebreak(2);
        Sleep(300);
        item_list();
    }  ///end get product choice
}

void fileloader()//Ehasan
{
	int serial, qntt; float prc; char itm[25];
	FILE *admin;
	admin = fopen("item.txt", "r+");
    while(fscanf(admin, "%d %s %f %d", &serial, itm, &prc, &qntt)!=EOF)
    {
    	if(serial==1)
    	{
    		insertfirst(serial, itm, qntt, prc);
		}
		else
		{
			insertend(serial, itm, qntt, prc);
		}
	}
}

void cls()
{
    system("cls");
}

void echo(char print[])
{
    printf("%s",print);
}

void linebreak(int line)
{
    for(int i=0; i<line; i++)
    {
        printf("\n");
    }
}

void pre(int tab)
{
    for(int i=0; i<tab; i++)
    {
        printf("\t");
    }
}

void main_menu()
{
    cls();
    linebreak(5);
    pre(3);
    echo("1.Buy Item");
    linebreak(2);
    pre(3);
    echo("2.Admin Panel");
    linebreak(2);
    pre(3);
    echo("3.Exit");

    linebreak(1);

    int main_menu_choice;

    linebreak(1);
    pre(4);
    fflush(stdin);
    scanf("%d",&main_menu_choice);
    choice(main_menu_choice);
}

void insertend(int data, char productname[25], int quantity, float price)//EHASAN
{
    node *temp;

    temp=(node *)malloc(sizeof(node));

    temp->data = data;

    temp->price = price;

    temp-> quantity = quantity;

    strcpy(temp->productname,productname);

    temp->next = NULL;

    if(head==NULL)
    {
        head = temp;
        list = head;
    }
    else
    {
        while(head->next != NULL)
        {
            head = head->next;
        }
        head->next = temp;
    }
}

void insertfirst(int data, char productname[25], int quantity, float price)//SOUVIK
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->data = data ;
    temp->price = price;
    strcpy(temp->productname,productname);
    temp-> quantity = quantity;
    temp->next = head;
    head = temp;
    list = head ;
}

void deleteproduct(int serial)//RAOMI
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp = list;

    if(temp->data != serial)
    {
        while(temp->next->data != serial)
        {
            temp = temp->next;
        }
        if(temp->next->data == serial)
        {
            temp->next = temp->next->next;
            cls();
            printf("\n\n\n\n\t\t\tDeleting Item %d ",serial);
            for(int cs=0; cs<4; cs++)
            {
                printf(" .");
                Sleep(400);
            }
            printf("\n\n\n\n\t\t\tDeleted Successfylly \n");
            getch();
        }
        else
        {
            printf("\n\n\n\n\t\t\ Item Not Found\n");
            getch();
        }
        head = temp ;
    }
    else
    {
        temp = temp->next;
        cls();
        printf("\n\n\n\n\t\t\tDeleting Item %d ",serial);
        for(int cs=0; cs<4; cs++)
        {
            printf(" .");
            Sleep(400);
        }
        printf("\n\n\n\n\t\t\tDeleted Successfylly \n");
        Sleep(500);
        head = temp ;
        list=head;
    }
}

void updateproduct(int udata, int uquantity)//NASIHA
{
    node *temp;
    temp = list;

    while(temp->data!=udata)
    {
        temp = temp->next;
    }
    if(temp->data == udata)
    {
        temp->quantity = uquantity;
    }
}

int countitem()//EHASAN
{
    node *temp;

    temp = list;

    int countitem=0;

    if(temp==NULL)
    {
        countitem = 0;
    }
    else
    {
        countitem = 1;
        while(temp->next != NULL)
        {
            countitem++;
            temp = temp->next;
        }
    }
    return countitem;
}

void item_list()//RAOMI
{
    cls();
    printf("press .0. Main Menu ");
    linebreak(4);
	int quan, dat;
	float pri;
	char itemnm[40];
    node *temp;
    temp = list;

	while(temp != NULL)
    {
    	pre(1);
        printf("serial: %d",temp->data);
        pre(2);
        printf("Item: %s", temp->productname);
        pre(2);
        printf("Price: %0.2f",temp->price);
        pre(2);
        printf("Quantity: %d",temp->quantity);
        linebreak(3);
        temp = temp->next ;
    }
}

void order_view(int order, int quantity, int or_no)//SOUVIK
{
    node *temp;

    temp = list;

    while(temp->data != order)
    {
        temp = temp->next;
    }
    if(temp->data == order)
    {
    	pre(1);
        printf("serial: %d",or_no);
        pre(2);
        printf("Item: %s", temp->productname);
        pre(2);
        printf("Price: %0.2f",temp->price);
        pre(2);
        printf("Quantity: %d",temp->quantity);
        linebreak(3);
        Sleep(100);
    }
}

void backuploader(void)//EHASAN
{
    for (int i=15; i<=100; i+=5)
    {
        cls();
        printf("\n\n\n\n\n\n\n\t\t\t\t");
        printf("%d %% Backing UP DATA...\n\n\t\t",i);
        printf("");
        for (int j=0; j<i; j+=2)
        {
            printf(" ");
        }
        Sleep(50);
        if(i==90 || i==50 || i==96 || i==83)
        {
            Sleep(50);
        }
    }
}

void gap(void)
{
    printf("\n\n\n\n\n\n\n");
}

void choice(int ch)//NASIHA
{
    if((ch >=1 && ch <=3))
    {
        if(ch == 1)
        {
            item_list();
        }
        else if( ch == 2)
        {
            achoice();
        }
        else if(ch==3)
        {
            cls();
            gap();
            pre(3);
            printf("Thank You For Using Our System. \n\t\t\tPresented To You By TEAM PAW PARENTS\n\n\n\n\n\n\n");
            Sleep(1000);
            exit(1);
        }
    }
    else
    {
        linebreak(2);
        pre(4);
        printf("Please Enter Correct Choice");
        Sleep(300);
        main_menu();
    }
}

void achoice()//EHASAN & SOUVIK
{
adminpanelchoice:
    ;
    int password;

    cls();
    gap() ;
    pre(4);
    printf("1. Main Menu\n\n\t");
    Sleep(300);
    printf("\t\t\tEnter Admin password: ");

    fflush(stdin);
    scanf("%d", &password);

    if(password==1302)
    {
        node *temp;
        temp = list;
adminchoice:
        cls();
        linebreak(3);
        pre(4);
        echo("..........Admin Panel..........   \n\n");
        pre(4);
        printf(" 1. Total Cash Today \n\n");
        pre(4);
        printf(" 2. View Card Pay \n\n");
        pre(4);
        printf(" 3. Add Item \n\n");
        pre(4);
        printf(" 4. Delete Item \n\n");
        pre(4);
        printf(" 5. search item \n\n");
        pre(4);
        printf(" 6. Item Counter \n\n");
        pre(4);
        printf(" 7. Backup System\n\n");
        pre(4);
        printf(" 8. Instant Order Preview\n\n");
        pre(4);
        printf(" 9. Show all transactions\n\n");
        pre(4);
        printf(" 10. Update Stock\n\n");
        pre(4);
        printf(" 0. Main Menu \n\n");
        printf("Enter Your From 1-0: ");

        int adminchoice;

        fflush(stdin);
        scanf("%d",&adminchoice);

        if(adminchoice==1)//souvik
        {
            cls();
            gap();
            pre(4);
            printf("Todays Total Cash : %0.2f  \n",totalmoney);

            Sleep(2000);

            goto adminchoice;
        }
        else if(adminchoice==2)//souvik
        {
            if(c!=0)
            {
                cls();
                linebreak(3);
                pre(4);

                printf(" ____________________________\n");
                pre(4);
                printf("|   Card NO.   |   Money $   |\n");
                pre(4);
                printf("------------------------------\n");
                pre(4);

                for(int z=1; z<=c; z++)
                {
                    printf("|  %d  | %0.2f |\n",cardno[z],cardmoney[z]);
                    pre(4);
                    printf("------------------------------\n");
                    pre(4);
                    Sleep(150);
                }
                Sleep(1500);
            }
            if(c==0)
            {
                cls();
                gap();
                pre(4);
                printf("No Card History\n");
            }
            Sleep(1500);
            goto adminchoice;
        }
        else if(adminchoice==3)//souvik
        {
productadd:
            cls();
			FILE *admin;
			admin=fopen("item.txt", "a");

            char fproductname[25];
            int fquantity;
            int fdata;
            float fprice;
            int fposi;

            linebreak(3);
            pre(4);
            printf(" Enter Item Name :  ");

            fflush(stdin);
            scanf("%s",fproductname);
fquantity:
            fflush(stdin);

            linebreak(2);
            pre(4);
            printf(" Enter Item Quantity :  ");

            scanf("%d",&fquantity);
            fflush(stdin);
productserial:
            linebreak(2);
            pre(4);
            printf(" Enter Item Serial :  ");
            scanf("%d",&fdata);
fprice:
            fflush(stdin);

            linebreak(2);
            pre(4);
            printf(" Enter Item Price :  ");
            fflush(stdin);

            scanf("%f", &fprice);

            linebreak(2);
            pre(4);
            printf("Submiting your data");
            for(int cs=0; cs<4; cs++)
            {
                printf(" .");
                Sleep(500);
            }
			fprintf(admin, "%d %s %.2f %d\n", fdata, fproductname, fprice, fquantity);
			fclose(admin);

            linebreak(2);
            pre(4);
            printf("Adding Item  Successfull....\n");

            Sleep(2000);

            goto adminchoice;
        }
        else if(adminchoice==4)//ehsan
        {
            cls();
            gap();
            pre(2);
            printf("Enter Serial No of the Item To Delete : ");
fdelete:
            ;
            int fdelete;
            fflush(stdin);
            scanf("%d",&fdelete);
            node *temp;
            temp=list;
            while(temp->data != fdelete)
            {
                temp = temp->next;
            }
            if(temp->data==fdelete)
            {
                deleteproduct(fdelete);
            }
            else
            {
                linebreak(2);
                pre(2);
                printf("Please Enter Correct Number :  ");
                Sleep(500);
                goto fdelete;
            }
            goto adminchoice;
        }
 		else if(adminchoice==5)//ehsan
 		{
 			system("cls");
 			int search, qtt;
 			printf("\n\n\t\tsearch item(insert serial number): ");
 			fflush(stdin);
 			scanf("%d", &search);
 		    node *temp;
            temp=list;
 			while(temp!=NULL)
 			{
 				if(temp->data==search)
 				{
 				printf("\n\n\n\n\t\tserial: %d", temp->data);
 				printf("\n\n\t\tItem: %s", temp->productname);
 				printf("\n\n\t\tprice: %0.2f", temp->price);
 				printf("\n\n\t\tqunatity: %d", temp->quantity);
 				getch();
 				goto adminchoice;
				}
			temp=temp->next;
			}
		}
        else if(adminchoice==6)//souvik
        {
            citem = countitem();
            cls();
            for(int cs=1; cs<=citem; cs++)
            {
                gap();
                pre(4);
                printf("Item Counting ");
                printf(" %d ",cs);
                Sleep(50);
                cls();
            }
            cls();
            gap();
            pre(4);
            printf("Total Item variety is:  %d  \n",citem);
            Sleep(2000);
            goto adminchoice;
        }
        ///Backup System
        else if(adminchoice==7)//souvik
        {
            char date[35]=__DATE__;

            strcat(date,".txt");
            FILE *fptr;
            fptr=fopen(date,"w");
            backuploader();
            if(fptr==NULL)
            {
                linebreak(3);
                pre(3);
                printf("Error!");
                Sleep(500);
                goto adminchoice;
            }
            fprintf(fptr,"Total Cash Today : %0.2f\n\n\n",totalmoney);
            fprintf(fptr,"Card No ------- Money \n\n");
            for(int l=1; l<=c; l++)
            {
                fprintf(fptr,"%d ------- %0.2f \n",cardno[l],cardmoney[l]);
            }
            linebreak(2);
            pre(4);
            printf("Backup Successfull...");
            Sleep(1500);

            fclose(fptr);
            goto adminchoice;
        }
        else if(adminchoice==8)//ehsan
        {
            cls();
            linebreak(2);
            pre(2);
            printf("\n\t\t");
            printf("______________________________________________________ ");
            for(int o=1; o<=order; o++)
            {
                order_view(total_order[o],order_quantity[o],o);
            }
            linebreak(2);
            pre(4);
            printf("1. <-- back  \n\n");
            pre(5);

            fflush(stdin);
            scanf("%d",&any);

            goto adminchoice;
        }
        else if(adminchoice==9)//ehsan
        {
            FILE*sale;
            sale=fopen("sales.txt", "r");
            cls();
            linebreak(4);
            while(fscanf(sale, "%s %s %s %s %d %d", ct.name, ct.address, ct.phone, ct.item, &ct.money, &ct.quantity)!=EOF)
            {
                printf("Customer name: %s\naddress: %s\nContact Number: %s\nPurchased item: %s\nBill: %d\nQuantity: %d\n\n\n", ct.name, ct.address, ct.phone, ct.item, ct.money, ct.quantity);
            }
            fclose(sale);
            getch();
            achoice();
        }
        else if(adminchoice==10)//ehsan
        {
        	cls();
        	int srl; int qntt;
        	printf("\n\n\n\t\tEnter serial to update stock:  ");
        	fflush(stdin);
 			scanf("%d", &srl);
 			printf("\n\n\t\t\tEnter amount of stock: ");
 			scanf("%d", &qntt);
 			node *temp;
            temp=list;
 			while(temp!=NULL)
 			{
 				if(temp->data==srl)
 				{
 					qntt=temp->quantity+qntt;
 				}
 			updateproduct(srl,qntt);
 			printf("\n\n\n\t\t\t\tItem updated");
 			getch();
 			goto adminchoice;
 		}
 	}
        else if(adminchoice==0)
        {
            main_menu();
        }
        else
        {
            linebreak(2);
            pre(4);
            printf("Please Select From List :  ");
            Sleep(500);
            goto adminchoice;
        }
    }
    else if(password==1)
    {
        main_menu();
    }
    else
    {
        linebreak(2);
        pre(4);
        printf("Please Enter Correct Choice");
        goto adminpanelchoice;
    }
}
