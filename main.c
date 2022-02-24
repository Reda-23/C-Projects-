#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Minute 31

//functions for the bills 
void generateBillHeader (char name[50],char date [30]){
     printf("\n \n");
     printf("\t  =====Café BRINI=====");
     printf("\n----------------------------------------");
     printf("\nDate:%s",date);
     printf("\nInvoiceTo : %s",name);
     printf("\n");
     printf("----------------------------------------\n");
     printf("Items\t\t");
     printf("Quantity\t");
     printf("Total:\t\t");
     printf("\n----------------------------------------");
     printf("\n\n");
}
void generateBillBody(char items[30],int qty,float price ){
     printf("%s\t\t",items);
     printf("%d\t\t",qty);
     printf("%.2f\t\t",qty*price);
     printf("\n");
}
struct items{
     char items [20];
     float price;
     int qty;
};
struct orders{
     char customers[50];
     char date[50];
     int numofitemss;
     struct items itm [50];
      
};
void generateBillFooter (float total){
     printf("\n");
     float dis = 0.1*total;
     float nesTotal = total - dis;
     float cgst = 0.09 * nesTotal,grandTotal =nesTotal + 2*cgst;//net Total + cgst*sgst  
     printf("----------------------------------------\n");
     printf("Sub Total \t\t\t%.2f",total);
     printf("\nDiscount @10 %s\t\t\t%.2f","%",dis);
     printf("\n--------");
     printf("\nNet Total\t\t\t%.2f",nesTotal);
     printf("\nCGST @9 %s\t\t\t%.2f","%",cgst);
     printf("\nSCGT @9%s\t\t\t%.2f","%",cgst);
     printf("\n----------------------------------------");
     printf("\nGrand Total\t\t\t%.2f",grandTotal);
     printf("\n----------------------------------------");
     }

     int main(){
          float total;
          int opt,n;
          struct orders ord;
          struct orders order;
          char saveBill = 'y',contFlag = 'y';
          char name[50];
          FILE *fp;
          
          //dashboard
          while (contFlag = 'y') {
               float total = 0;
               int  invoiceFound = 0;
          printf("\t =====Café BRINI=====");
          printf("\n\nPlease Select Your Prefered Operation");
          printf("\n1.Generate Invoice");
          printf("\n2.Show all Invoices");
          printf("\n3.Search Invoices ");
          printf("\n4.Exit");

          printf("\n\n Your Choice:\t");
          scanf("%d",&opt);

     fgetc(stdin);
     switch (opt){
     case 1:
     system("clear");
     printf("\nPlease enter the name of the Waiter\t");
     fgets(ord.customers,50,stdin);
     ord.customers[strlen(ord.customers)-1]=0;
     strcpy(ord.date,__DATE__);
     printf("\nPlease Enter The Number Of Items\t");
     scanf("%d",&n); 
     ord.numofitemss = n;
     for (int i = 0; i < n; i++) {
          fgetc(stdin);
          printf("\n\n");
          printf("Please enter the Item %d :\t",i+1);
          fgets(ord.itm[i].items,20,stdin);
          ord.itm[i].items[strlen(ord.itm[i].items)-1]=0;
          printf("\nPlease enter the quantity : \t");
          scanf("%d",&ord.itm[i].qty);
          printf("Please enter the unit price:\t");
          scanf("%f",&ord.itm[i].price);
          total += ord.itm[i].qty * ord.itm[i].price;
     }


     generateBillHeader(ord.customers,ord.date);
     for (int i = 0; i < ord.numofitemss; i++)
     {
          generateBillBody(ord.itm[i].items,ord.itm[i].qty,ord.itm[i].price);

     }
     generateBillFooter(total);
     
     printf("\n Do you want to save the invoice: [y/n] ?\t");
     scanf("%s",&saveBill);
     if (saveBill = 'y')
     {
          fp = fopen("RestaurentBill.dat","a+") ;
          fwrite(&ord,sizeof(struct orders),1,fp);
          if (fwrite != 0)
          printf("\nSuccessfuly saved");
          else 
          printf("\nError Saving");
          fclose(fp);
     }
     break;
     case 2:
     system("clear");
     fp = fopen ("ResteurantBill.dat","r");
     printf("\n*****Your Previous Invoice*****\n");
     while (fread(&order,sizeof(struct orders),1,fp)){
          float tot = 0;
          generateBillHeader(order.customers,order.date);
          for (int  i = 0; i < order.numofitemss ; i++){
               generateBillBody(order.itm[i].items,order.itm[i].qty,order.itm[i].price);
               tot += order.itm[i].qty * order.itm[i].price;
          }
               generateBillFooter(tot);
          
     }
     fclose(fp);
     break;
     case 3:
     printf("\n Enter the name of the customer:\t");
     //fgetc(stdin);
     fgets(name,50,stdin);
     name[strlen(name)-1] = 0;
     system("clear");
     fp = fopen ("ResteurantBill.dat","r");
     printf("\t*****Invoice Of %s*****",name);
     while (fread(&order,sizeof(struct orders),1,fp)){
          float total = 0;
          if (!strcmp(order.customers,name)){
                generateBillHeader(order.customers,order.date);
          for (int  i = 0; i < order.numofitemss ; i++)
          {
               generateBillBody(order.itm[i].items,order.itm[i].qty,order.itm[i].price);
               total += order.itm[i].qty * order.itm[i].price;
          }
               generateBillFooter(total);
               invoiceFound = 1;

          }
    
          
     }
     if (!invoiceFound)
     {
          printf("Sorry the inpust for %s does not exists",name);
     }
     
     fclose(fp);
     break;

     case 4:
     printf("\n\t\t Goodbye \n\n");
     exit (0);
     break;

     default:
     printf("Invalid Option");
     break;
 }
     printf("\nDo you want to perform another operation? [y/n]");
     scanf("%s",&contFlag);
       }
          printf("\n\n");

     
     
     return 0;
     }


