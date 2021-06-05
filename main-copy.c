#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include "funcname.h"


int main() 
{ 
  patient *root = NULL; 
  root = load(root);
  int ch,patientID,key,dkey;
  patient *temp=NULL;
  patient *new=NULL;
  system("cls");
  while(1)
  {
      printf("\nEnter 1 to Display list of all the patients:\t");
      printf("\nEnter 2 to Add a patient record to database:\t");
      printf("\nEnter 3 to Find patient:\t");
      printf("\nEnter 4 to Delete a patient record from database:\t");
      printf("\nEnter 5 to Print the tree:\t");
      printf("\nEnter 6 to Add records from the tree to a new file in ascending order:\t");
      printf("\nEnter 7 to Exit:\t");
      printf("\n Enter your Choice \n");
      scanf("%d",&ch);
      switch(ch)
      {
        case 1:
        if(root==NULL)
                printf("\nDatabase Empty!");
            displayAll(root);
            clr();
            break;
        case 2:
            while(1)
            {
                printf("\nEnter PatientID:\t");
                scanf("%d",&patientID);
                temp=search(root,patientID);
                if(temp==NULL)
                {
                    root=insert(root,patientID);
                    printf("\nPatient added\n");
                    break;
                }
                printf("\nID already exists!");
                printf("\nPlease insert valid ID\n");
            }
            printf("\nPress Enter to continue\n");
	        getchar();
	        system("cls");
            break;
        case 3:
            printf("\nEnter ID of patient to be searched:\t");
            scanf("%d",&key);
            temp=search(root,key);
            displayNode(temp);
            clr();
            break;
        case 4:
            printf("\nEnter ID of patient to be removed from database:\t");
            scanf("%d",&dkey);
            temp=search(root,dkey);
            if(temp==NULL)
                printf("\nRecord doesnt exist!");
            else
            {
                root=del(root,dkey);
                printf("\nPatient with ID %d removed\n",dkey);
                deletefile(dkey);
                new=load(new);
                root=new;
            }
            clr();
            break;
        case 5:
            printf("\n");
            print2DUtil(root,0);
            clr();
            break;
        case 6:
            export(root);
            printf("\nNodes added to Sorted_Records.txt in ascending order!!!\n");
            clr();
            break;
        case 7:
            exit(0);
        default:
            printf("\nPlease Enter valid Input!!!");
            clr();
     }               
  }
    return 0; 
} 


