/*
 * @file 	Bank_program.c
 * @author 	Ali El_bana (alitheboss922@gmail.com)
 * @brief 
 * @version 	0.1
 * @date 	2022-04-17
 * 
 * @copyright 	Copyright (c) 2022
 * 
 */


#include <stdio.h>
#include <cs50.c>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "Bank_config.h"
#include "Bank_interface.h"
#include "Bank_private.h"





int 			accounts_nums  			= Initialized_by_Zero ; // Is a variable for the number of accounts you want to create.

int 			OpenExistingAccount_flag 	= Initialized_by_Zero ; // Is a flag for the open account.

int 			makeTransaction_flag 		= Initialized_by_Zero ; // Is a flag for the correct transfered account bank_ID.

unsigned long long int 	open_bank_ID 			= Initialized_by_Zero ; // Is a variable for open account ID.

unsigned long long int 	transfered_bank_ID 		= Initialized_by_Zero ; // Is a variable for transfered account ID.

int 			open_account_activation 	= Initialized_by_Zero ; // Is a variable for checking the status of the open account.

int 			active_accounts_checking	= Initialized_by_Zero ; // Is a variable for checking the status of the bank accounts.

int			clientWindow_flag		= Initialized_by_Zero ; // Is a flag for the correct client bank_ID and password.
	
unsigned long long int	client_bank_ID			= Initialized_by_Zero ; // Is a variable for scaning the bank account_ID of the client.

unsigned long long int 	client_password			= Initialized_by_Zero ; // Is a variable for scaning the bank account password of the client.

int 			client_MakeTransaction_flag 	= Initialized_by_Zero ; // Is a flag for the correct transfered account bank_ID.

int 			old_Password_flag		= Initialized_by_Zero ; // Is a flag for the correct client account password.

unsigned long long int 	old_AccountPassword 		= Initialized_by_Zero ; // Is a variable for the old account password. 




typedef struct
{
	
	char 			name[ Max_name_chars ]   		;	// Is a string for the name of the client.
	
	string 			address 				;	// Is a string for the address of the client.
	
	char 			account_status[ Max_Status_chars ]	;	// Is a string for the account status of the client(Active,Restricted or Closed).
	
	
	// In case of user is less than 21 he must have a guardian.
	char 			guardian_name[ Max_name_chars ]		;	// Is a string for the guardian name of the client.
	
	unsigned long long int 	guardian_NationalID			;	// Is a variable for the guardian national_ID of the client.


 	unsigned long long int 	national_ID 				;	// Is a variable for the national_ID of the client.
	
	unsigned long long int 	bank_account_ID				;	// Is a variable for the bank_account_ID of the client.
	
	unsigned long long int 	balance 				;	// Is a variable for the balance (money) of the client.
 
	unsigned long long int 	password				;	// Is a variable for a password of the client.
 
	unsigned char 		age        				;	// Is a variable for the age of the client.
	
	
	
}Accounts;





// creating an array of accounts.
Accounts bank_account[ Max_Accounts ] ;






/*****************************************************************************************************************************************/
/****************************************************************************************************************************************/



/*
 * @Function  name 		:	vDisp_mainWindow( ).
 * @Function  info. 	:	Display the main available windows of the Bank system. 
 * @Function  input		:	None.
 * @@Function return	:	None.
 * 
 */
void vDisp_mainWindow( void )
{


    printf("+===========================================================================================+\n")   ;
    printf("|                               Welcome to my \"Bank system\"                                 |\n") ;
    printf("+===========================================================================================+\n")   ;
    printf("| 1 | Admin window                                                                          |\n")   ;
    printf("|---|---------------------------------------------------------------------------------------|\n")   ;
    printf("| 2 | Client window                                                                         |\n")   ;
    printf("|---|---------------------------------------------------------------------------------------|\n")   ;
    printf("| 0 | Exit                                                                                  |\n")   ;
    printf("+===========================================================================================+\n")   ;


}





/*****************************************************************************************************************************************/
/****************************************************************************************************************************************/




/*
 * @Function  name 	:	vAdmin_windowFeatures( ).
 * @Function  info. 	:	Select the features of the Admin window. 
 * @Function  input	:	None.
 * @@Function return	:	None.
 * 
 */
void vAdmin_windowFeatures( void )
{
	
	int select_AdminFeatures = Initialized_by_Zero ; // Is a variable for scaning the feature number.
	
	
	// Making a menu for the Admin features.
	do
	{

		printf("\n\n")																								;
		printf("+===========================================================================================+\n")   ;
		printf("|                                The \"Admin window\"                                         |\n") ;
		printf("+===========================================================================================+\n")   ;
		printf("| 1 | Create bank accounts                                                                  |\n")   ;
		printf("|---|---------------------------------------------------------------------------------------|\n")   ;
		printf("| 2 | Open existing account                                                                 |\n")   ;
		printf("|---|---------------------------------------------------------------------------------------|\n")   ;
		printf("| 0 | Exit                                                                                  |\n")   ;
		printf("+===========================================================================================+\n")   ;
	  
	  
		// To scan the feature number.
		select_AdminFeatures = get_int("\nKindly, select the feature number: ") ;
	  
		
		/* 
		
		 *	To handle entering a number other than the available ones (0,1,2):
		
		 * 	If you enter a number other than (0,1,2) 
			the program will (display Not a choice.try again, please.)
			and will ask you to enter your choice again and repeat that if you enter 
			a not available choice, until you enter one of the available choices then the program 
			will continue.
			
		*/
	  	while ( Default_of_select_AdminFeatures )
		{
			
			printf("\n\nNot a choice.try again, please.\n") ;
			
			// To scan the feature you choose from the Admin window.
			select_AdminFeatures = get_int("\nKindly, select the feature number: ") ; 
			
			
		}
	  
	  
	  
		// Switching on the Admin features choices.
	  	switch( select_AdminFeatures )
		{
			// The choice number 1 is creating bank accounts.
			case Create_BankAccounts  :	vCreate_New_Account( );		break;
			
			// The choice number 2 is opening existing accounts.
			case Open_ExistingAccount :	vOpen_ExistingAccount( );	break;
			
			// The choice number 0 is exiting from the Admin window.
			case Exit_AdminWindow	  : printf("\nYou signed out from the Admin window\n\n") ;
			
		}
	  
	  
	  
	  
	  
		// Do that until the Admin choose to exit from the Admin window.
	}while( select_AdminFeatures != Exit_AdminWindow );
	
	
	
}




/*****************************************************************************************************************************************/
/****************************************************************************************************************************************/




/*
 * @Function  name 	:	vAdminPass_Check3times( int admin_pass ).
 * @Function  info. 	:	Give two more tries to the Admin to enter the correct username and password. 
 * @Function  input	:	The Admin username and Password and the result of the strcmp of the names.
 * @@Function return	:	None.
 * 
 */
void vAdminUsername_and_Pass_Check3times( string admin_name , int admin_pass , int check_admin_name  )
{


	int i = Iteration_start;
	
	
	// If the Admin username or password is not correct.
	if( Incorrect_AdminUsername_or_pass )
	{

		// Give him two more tries to enter the correct Admin username and password.
		for ( i = Iteration_start ; i < Twice ; i ++ )
		{
			
			printf("\n Wrong Admin username or password, Try again\n\n") ;
			
			
			// To scan the Admin username.
			admin_name = get_string(NULL , "\nEnter the Admin username: ") ;
			
			
            // To scan the Admin password.
			admin_pass = get_int("\nEnter the Admin password: ") ;
			
			
			// To check on the admin username (if correct return 0) (else return 1).
			check_admin_name = strcmp( Correct_AdminUsername , admin_name ) ;
			
 
			// During that if he enters the correct Admin username or password break from the iterations and continue the program.
			if ( Correct_AdminUsername_and_pass )
			{	
 
				// Select the features of the Admin window.
				vAdmin_windowFeatures( );
			
			  
				break ;
             
           	}
          
		 
		 
		 
		 
		}
	
	
		// If he enters a wrong Admin username or password for the third time end the program.
		if( Incorrect_AdminUsername_or_pass )
		{
	 
	 
	 
			printf("\nNo more tries\n");
			
			
            
     	    
	    } 
	 
	 
	 
	 
     	
	 
	}
  
    
  
    
  
    
}





/*****************************************************************************************************************************************/
    /*------------------------------------------------- The Admin window functions --------------------------------------------------*/
/****************************************************************************************************************************************/




/*
 * @Function  name 	:	vCreate_New_Account( ).
 * @Function  info. 	:	Create bank_accounts. 
 * @Function  input	:	None.
 * @@Function return	:	None.
 * 
 */
void vCreate_New_Account( void )
{
	
	
	int i 					= Iteration_start	; // Is a variable for the first iteration.

	int j 					= Iteration_start	; // Is a variable for the second iteration.
	
	int national_ID_digits			= Initialized_by_Zero	; // Is a variable for counting the number of digits of the national_ID.
	
	int guardian_national_ID_digits 	= Initialized_by_Zero	; // Is a variable for counting the number of digits of the guardian national_ID.
	
	int name_alphabet			= Initialized_by_Zero	; // Is a counter for the letters in a string.
	
	int name_nums 				= Initialized_by_Zero	; // Is a counter for the numbers in a string.
	
	int name_special_char			= Initialized_by_Zero	; // Is a counter for the special characters in a string.
	
	int spaces_in_name			= Initialized_by_Zero	; // Is a counter for the spaces between every name.
	
	int s					= Initialized_by_Zero	; // Is a counter for the input characters in the name.
	
	
	
	
	printf("\n\n\n/*---------------------------------- Create New Account -----------------------------------*/\n\n");
	
	
	// To scan the number of accounts you want to create.
	accounts_nums = get_int("\nEnter the number of accounts you want to create: "); 
	
	
	
	
	// To fill the information of the accounts.																								
	for ( i = Iteration_start ; i< accounts_nums ; i++ ) 
	{ 	

		national_ID_digits  = Initialized_by_Zero ; // Empty the counter to count the new ID again.
        
        guardian_national_ID_digits = Initialized_by_Zero ; // Empty the counter to count the new ID again.
		
		
		// To print the account number.
		printf("\n\nAdd bank account %d :\n\n ",i+1);	
		
		
		
		//_________________________________________________________________Operations on Client name_________________________________________________________________//
		
		// To scan the name of the client.
		printf("\nEnter the name of the client account: ") ; gets(bank_account[i].name) ;
	
		// Is a function to clear (or flush) the output buffer and move the buffered data to console.
		fflush(stdin) ;
		
		// In case he doesn't enter a full name.
		while( strlen(bank_account[i].name) < Min_name_chars )
		{
			
			printf("\nRejected: You must enter at least first four names ex: Mohamed Salah Hamed Mahrous\n");	
			
			// To scan the name of the client.
			printf("\nEnter the name of the client account: ") ; gets(bank_account[i].name) ;
	
			// Is a function to clear (or flush) the output buffer and move the buffered data to console.
			fflush(stdin) ;
			
		}

		

		// Complete the name scaning process 
		while( bank_account[i].name[s] != Null )
		{
			
			// Counting the letters on the name
			if( BankAccountNameContains_Alphabets )
			{
				
				name_alphabet ++ ;
				
			}
			
			// Counting the numbers on the name
			else if( BankAccountNameContains_Numbers )
			{
				
				name_nums ++ ;
				
			}
			
			// Counting the spaces on the name 
			else if( BankAccountNameContains_Spaces  )
			{
				
				spaces_in_name ++ ;
				
			}
			
			// Counting the special characters on the name
			else
			{
				
				name_special_char ++ ;
				
			}
		 
			s++;
		}
		
	
	
		// In case he doesn't enter a full name
		while( name_alphabet < Min_name_alphabets )
		{
			
			printf("\nRejected: You must enter at least first four names ex: Mohamed Salah Hamed Mahrous\n");	
			
			// To scan the name of the client.
			printf("\nEnter the name of the client account: ") ; gets(bank_account[i].name) ;
			
			// Is a function to clear (or flush) the output buffer and move the buffered data to console.
			fflush(stdin) ;
			
			// Is a Macro to empty all the name counters to start to count from 0 again.
			Empty_name_counters ;
			
		    // Complete the name scaning process. 
			while( bank_account[i].name[s] != Null )
			{
			
				// Counting the letters on the name.
				if( BankAccountNameContains_Alphabets )
				{
					
					name_alphabet ++ ;
					
				}
				
				// Counting the numbers on the name.
				else if( BankAccountNameContains_Numbers )
				{
					
					name_nums ++ ;
					
				}
				
				// Counting the spaces on the name. 
				else if( BankAccountNameContains_Spaces  )
				{
					
					spaces_in_name ++ ;
					
				}
				
				// Counting the special characters on the name.
				else
				{
					
					name_special_char ++ ;
					
				}
			
				s++;
			}
			
		}
		
		// In case he enters a number on the name. 
		while( name_nums > Max_name_nums )
		{
			
			printf("\nRejected: You must enter at least first four names without any numbers ex: Mohamed Salah Hamed Mahrous\n");	
			
			// To scan the name of the client. 
			printf("\nEnter the name of the client account: ") ; gets(bank_account[i].name) ;
			
			// Is a function to clear (or flush) the output buffer and move the buffered data to console.
			fflush(stdin) ;
			
			// Is a Macro to empty all the name counters to start to count from 0 again.
			Empty_name_counters ;
			
			// Complete the name scaning process. 
			while( bank_account[i].name[s] != Null )
			{
			
				// Counting the letters on the name.
				if( BankAccountNameContains_Alphabets )
				{
					
					name_alphabet ++ ;
					
				}
				
				// Counting the numbers on the name.
				else if( BankAccountNameContains_Numbers )
				{
					
					name_nums ++ ;
					
				}
				
				// Counting the spaces on the name. 
				else if( BankAccountNameContains_Spaces  )
				{
					
					spaces_in_name ++ ;
					
				}
				
				// Counting the special characters on the name.
				else
				{
					
					name_special_char ++ ;
					
				}
			
				s++;
				
			}
			
			
			
		}
	
		// In case he enters less than 3 spaces in the name.
		while( spaces_in_name < Min_name_spaces )
		{
			
			printf("\nRejected: You must enter at least first four names between every name there's a space ex: Mohamed Salah Hamed Mahrous\n");	
			
			// To scan the name of the client.
			printf("\nEnter the name of the client account: ") ; gets(bank_account[i].name) ;
			
			// Is a function to clear (or flush) the output buffer and move the buffered data to console.
			fflush(stdin) ;
			
			// Is a Macro to empty all the name counters to start to count from 0 again.
			Empty_name_counters ;
			
			// Complete the name scaning process. 
			while( bank_account[i].name[s] != Null )
			{
			
				// Counting the letters on the name.
				if( BankAccountNameContains_Alphabets )
				{
					
					name_alphabet ++ ;
					
				}
				
				// Counting the numbers on the name.
				else if( BankAccountNameContains_Numbers )
				{
					
					name_nums ++ ;
					
				}
				
				// Counting the spaces on the name. 
				else if( BankAccountNameContains_Spaces  )
				{
					
					spaces_in_name ++ ;
					
				}
				
				// Counting the special characters on the name.
				else
				{
					
					name_special_char ++ ;
					
				}
			
				s++;
				
			}
			
		}
		
		// In case he enters a special characters on the name except the 3 spaces.
		while( name_special_char > Max_name_special_char )
		{
			
			printf("\nRejected: You must enter at least first four names without any special characters except the 3 spaces ex: Mohamed Salah Hamed Mahrous\n");	
			
			// To scan the name of the client. 
			printf("\nEnter the name of the client account: ") ; gets(bank_account[i].name) ;
			
			// Is a function to clear (or flush) the output buffer and move the buffered data to console.
			fflush(stdin) ;
			
			// Is a Macro to empty all the name counters to start to count from 0 again.
			Empty_name_counters ;
			
			// Complete the name scaning process. 
			while( bank_account[i].name[s] != Null )
			{
			
				// Counting the letters on the name.
				if( BankAccountNameContains_Alphabets )
				{
					
					name_alphabet ++ ;
					
				}
				
				// Counting the numbers on the name.
				else if( BankAccountNameContains_Numbers )
				{
					
					name_nums ++ ;
					
				}
				
				// Counting the spaces on the name. 
				else if( BankAccountNameContains_Spaces  )
				{
					
					spaces_in_name ++ ;
					
				}
				
				// Counting the special characters on the name.
				else
				{
					
					name_special_char ++ ;
					
				}
			
				s++;
			}
			
			
			
		}
		
		
		
		//_________________________________________________________________Operations on Client address_________________________________________________________________//

	   	// To scan the address of the client.
		bank_account[i].address		=    get_string(NULL,"\nEnter the address of the client account: ")	  ;
		
		// In case he doesn't enter a full address.
		while( strlen(bank_account[i].address) < Min_address_chars )
		{
			
			printf("\nRejected: You must enter a full address ex: 6 Hussien Wassef, F rom El-Dokki st , G i z a\n");	
			
			// To scan the address of the client.
			bank_account[i].address	=    get_string(NULL,"\nEnter the address of the client account: ")   ;
			
		}
		
		

		
		//_________________________________________________________________Operations on Client national_ID_________________________________________________________________//
		
		// To scan the national_ID of the client.
		bank_account[i].national_ID	=    get_long_long("\nEnter the national_ID of the client account: ") ;
		
		// To count the digits of the ID to force him entering only 14 digits.
		national_ID_digits = floor( log10(bank_account[i].national_ID) )+1 ;
		
		// In case the admin entered an ID not equal 14 digits.
		while ( national_ID_digits != Digits_of_national_ID )
		{
			// Empty the counter to count the new ID again.
			national_ID_digits = Initialized_by_Zero ;
			
			printf("\nRejected: You must enter National ID which consist of 14 digit Number ex: 29805070100179\n");
			
			// To scan the national_ID of the client.
			bank_account[i].national_ID	=    get_long_long("\nEnter the national_ID of the client account: ") ;
         
			
			// To count the digits of the ID to force him entering only 14 digits.
			national_ID_digits = floor( log10(bank_account[i].national_ID) )+1 ;
         
          
			
		}
		
		
		
		//_________________________________________________________________Operations on Client bank_account_ID_________________________________________________________________//
		
		// Intializes random number generator
		srand( ( unsigned long long int ) time(NULL) ) ;
		
		// Assign a default bank account_ID to the bank accounts.
		bank_account[i].bank_account_ID = ( rand( ) % (Bank_account_ID_upper_limit - Bank_account_ID_lower_limit + The_last_limit) + Bank_account_ID_lower_limit ) ;
		
		// To print the bank account ID of the client.
		printf("\nThe bank account ID of the client account: %llu\n", bank_account[i].bank_account_ID ) ;
		
		
		
		//_________________________________________________________________Operations on Client age_________________________________________________________________//
		
		// To scan the age of the client.
        bank_account[i].age 		=    get_int("\nEnter the age of the client account: ")               ;
		
		// In case of user is less than 21 he must have a guardian.
		if( bank_account[i].age < Minor_age )
		{
			
			// To scan the guardian name of the client.
			printf("\nEnter the guardian name of the client account: ") ; gets(bank_account[i].guardian_name) ;
	
			// Is a function to clear (or flush) the output buffer and move the buffered data to console.
			fflush(stdin) ;
			
			
			// In case he doesn't enter a full name.
			while( strlen(bank_account[i].guardian_name) < Min_name_chars )
			{
			
				printf("\nRejected: You must enter at least first four names ex: Mohamed Salah Hamed Mahrous\n");	
			
				// To scan the guardian name of the client.
				printf("\nEnter the guardian name of the client account: ") ; gets(bank_account[i].guardian_name) ;
	
				// Is a function to clear (or flush) the output buffer and move the buffered data to console.
				fflush(stdin) ;
			 
			 
			}
			
			
			
			//_________________________________________________________________Operations on Client guardian_name_________________________________________________________________//
			
			// Is a Macro to empty all the name counters to start to count from 0 again.
			Empty_name_counters ;
			
			
			// Complete the name scaning process 
			while( bank_account[i].guardian_name[s] != Null )
			{
				
				// Counting the letters on the name
				if( BankAccountNameContains_Alphabets )
				{
					
					name_alphabet ++ ;
					
				}
				
				// Counting the numbers on the name
				else if( BankAccountNameContains_Numbers )
				{
					
					name_nums ++ ;
					
				}
				
				// Counting the spaces on the name 
				else if( BankAccountNameContains_Spaces  )
				{
					
					spaces_in_name ++ ;
					
				}
				
				// Counting the special characters on the name
				else
				{
					
					name_special_char ++ ;
					
				}
			
				s++;
			}
			
			
			
			// In case he doesn't enter a full name
			while( name_alphabet < Min_name_alphabets )
			{
				
				printf("\nRejected: You must enter at least first four names ex: Mohamed Salah Hamed Mahrous\n");	
				
				// To scan the guardian name of the client.
				printf("\nEnter the guardian name of the client account: ") ; gets(bank_account[i].guardian_name) ;
	
				// Is a function to clear (or flush) the output buffer and move the buffered data to console.
				fflush(stdin) ;
				
				// Is a Macro to empty all the name counters to start to count from 0 again.
				Empty_name_counters ;
				
				
				// Complete the name scaning process. 
				while( bank_account[i].guardian_name[s] != Null )
				{
				
					// Counting the letters on the name.
					if( BankAccountNameContains_Alphabets )
					{
						
						name_alphabet ++ ;
						
					}
					
					// Counting the numbers on the name.
					else if( BankAccountNameContains_Numbers )
					{
						
						name_nums ++ ;
						
					}
					
					// Counting the spaces on the name. 
					else if( BankAccountNameContains_Spaces  )
					{
						
						spaces_in_name ++ ;
						
					}
					
					// Counting the special characters on the name.
					else
					{
						
						name_special_char ++ ;
						
					}
				
					s++;
				}
				
			}
			
			// In case he enters a number on the name. 
			while( name_nums > Max_name_nums )
			{
				
				printf("\nRejected: You must enter at least first four names without any numbers ex: Mohamed Salah Hamed Mahrous\n");	
				
				// To scan the guardian name of the client.
				printf("\nEnter the guardian name of the client account: ") ; gets(bank_account[i].guardian_name) ;
	
				// Is a function to clear (or flush) the output buffer and move the buffered data to console.
				fflush(stdin) ;
				
				// Is a Macro to empty all the name counters to start to count from 0 again.
				Empty_name_counters ;
				
				// Complete the name scaning process. 
				while( bank_account[i].guardian_name[s] != Null )
				{
				
					// Counting the letters on the name.
					if( BankAccountNameContains_Alphabets )
					{
						
						name_alphabet ++ ;
						
					}
					
					// Counting the numbers on the name.
					else if( BankAccountNameContains_Numbers )
					{
						
						name_nums ++ ;
						
					}
					
					// Counting the spaces on the name. 
					else if( BankAccountNameContains_Spaces  )
					{
						
						spaces_in_name ++ ;
						
					}
					
					// Counting the special characters on the name.
					else
					{
						
						name_special_char ++ ;
						
					}
				
					s++;
					
				}
				
				
				
			}
		
			// In case he enters less than 3 spaces in the name.
			while( spaces_in_name < Min_name_spaces )
			{
				
				printf("\nRejected: You must enter at least first four names between every name there's a space ex: Mohamed Salah Hamed Mahrous\n");	
				
				// To scan the guardian name of the client.
				printf("\nEnter the guardian name of the client account: ") ; gets(bank_account[i].guardian_name) ;
	
				// Is a function to clear (or flush) the output buffer and move the buffered data to console.
				fflush(stdin) ;
				
				// Is a Macro to empty all the name counters to start to count from 0 again.
				Empty_name_counters ;
				
				// Complete the name scaning process. 
				while( bank_account[i].guardian_name[s] != Null )
				{
				
					// Counting the letters on the name.
					if( BankAccountNameContains_Alphabets )
					{
						
						name_alphabet ++ ;
						
					}
					
					// Counting the numbers on the name.
					else if( BankAccountNameContains_Numbers )
					{
						
						name_nums ++ ;
						
					}
					
					// Counting the spaces on the name. 
					else if( BankAccountNameContains_Spaces  )
					{
						
						spaces_in_name ++ ;
						
					}
					
					// Counting the special characters on the name.
					else
					{
						
						name_special_char ++ ;
						
					}
				
					s++;
					
				}
				
			}
			
			// In case he enters a special characters on the name except the 3 spaces.
			while( name_special_char > Max_name_special_char )
			{
				
				printf("\nRejected: You must enter at least first four names without any special characters except the 3 spaces ex: Mohamed Salah Hamed Mahrous\n");	
				
				// To scan the name of the client. 
				printf("\nEnter the guardian name of the client account: ") ; gets(bank_account[i].guardian_name) ;
				
				// Is a function to clear (or flush) the output buffer and move the buffered data to console.
				fflush(stdin) ;
				
				// Is a Macro to empty all the name counters to start to count from 0 again.
				Empty_name_counters ;
				
				// Complete the name scaning process. 
				while( bank_account[i].guardian_name[s] != Null )
				{
				
					// Counting the letters on the name.
					if( BankAccountNameContains_Alphabets )
					{
						
						name_alphabet ++ ;
						
					}
					
					// Counting the numbers on the name.
					else if( BankAccountNameContains_Numbers )
					{
						
						name_nums ++ ;
						
					}
					
					// Counting the spaces on the name. 
					else if( BankAccountNameContains_Spaces  )
					{
						
						spaces_in_name ++ ;
						
					}
					
					// Counting the special characters on the name.
					else
					{
						
						name_special_char ++ ;
						
					}
				
					s++;
				}
				
				
				
			}
			
			
			
			//_________________________________________________________________Operations on Client guardian_NationalID _________________________________________________________________//
			
			// To scan the guardian national_ID of the client.
			bank_account[i].guardian_NationalID	=    get_long_long("\nEnter the guardian national_ID of the client account: ")	;
			
			
			// To count the digits of the ID to force him entering only 14 digits.
			guardian_national_ID_digits = floor( log10(bank_account[i].guardian_NationalID) )+1 ;
			
			
			// In case the admin entered an ID not equal 14 digits.
			while ( guardian_national_ID_digits != Digits_of_national_ID )
			{
				// Empty the counter to count the new ID again.
				guardian_national_ID_digits = Initialized_by_Zero ;
				
				printf("\nRejected: You must enter National ID which consist of 14 digit Number ex: 29805070100179\n");
				
				// To scan the national_ID of the client.
				bank_account[i].guardian_NationalID	=   get_long_long("\nEnter the guardian national_ID of the client account: ") ; 
			 
				
			 	// To count the digits of the ID to force him entering only 14 digits.
				guardian_national_ID_digits = floor( log10(bank_account[i].guardian_NationalID) )+1 ;
			 
			  
				
			}
		 
         
         
      		
         	
		}
		
		
		
		//_________________________________________________________________Operations on Client balance_________________________________________________________________//
		
		// To scan the balance of the client.
		bank_account[i].balance		=    get_long_long("\nEnter the balance of the client account: ")     ;
		
		
		//_________________________________________________________________Operations on Client account_status_________________________________________________________________//
		
		// To print the bank account status of the client.
		printf("\nThe account status of the client: %s\n" 	, strcpy(bank_account[i].account_status, "Active") ) ;
		
		
		//_________________________________________________________________Operations on Client password________________________________________________________________//
		
		// Assign a default password to the bank accounts.
		bank_account[i].password = ( rand( ) % (Password_upper_limit - Password_lower_limit + The_last_limit) + Password_lower_limit ) ;
		
		// To print the account password of the client.
		printf("\nThe password of the client: %llu" 		, bank_account[i].password )  ;
	
	
	
		//_________________________________________________________________End of creat bank accounts operations_________________________________________________________________//
	
		// Is a boundary between the bank accounts.
		printf("\n__________________________________________________________________________________________________________________________________\n") ;
	 
	 
	 
	 
	 
  	}
  
  
  
  
  
  
} 





/*****************************************************************************************************************************************/
/****************************************************************************************************************************************/



/*
 * @Function  name 	:	vOpen_ExistingAccount( ).
 * @Function  info. 	:	Open the existing accounts and make operations. 
 * @Function  input	:	None.
 * @@Function return	:	None.
 * 
 */
void vOpen_ExistingAccount( void )
{
	
	
	int i = Iteration_start ; // Is a variable for the first iteration.
	

	
	printf("\n\n\n/*---------------------------------- Open Existing Account -----------------------------------*/\n\n");
	
	
	// To scan the bank account_ID.
	open_bank_ID = get_long_long("\nEnter the bank account_ID of the client account: ");
	
	
	// To iterate on all bank accounts.
	for( i = Iteration_start ; i< accounts_nums ; i++ )
	{
		
		// Check if the input bank account_ID is exist.
		if( open_bank_ID == bank_account[i].bank_account_ID )
		{
		
			// Assign the account number on the flag.
			OpenExistingAccount_flag = i;
			
			break;
			
		 
		 
		}
		
	
		// if the input bank account_ID doesn't exist.
		else
		{
			// Assign a negative value on the flag.
			OpenExistingAccount_flag = Flag_Incorrect ;
		 
			
		}
		
		
		
		
	}	
	
	
	
	// If the flag isn't a negative value so the input bank account_ID is exist.
	if( OpenExistingAccount_flag >= Flag_Correct )
	{
	
		// Select the features of the Open Existing Account Menu.
		vOpen_ExistingAccount_Menu( );
      
	  
		
		
	}
	
	else
	{
		
		// Give him two more tries to enter an existent bank account_ID.
		vOpen_ExistingAccount_Flag_Check3times( OpenExistingAccount_flag );
	 
	}
	
	
	
	
	
	
}




/*****************************************************************************************************************************************/
/****************************************************************************************************************************************/


/*
 * @Function  name 	:	vOpen_ExistingAccount_Menu( ).
 * @Function  info. 	:	Select the features of the Open Existing Account Menu.
 * @Function  input	:	None.
 * @@Function return	:	None.
 * 
 */
void vOpen_ExistingAccount_Menu( void )
{
	
	
	
	int select_Open_ExistingAccount_Menu = Initialized_by_Zero ; // Is a variable for scaning the Open Existing Account Menu choice.
	
	
	// Making a menu for the Open Existing Account.
	do
	{
	
		printf("\n\n")																								;
		printf("+===========================================================================================+\n")   ;
		printf("|                          The \"Open Existing Account\" Menu                                 |\n") ;
		printf("+===========================================================================================+\n")   ;
		printf("| 1 | Make Transaction                                                                      |\n")   ;
		printf("|---|---------------------------------------------------------------------------------------|\n")   ;
		printf("| 2 | Change Account Status                                                                 |\n")   ;
		printf("|---|---------------------------------------------------------------------------------------|\n")   ;
		printf("| 3 | Get Cash                                                               		    |\n")   ;
		printf("|---|---------------------------------------------------------------------------------------|\n")   ;
		printf("| 4 | Deposit in Account                                                               	    |\n")   ;
		printf("|---|---------------------------------------------------------------------------------------|\n")   ;
		printf("| 0 | Return to main Menu                                                                   |\n")   ;
		printf("+===========================================================================================+\n")   ;
	  
	  
		// To scan the Menu choice.
		select_Open_ExistingAccount_Menu = get_int("\nKindly, select the choice number: ") ;
	  
		
		/* 
		
		 *	To handle entering a number other than the available ones (0,1,2,3,4):
		
		 * 	If you enter a number other than (0,1,2) 
			the program will (display Not a choice.try again, please.)
			and will ask you to enter your choice again and repeat that if you enter 
			a not available choice, until you enter one of the available choices then the program 
			will continue.
			
		*/
	  	while ( Default_of_select_Open_ExistingAccount_Menu )
		{
			
			printf("\n\nNot a choice.try again, please.\n") ;
			
			// To scan the Menu choice from the Open Existing Account Menu.
			select_Open_ExistingAccount_Menu = get_int("\nKindly, select the feature number: ") ; 
			
			
		}
	  
	  
	  
    	// Switching on the Open Existing Account Menu choices.
      	switch( select_Open_ExistingAccount_Menu )
    	{
    		// The choice number 1 is Make Transaction.
    		case Make_Transaction  		:	vMake_Transaction( )		;	break;
    		
    		// The choice number 2 is Change Account Status.
    		case Change_Account_Status	:	vChange_Account_Status( )	;	break;
			
			// The choice number 3 is Get Cash.
    		case Get_Cash 			:	vGet_Cash( )			;	break;
			
			// The choice number 4 is Deposit in Account.
    		case Deposit_in_Account 	:	vDeposit_in_Account( )		;	break;
    		
    		// The choice number 0 is exiting from the Open Existing Account Menu.
    		case Return_to_mainMenu 	: 	printf("\nYou exit from the Open Existing Account Menu\n") ;
    		
    	}
      
      
      
      
      
    	// Do that until the Admin choose to exit from the Admin window.
    }while( select_Open_ExistingAccount_Menu != Return_to_mainMenu );






}





/*****************************************************************************************************************************************/
/****************************************************************************************************************************************/


/*
 * @Function  name 	:	vOpen_ExistingAccount_Flag_Check3times( Open_ExistingAccount_flag ).
 * @Function  info. 	:	Give two more tries to the Admin to enter an existent bank account_ID. 
 * @Function  input	:	Open_ExistingAccount_flag.
 * @@Function return	:	None.
 * 
 */
void vOpen_ExistingAccount_Flag_Check3times( int OpenExistingAccount_flag )
{
	
	int i = Iteration_start ; // Is a variable for the second iteration.
	
	int j = Iteration_start ; // Is a variable for the first iteration.
	
	// Give him two more tries to enter an existent bank account_ID.
	for ( j = Iteration_start ; j< Twice ; j++ )
	{
		
		printf("\nNot found, Try again\n");
	    
		// To scan the bank account_ID.
		open_bank_ID = get_long_long("\nEnter the bank account_ID of the client account: ");
	
	
		// To iterate on all bank accounts.
		for( i = Iteration_start ; i< accounts_nums ; i++ )
		{
	
			// Check if the input bank account_ID is exist.
			if( open_bank_ID == bank_account[i].bank_account_ID )
			{
				// Assign the account number on the flag.
				OpenExistingAccount_flag = i;
			
				break;
	          
			}
	 
			// if the input bank account_ID doesn't exist.
			else
			{
				
				// Assign a negative value on the flag.
				OpenExistingAccount_flag = Flag_Incorrect ;
			 
			 
			}
	      
	     
			
		}
		
		
		// If the flag isn't a negative value so the input bank account_ID is exist.
		if ( OpenExistingAccount_flag >= Flag_Correct )
		{	
	
			// Select the features of the Open Existing Account Menu.
			vOpen_ExistingAccount_Menu( );
			
	
			break;
		  
		  
	     
	   	}
	  
	 
	 
	 
	 
	}
	
	
	// If he enters a nonexistent bank account_ID for the third time exit from the function.
	if( OpenExistingAccount_flag < Flag_Correct )
	{
	
	
	
		printf("\nNo more tries\n");
		
		
	    
	    
	} 
	
	
	

	
	
	
}





/*****************************************************************************************************************************************/
/****************************************************************************************************************************************/

/*
 * @Function  name 	:	vMake_Transaction( ).
 * @Function  info. 	:	Transfaring amount of money from one account to another. 
 * @Function  input	:	None.
 * @@Function return	:	None.
 * 
 */
void vMake_Transaction( void )
{
	
	int i 					= Iteration_start 	; // Is a variable for the first iteration.
	
	int amount_of_money 			= Initialized_by_Zero 	; // Is a variable for scaning the amount of money to be transfered.		
	
	int transfered_account_activation	= Initialized_by_Zero	; // Is a variable for checking the status of the transfered account.

	
	
	printf("\n\n\n/*---------------------------------- Make Transaction -----------------------------------*/\n\n");
	
	
	// To scan the bank account_ID.
	transfered_bank_ID = get_long_long("\nEnter the bank account_ID you want to transfer money to: ");
	
	
	// To iterate on all bank accounts.
	for( i = Iteration_start ; i< accounts_nums ; i++ )
	{
		
		// Check if the input bank account_ID is exist.
		if( transfered_bank_ID == bank_account[i].bank_account_ID )
		{
		
			// Assign the account number on the flag.
			makeTransaction_flag = i;
			
			break;
			
		 
		 
		}
		
	
		// if the input bank account_ID doesn't exist.
		else
		{
			// Assign a negative value on the flag.
			makeTransaction_flag = Flag_Incorrect ;
		 
			
		}
		
		
		
		
	}	
	
	
	
	// If the flag isn't a negative value so the input bank account_ID is exist.
	if( makeTransaction_flag >= Flag_Correct )
	{
	
		
		// if the open account is active return 0.
		open_account_activation 		= strcmp( bank_account[OpenExistingAccount_flag].account_status 	, "Active" ) 	; 
		
		// if the transfered account is active return 0.
		transfered_account_activation	= strcmp( bank_account[makeTransaction_flag].account_status 		, "Active" )	;
		
		// if the both accounts is active equal 0.
		active_accounts_checking 		= open_account_activation & transfered_account_activation 							;
		
		
		// Check if the both accounts is active equal 0.
		if( Equal_strings == active_accounts_checking )
		{
			
			
			// To scan the amount of money to be transfered.
			amount_of_money = get_long_long("\nEnter amount of money to transfer it to the this account: ") ;
	
			// To make sure that the amount of money is less than your client’s balance or the transaction won’t be completed.
			if( amount_of_money < bank_account[OpenExistingAccount_flag].balance )
			{
				
				// Assign the open_bank_ID that has been entered to the client bank_ID, who wants to transact the money.			
				bank_account[OpenExistingAccount_flag].bank_account_ID	= 	open_bank_ID 		;
				
				// Assign the transfered_bank_ID that has been entered to the client bank_ID, who the money will be transfered to.
				bank_account[makeTransaction_flag].bank_account_ID 		= 	transfered_bank_ID 	;
				
				// Substracting the amount of money that will be transfered from the client account, who wants to transact the money. 
				bank_account[OpenExistingAccount_flag].balance 	    	-= 	amount_of_money 	;
				
				// Adding the amount of money that will be transfered to the client account, who the money will be transfered to.
				bank_account[makeTransaction_flag].balance 				+= 	amount_of_money 	;
			 	
			}
			
			
			//The money is less than your client’s balance, the transaction won’t be completed.
			else
			{
			
				printf("\nThe money is less than your client’s balance, the transaction won’t be completed.") ;
				
				
				
			}
		 
		 
		 
		 
		}
		
		// If the open account or/and the transfered account isn't/aren't Active.
		else
		{
		
			printf("\nThe open account or/and the transfered account isn't/aren't Active.") ;
			
		}
		
      
	 
		
		
	}
	
	// If the flag is a negative value so the input bank account_ID isn't exist.
	else
	{
		// Give him two more tries to enter an existent bank account_ID.
		vMake_Transaction_Flag_Check3times( makeTransaction_flag );
	  
	}
	
	
	
	
	

	
}




/*****************************************************************************************************************************************/
/****************************************************************************************************************************************/



/*
 * @Function  name 	:	vMake_Transaction_Flag_Check3times( MakeTransaction_flag ).
 * @Function  info. 	:	Give two more tries to the Admin to enter an existent bank account_ID. 
 * @Function  input	:	Make_Transaction_flag.
 * @@Function return	:	None.
 * 
 */
void vMake_Transaction_Flag_Check3times( int makeTransaction_flag )
{
	
	int i = Iteration_start ; // Is a variable for the second iteration.
	
	int j = Iteration_start ; // Is a variable for the first iteration.
	
	// Give him two more tries to enter an existent bank account_ID.
	for ( j = Iteration_start ; j < Twice ; j++ )
	{
		
		printf("\nNot found, Try again\n");
	    
		// To scan the bank account_ID.
		transfered_bank_ID = get_long_long("\nEnter the bank account_ID of the client account: ");
	
	
		// To iterate on all bank accounts.
		for( i = Iteration_start ; i< accounts_nums ; i++ )
		{
	
			// Check if the input bank account_ID is exist.
			if(  transfered_bank_ID == bank_account[i].bank_account_ID )
			{
				// Assign the account number on the flag.
				makeTransaction_flag = i;
			
				break;
	          
			}
	 
			// if the input bank account_ID doesn't exist.
			else
			{
				
				// Assign a negative value on the flag.
				makeTransaction_flag = Flag_Incorrect ;
			 
			 
			}
	      
	     
			
		}
		
		
		// If the flag isn't a negative value so the input bank account_ID is exist.
		if ( makeTransaction_flag >= Flag_Correct )
		{	
	
	
			int amount_of_money 			= Initialized_by_Zero 	; // Is a variable for scaning the amount of money to be transfered.		
	
			int transfered_account_activation	= Initialized_by_Zero	; // Is a variable for checking the status of the transfered account.
	
			
			// if the open account is active return 0.
			open_account_activation 		= strcmp( bank_account[OpenExistingAccount_flag].account_status 	, "Active" ) 	; 
			
			// if the transfered account is active return 0.
			transfered_account_activation		= strcmp( bank_account[makeTransaction_flag].account_status 		, "Active" )	;
			
			// if the both accounts is active equal 0.
			active_accounts_checking 		= open_account_activation & transfered_account_activation 				;
			
			
			// Check if the both accounts is active equal 0.
			if( Equal_strings == active_accounts_checking )
			{
				
				
				// To scan the amount of money to be transfered.
				amount_of_money = get_long_long("\nEnter amount of money to transfer it to the this account: ") ;
		
				// To make sure that the amount of money is less than your client’s balance or the transaction won’t be completed.
				if( amount_of_money < bank_account[OpenExistingAccount_flag].balance )
				{
					
					// Assign the open_bank_ID that has been entered to the client bank_ID, who wants to transact the money.			
					bank_account[OpenExistingAccount_flag].bank_account_ID	= 	open_bank_ID 		;
					
					// Assign the transfered_bank_ID that has been entered to the client bank_ID, who the money will be transfered to.
					bank_account[makeTransaction_flag].bank_account_ID 	= 	transfered_bank_ID 	;
					
					// Substracting the amount of money that will be transfered from the client account, who wants to transact the money. 
					bank_account[OpenExistingAccount_flag].balance 	    	-= 	amount_of_money 	;
					
					// Adding the amount of money that will be transfered to the client account, who the money will be transfered to.
					bank_account[makeTransaction_flag].balance 		+= 	amount_of_money 	;
					
				}
				
				
				//The money is less than your client’s balance, the transaction won’t be completed.
				else
				{
				
					printf("\nThe money is less than your client’s balance, the transaction won’t be completed.") ;
					
					
					
				}
			 
			  
			  
			  
			}
			
			// If the open account or/and the transfered account isn't/aren't Active.
			else
			{
			
				printf("\nThe open account or/and the transfered account isn't/aren't Active.") ;
				
			}
			
	
	
			break;
		  
		  
	     
	   	}
	  
	 
	 
	 
	 
	}
	
	
	// If he enters a nonexistent bank account_ID for the third time exit from the function.
	if( makeTransaction_flag < Flag_Correct )
	{
	
	
	
		printf("\nNo more tries\n");
		
		
	    
	    
	} 
	
	
	

	
	
	
}





/*****************************************************************************************************************************************/
/****************************************************************************************************************************************/


/*
 * @Function  name 	:	vChange_Account_Status( ).
 * @Function  info. 	:	Change Bank Account Status. 
 * @Function  input	:	None.
 * @@Function return	:	None.
 * 
 */
void vChange_Account_Status( void )
{

	int select_AccountStatus = Initialized_by_Zero ; // Is a variable for changing the account status. 
	

	printf("\n\n\n/*---------------------------------- Change Bank Account Status -----------------------------------*/\n\n");

	printf("\n\n")																								;
    printf("+===========================================================================================+\n")   ;
    printf("|                           \"Change Bank Account Status\"                                    |\n") ;
    printf("+===========================================================================================+\n")   ;
    printf("| 1 | Set Account to Active State                                                           |\n")   ;
    printf("|---|---------------------------------------------------------------------------------------|\n")   ;
    printf("| 2 | Set Account to Restricted State                                                       |\n")   ;
    printf("|---|---------------------------------------------------------------------------------------|\n")   ;
    printf("| 3 | Set Account to Closed State                                                           |\n")   ;
    printf("+===========================================================================================+\n")   ;


	// To scan the Bank Account Status you want.
	select_AccountStatus = get_int("\nKindly, select the Bank Account Status you want: ") ;



	/* 
    
     *	To handle entering a number other than the available ones (0,1,2,3,4):
    
     * 	If you enter a number other than (0,1,2) 
    	the program will (display Not a choice.try again, please.)
    	and will ask you to enter your choice again and repeat that if you enter 
    	a not available choice, until you enter one of the available choices then the program 
    	will continue.
    	
    */
    while ( Default_of_select_AccountStatus )
    {
    	
    	printf("\n\nNot a choice.try again, please.\n") ;
    	
    	// To scan the Menu choice from the Open Existing Account Menu.
    	select_AccountStatus = get_int("\nKindly, select the Bank Account Status you want: ") ; 
    	
    	
    }
	
	
	// Switching on the Open Existing Account Menu choices.
	switch( select_AccountStatus )
	{
		// The choice number 1 is Set Account to Active State.
		case Active_State  		:	strcpy( bank_account[OpenExistingAccount_flag].account_status , "Active" )		;	break;
		
		// The choice number 2 is Set Account to Restricted State.
		case Restricted_State		:	strcpy( bank_account[OpenExistingAccount_flag].account_status , "Restricted" )	;	break;
		
		// The choice number 3 is Set Account to Closed State.
		case Closed_State 		:	strcpy( bank_account[OpenExistingAccount_flag].account_status , "Closed" )		;	break;
		
	 
		
	}




}





/*****************************************************************************************************************************************/
/****************************************************************************************************************************************/

/*
 * @Function  name 	:	vGet_Cash( ).
 * @Function  info. 	:	Get cash from a bank account. 
 * @Function  input	:	None.
 * @@Function return	:	None.
 * 
 */
void vGet_Cash( void )
{


	int cash = Initialized_by_Zero ; // Is a variable for getting cash from the bank account.
	
	

	printf("\n\n\n/*---------------------------------- Get Cash -----------------------------------*/\n\n");

	
	// if the open account is active return 0.
	open_account_activation = strcmp( bank_account[OpenExistingAccount_flag].account_status 	, "Active" ) ; 

	// Check if the both accounts is active equal 0.
	if( Equal_strings == open_account_activation )
	{
		
		// To scan the amount of money to be got.
		cash = get_int("\nEnter the cash amount you want from this account: ") ;
		
    
    	// To make sure that the amount of money is less than your client’s balance or the transaction won’t be completed.
    	if( cash < bank_account[OpenExistingAccount_flag].balance )
    	{
    		
    		// Assign the open_bank_ID that has been entered to the client bank_ID, who wants to transact the money.			
    		bank_account[OpenExistingAccount_flag].bank_account_ID	= 	open_bank_ID ;
    	
    		
    		// Substracting the amount of money that will be taken from the client account, who wants to get the money. 
    		bank_account[OpenExistingAccount_flag].balance 	    	-= 	cash 		;
    		
			
    	}
    	
    	
    	//The money is less than your client’s balance, the transaction won’t be completed.
    	else
    	{
    	
    		printf("\nThe money is less than your client’s balance, the transaction won’t be completed.") ;
    		
    		
    		
    	}
     
     
     
     
    }
    
    // If the open account isn't Active.
    else
    {
    
    	printf("\nThe open account isn't Active.") ;
    	
    }
	








}









/*****************************************************************************************************************************************/
/****************************************************************************************************************************************/



/*
 * @Function  name 	:	vDeposit_in_Account( ).
 * @Function  info. 	:	Add cash to a bank account. 
 * @Function  input	:	None.
 * @@Function return	:	None.
 * 
 */
void vDeposit_in_Account( void )
{
	
	
	
	int add_cash = Initialized_by_Zero ; // Is a variable for adding cash to a bank account.
	
	
	
	printf("\n\n\n/*---------------------------------- Deposit in Account -----------------------------------*/\n\n");
	
	
	
	
	// if the open account is active return 0.
	open_account_activation = strcmp( bank_account[OpenExistingAccount_flag].account_status 	, "Active" ) ; 
	

	// Check if the both accounts is active equal 0.
	if( Equal_strings == open_account_activation )
	{
	
		// To scan the amount of money to be deposited.
		add_cash = get_int("\nEnter the cash amount you want to add to this account: ") ;
		
		// Assign the open_bank_ID that has been entered to the client bank_ID, who wants to transact the money.			
		bank_account[OpenExistingAccount_flag].bank_account_ID	= 	open_bank_ID ;
		
		
		// Substracting the amount of money that will be taken from the client account, who wants to get the money. 
		bank_account[OpenExistingAccount_flag].balance 	    	+= 	add_cash 	;
		
	 
	}
	
	// If the open account isn't Active.
	else
	{
	
		printf("\nThe open account isn't Active.") ;
		
	}
	
	
	
	

	
	
	
}







/*****************************************************************************************************************************************/
    /*------------------------------------------------- The Client window functions --------------------------------------------------*/
/****************************************************************************************************************************************/


/*
 * @Function  name 	:	vClient_windowFeatures( ).
 * @Function  info. 	:	Select the features of the client window. 
 * @Function  input	:	None.
 * @@Function return	:	None.
 * 
 */
void vClient_windowFeatures( void )
{
	
	
	int select_ClientFeatures	= Initialized_by_Zero 	; // Is a variable for scaning the feature number.

	int i 				= Iteration_start 	; // Is a variable for the first iteration.
	
	
	
	// To scan the bank account_ID.
	client_bank_ID 		= get_long_long("\nEnter the bank account_ID of the client account: ")		;
	
	// To scan the bank account password.
	client_password		= get_long_long("\nEnter the bank account password of the client account: ")	;
	
	
	// To iterate on all bank accounts.
	for( i = Iteration_start ; i< accounts_nums ; i++ )
	{
		
		// Check if the input bank account_ID and password is exist and correct.
		if( Correct_ClientbankID_and_password )
		{
		
			// Assign the account number on the flag.
			clientWindow_flag = i;
			
			break;
			
		 
		 
		}
		
	
		// if the input bank account_ID and password doesn't exist or correct.
		else
		{
			// Assign a negative value on the flag.
			clientWindow_flag = Flag_Incorrect ;
		 
			
		}
		
		
		
		
	}	
	
	
	
	// If the flag isn't a negative value so the input bank account_ID and password is exist and correct.
	if( clientWindow_flag >= Flag_Correct )
	{
	
		// Making a menu for the Client features.
		do
		{

			printf("\n\n")																								;
			printf("+===========================================================================================+\n")   ;
			printf("|                           Welcome to The \"Client window\"                                  |\n") ;
			printf("+===========================================================================================+\n")   ;
			printf("| 1 | Make Transaction                                                                      |\n")   ;
			printf("|---|---------------------------------------------------------------------------------------|\n")   ;
			printf("| 2 | Change Account Password                                                               |\n") ;
			printf("|---|---------------------------------------------------------------------------------------|\n")   ;
			printf("| 3 | Get Cash                                                               		    |\n")   ;
			printf("|---|---------------------------------------------------------------------------------------|\n")   ;
			printf("| 4 | Deposit in Account                                                               	    |\n")   ;
			printf("|---|---------------------------------------------------------------------------------------|\n")   ;
			printf("| 0 | Return to main Menu                                                                   |\n")   ;
			printf("+===========================================================================================+\n")   ;
	  
	  
			// To scan the feature number
			select_ClientFeatures = get_int("\nKindly, select the feature number: ") ;
	  
			
			/* 
			
			 *	To handle entering a number other than the available ones (0,1,2,3,4):
			 
			 * 	If you enter a number other than (0,1,2) 
				the program will (display Not a choice.try again, please.)
				and will ask you to enter your choice again and repeat that if you enter 
				a not available choice, until you enter one of the available choices then the program 
				will continue.
				
			*/
			while ( Default_of_select_ClientFeatures )
			{
				
				printf("\n\nNot a choice.try again, please.\n") ;
				
				// To scan the feature you choose from the Admin window.
				select_ClientFeatures = get_int("\nKindly, select the feature number: ") ; 
				
				
			}
		
		
		
			// Switching on the Admin feature choices.
			switch( select_ClientFeatures )
			{
			
			
				// The choice number 1 is Make Transaction.
				case Client_Make_Transaction  	:	vClient_Make_Transaction( )	;	break;
				
				// The choice number 2 is Change Account password.
				case Change_Account_Password	:	vChange_Account_Password( )	;	break;
				
				// The choice number 3 is Get Cash.
				case Client_Get_Cash 		:	vClient_Get_Cash( )		;	break;
				
				// The choice number 4 is Deposit in Account.
				case Client_Deposit_in_Account 	:	vClient_Deposit_in_Account( )	;	break;
				
				// The choice number 0 is exiting from the client window.
				case Return_to_mainMenu 		: 	printf("\nYou exit from the client window\n") ;
			 
			 
			 
			 
				
			}
		 
		 
		 
		 
		 
			// Do that until the client choose to exit from the client window.
		}while( select_ClientFeatures != Return_to_mainMenu );
		
      
	  
		
		
	}
	
	
	else
	{
		
		// Give him two more tries to enter an existent bank account_ID or password.
		vClientWindow_Flag_Check3times( clientWindow_flag );
	 
	}
	
	
	

	
	
}




/*****************************************************************************************************************************************/
/****************************************************************************************************************************************/


/*
 * @Function  name 	:	vClientWindow_Flag_Check3times( int clientWindow_flag ).
 * @Function  info. 	:	Give two more tries to the Client to enter an existent bank account_ID and password. 
 * @Function  input	:	clientWindow_flag.
 * @@Function return	:	None.
 * 
 *
 */
void vClientWindow_Flag_Check3times( int clientWindow_flag )
{
	
	
	
	int i = Iteration_start ; // Is a variable for the second iteration.
	
	int j = Iteration_start ; // Is a variable for the first iteration.
	
	
	// Give him two more tries to enter an existent bank account_ID.
	for ( j = Iteration_start ; j< Twice ; j++ )
	{
		
		printf("\nNot found, Try again\n");
	    
		// To scan the bank account_ID.
		client_bank_ID = get_long_long("\nEnter the bank account_ID of the client account: ")		;
		
		// To scan the bank account password.
		client_password	= get_long_long("\nEnter the bank account password of the client account: ")	;
		
	
		// To iterate on all bank accounts.
		for( i = Iteration_start ; i< accounts_nums ; i++ )
		{
	
			// Check if the input bank account_ID and password is exist.
			if( Correct_ClientbankID_and_password )
			{
				// Assign the account number on the flag.
				clientWindow_flag = i ;
			
				break;
	          
			}
	 
			// if the input bank account_ID or password doesn't exist.
			else
			{
				
				// Assign a negative value on the flag.
				clientWindow_flag = Flag_Incorrect ;
			 
			 
			}
	      
	     
			
		}
		
		
		// If the flag isn't a negative value so the input bank account_ID is exist.
		if ( clientWindow_flag >= Flag_Correct )
		{	
	
			int select_ClientFeatures	= Initialized_by_Zero 	; // Is a variable for scaning the feature number.
	
	
			// Making a menu for the Client features.
			do
			{
	
				printf("\n\n")																								;
				printf("+===========================================================================================+\n")   ;
				printf("|                           Welcome to The \"Client window\"                                  |\n") ;
				printf("+===========================================================================================+\n")   ;
				printf("| 1 | Make Transaction                                                                      |\n")   ;
				printf("|---|---------------------------------------------------------------------------------------|\n")   ;
				printf("| 2 | Change Account Password                                                               |\n") ;
				printf("|---|---------------------------------------------------------------------------------------|\n")   ;
				printf("| 3 | Get Cash                                                               		    |\n")   ;
				printf("|---|---------------------------------------------------------------------------------------|\n")   ;
				printf("| 4 | Deposit in Account                                                               	    |\n")   ;
				printf("|---|---------------------------------------------------------------------------------------|\n")   ;
				printf("| 0 | Return to main Menu                                                                   |\n")   ;
				printf("+===========================================================================================+\n")   ;
		
		
				// To scan the feature number
				select_ClientFeatures = get_int("\nKindly, select the feature number: ") ;
		
				
				/* 
				
				*	To handle entering a number other than the available ones (0,1,2,3,4):
				
				* 	If you enter a number other than (0,1,2) 
					the program will (display Not a choice.try again, please.)
					and will ask you to enter your choice again and repeat that if you enter 
					a not available choice, until you enter one of the available choices then the program 
					will continue.
					
				*/
				while ( Default_of_select_ClientFeatures )
				{
					
					printf("\n\nNot a choice.try again, please.\n") ;
					
					// To scan the feature you choose from the Admin window.
					select_ClientFeatures = get_int("\nKindly, select the feature number: ") ; 
					
					
				}
			
			
			
				// Switching on the Admin feature choices.
				switch( select_ClientFeatures )
				{
				
				
					// The choice number 1 is Make Transaction.
					case Client_Make_Transaction  	:	vClient_Make_Transaction( )		;	break;
					
					// The choice number 2 is Change Account password.
					case Change_Account_Password	:	vChange_Account_Password( )		;	break;
					
					// The choice number 3 is Get Cash.
					case Client_Get_Cash 			:	vClient_Get_Cash( )				;	break;
					
					// The choice number 4 is Deposit in Account.
					case Client_Deposit_in_Account 	:	vClient_Deposit_in_Account( )	;	break;
					
					// The choice number 0 is exiting from the client window.
					case Return_to_mainMenu 		: 	printf("\nYou exit from the client window\n") ;
				 
			     
				}
			
			
			
			
			
				// Do that until the client choose to exit from the client window.
			}while( select_ClientFeatures != Return_to_mainMenu );
			
	
			
	
			break;
		  
		  
	     
	   	}
	  
	 
	 
	 
	 
	}
	
	
	// If he enters a nonexistent bank account_ID for the third time exit from the function.
	if( clientWindow_flag < Flag_Incorrect )
	{
	
	
	
		printf("\nNo more tries\n\n");
		
		
	    
	    
	} 
	
	
	
	
	
	
	
	
	
}





/*****************************************************************************************************************************************/
/****************************************************************************************************************************************/


/*
 * @Function  name 	:	vClient_Make_Transaction( ).
 * @Function  info. 	:	Transfaring amount of money from one account to another. 
 * @Function  input	:	None.
 * @@Function return	:	None.
 * 
 */
void vClient_Make_Transaction( void )
{
	
	
	
	int i 					= Iteration_start 	; // Is a variable for the first iteration.
	
	int amount_of_money 			= Initialized_by_Zero 	; // Is a variable for scaning the amount of money to be transfered.		
	
	int transfered_account_activation	= Initialized_by_Zero	; // Is a variable for checking the status of the transfered account.

	
	
	printf("\n\n\n/*---------------------------------- Make Transaction -----------------------------------*/\n\n");
	
	
	// To scan the bank account_ID.
	transfered_bank_ID = get_long_long("\nEnter the bank account_ID you want to transfer money to: ");
	
	
	// To iterate on all bank accounts.
	for( i = Iteration_start ; i< accounts_nums ; i++ )
	{
		
		// Check if the input bank account_ID is exist.
		if( transfered_bank_ID == bank_account[i].bank_account_ID )
		{
		
			// Assign the account number on the flag.
			client_MakeTransaction_flag = i;
			
			break;
			
		 
		 
		}
		
	
		// if the input bank account_ID doesn't exist.
		else
		{
			// Assign a negative value on the flag.
			client_MakeTransaction_flag = Flag_Incorrect ;
		 
			
		}
		
		
		
		
	}	
	
	
	
	// If the flag isn't a negative value so the input bank account_ID is exist.
	if( client_MakeTransaction_flag >= Flag_Correct )
	{
	
		
		// if the open account is active return 0.
		open_account_activation 	= strcmp( bank_account[clientWindow_flag].account_status 	, "Active" ) 	; 
		
		// if the transfered account is active return 0.
		transfered_account_activation	= strcmp( bank_account[client_MakeTransaction_flag].account_status , "Active" )	;
		
		// if the both accounts is active equal 0.
		active_accounts_checking 	= open_account_activation & transfered_account_activation 			;
		
		// Check if the both accounts is active equal 0.
		if( Equal_strings == active_accounts_checking )
		{
			
			
			// To scan the amount of money to be transfered.
			amount_of_money = get_long_long("\nEnter amount of money to transfer it to the this account: ") ;
		
	
			// To make sure that the amount of money is less than your client’s balance or the transaction won’t be completed.
			if( amount_of_money < bank_account[clientWindow_flag].balance )
			{
				
				// Assign the Client bank_ID that has been entered to the client bank_ID, who wants to transact the money.			
				bank_account[clientWindow_flag].bank_account_ID			= 	client_bank_ID 		;
				
				// Assign the transfered_bank_ID that has been entered to the client bank_ID, who the money will be transfered to.
				bank_account[client_MakeTransaction_flag].bank_account_ID	= 	transfered_bank_ID 	;
				
				// Substracting the amount of money that will be transfered from the client account, who wants to transact the money. 
				bank_account[clientWindow_flag].balance 	    		-= 	amount_of_money 	;
				
				// Adding the amount of money that will be transfered to the client account, who the money will be transfered to.
				bank_account[client_MakeTransaction_flag].balance 		+= 	amount_of_money 	;
				
				
			}
			
			
			//The money is less than your client’s balance, the transaction won’t be completed.
			else
			{
			
				printf("\nThe money is less than your client’s balance, the transaction won’t be completed.") ;
				
				
				
			}
		 
		 
		 
		 
		}
		
		// If the open account or/and the transfered account isn't/aren't Active.
		else
		{
		
			printf("\nThe open account or/and the transfered account isn't/aren't Active.") ;
			
		}
		
      
	 
		
		
	}
	
	// If the flag is a negative value so the input bank account_ID isn't exist.
	else
	{
		// Give him two more tries to enter an existent bank account_ID.
		vClient_Make_Transaction_Flag_Check3times( client_MakeTransaction_flag );
	  
	}
	


	
	
	
}




/*****************************************************************************************************************************************/
/****************************************************************************************************************************************/



/*
 * @Function  name 	:	vClient_Make_Transaction_Flag_Check3times( client_MakeTransaction_flag ).
 * @Function  info. 	:	Give two more tries to the Client to enter an existent bank account_ID. 
 * @Function  input	:	Make_Transaction_flag.
 * @@Function return	:	None.
 * 
 */
void vClient_Make_Transaction_Flag_Check3times( int client_MakeTransaction_flag )
{
	

	int i = Iteration_start ; // Is a variable for the second iteration.
	
	int j = Iteration_start ; // Is a variable for the first iteration.
	
	
	// Give him two more tries to enter an existent bank account_ID.
	for ( j = Iteration_start ; j< Twice ; j++ )
	{
		
		printf("\nNot found, Try again\n");
	    
		// To scan the bank account_ID.
		transfered_bank_ID = get_long_long("\nEnter the bank account_ID of the client account: ") ;
	
	
		// To iterate on all bank accounts.
		for( i = Iteration_start ; i< accounts_nums ; i++ )
		{
	
			// Check if the input bank account_ID is exist.
			if(  transfered_bank_ID == bank_account[i].bank_account_ID )
			{
				// Assign the account number on the flag.
				client_MakeTransaction_flag = i;
			
				break;
	          
			}
	 
			// if the input bank account_ID doesn't exist.
			else
			{
				
				// Assign a negative value on the flag.
				client_MakeTransaction_flag = Flag_Incorrect ;
			 
			 
			}
	      
	     
			
		}
		
		
		// If the flag isn't a negative value so the input bank account_ID is exist.
		if ( client_MakeTransaction_flag >= Flag_Correct )
		{	
			
			
			int amount_of_money 				= Initialized_by_Zero 	; // Is a variable for scaning the amount of money to be transfered.		
	
			int transfered_account_activation	= Initialized_by_Zero	; // Is a variable for checking the status of the transfered account.
			
			
			// if the open account is active return 0.
			open_account_activation 		= strcmp( bank_account[clientWindow_flag].account_status 	, "Active" ) 			; 
			
			// if the transfered account is active return 0.
			transfered_account_activation	= strcmp( bank_account[client_MakeTransaction_flag].account_status 	, "Active" )	;
			
			// if the both accounts is active equal 0.
			active_accounts_checking 		= open_account_activation & transfered_account_activation 							;
			
			// Check if the both accounts is active equal 0.
			if( Equal_strings == active_accounts_checking )
			{
				
				
				// To scan the amount of money to be transfered.
				amount_of_money = get_long_long("\nEnter amount of money to transfer it to the this account: ") ;
			
		
				// To make sure that the amount of money is less than your client’s balance or the transaction won’t be completed.
				if( amount_of_money < bank_account[clientWindow_flag].balance )
				{
					
					// Assign the Client bank_ID that has been entered to the client bank_ID, who wants to transact the money.			
					bank_account[clientWindow_flag].bank_account_ID			= 	client_bank_ID 		;
					
					// Assign the transfered_bank_ID that has been entered to the client bank_ID, who the money will be transfered to.
					bank_account[client_MakeTransaction_flag].bank_account_ID	= 	transfered_bank_ID 	;
					
					// Substracting the amount of money that will be transfered from the client account, who wants to transact the money. 
					bank_account[clientWindow_flag].balance 	    		-= 	amount_of_money 	;
					
					// Adding the amount of money that will be transfered to the client account, who the money will be transfered to.
					bank_account[client_MakeTransaction_flag].balance 		+= 	amount_of_money 	;
					
					
				}
				
				
				//The money is less than your client’s balance, the transaction won’t be completed.
				else
				{
				
					printf("\nThe money is less than your client’s balance, the transaction won’t be completed.") ;
					
					
					
				}
			  
			 
			}
			
			// If the open account or/and the transfered account isn't/aren't Active.
			else
			{
			
				printf("\nThe open account or/and the transfered account isn't/aren't Active.") ;
				
			}
		

	
			break;
		  
		  
	     
	   	}
	  
	 
	 
	 
	 
	}
	
	
	// If he enters a nonexistent bank account_ID for the third time exit from the function.
	if( client_MakeTransaction_flag < Flag_Correct )
	{
	
	
	
		printf("\nNo more tries\n\n");
		
		
	    
	    
	} 
	
	
	




}





/*****************************************************************************************************************************************/
/****************************************************************************************************************************************/


/*
 * @Function  name 	:	vChange_Account_Password( ).
 * @Function  info. 	:	Change Bank Account Password. 
 * @Function  input	:	None.
 * @@Function return	:	None.
 * 
 */
void vChange_Account_Password( void )
{
	
	
	unsigned long long int 	new_AccountPassword 	= Initialized_by_Zero 	; // Is a variable for the old account password.
	
	int 			i 			= Iteration_start 	; // Is a variable for the first iteration.
	
	

	printf("\n\n\n/*---------------------------------- Change Bank Account Password -----------------------------------*/\n\n");
	
	
	
	// To scan the old bank account password.
	old_AccountPassword = get_long_long("\nEnter the old bank account password: ");
	
	
	// To iterate on all bank accounts.
	for( i = Iteration_start ; i< accounts_nums ; i++ )
	{
		
		// Check if the input bank account password is exist.
		if( old_AccountPassword == bank_account[i].password )
		{
		
			// Assign the account number on the flag.
			old_Password_flag = i;
			
			break;
			
		 
		 
		}
		
	
		// if the input bank account password doesn't exist.
		else
		{
			// Assign a negative value on the flag.
			old_Password_flag = Flag_Incorrect ;
		 
			
		}
		
		
		
		
	}	
	
	
	
	// If the flag isn't a negative value so the input bank account password is exist.
	if( old_Password_flag >= Flag_Correct )
	{
	
		// To scan the new account password of the bank account.
		new_AccountPassword = get_long_long("\nEnter the new bank account password: ") ;
		
		
		// In case the new password is token before.
		while( new_AccountPassword == bank_account[i].password )
		{
			
			printf("\nThere's a bank account with the same password, enter another password\n") ;
		
			// To scan the new account password of the bank account.
			new_AccountPassword = get_long_long("\nEnter the new bank account password: ") 	;
			
			
		}
		
		
		// Changing the old password with a new one.
		bank_account[old_Password_flag].password = new_AccountPassword ;
		
		
	}
	
	// If the flag is a negative value so the input bank account_ID isn't exist.
	else
	{
		// Give him two more tries to enter an existent bank account_ID.
		vOld_Password_Flag_Check3times( old_Password_flag );
	  
	}
	
	
	
	

	
	
}





/*****************************************************************************************************************************************/
/****************************************************************************************************************************************/


/*
 * @Function  name 	:	vOld_Password_Flag_Check3times( old_Password_flag ).
 * @Function  info. 	:	Give two more tries to the Client to enter an existent bank account password. 
 * @Function  input	:	old_Password_flag.
 * @@Function return	:	None.
 * 
 */
void vOld_Password_Flag_Check3times( int old_Password_flag )
{
	
	
	
	int i = Iteration_start ; // Is a variable for the second iteration.
	
	int j = Iteration_start ; // Is a variable for the first iteration.
	
	
	// Give him two more tries to enter an existent bank account password.
	for ( j = Iteration_start ; j< Twice ; j++ )
	{
		
		printf("\nNot found, Try again\n")	;
		
	    
		// To scan the old bank account password.
		old_AccountPassword = get_long_long("\nEnter the old bank account password: ");
	
	
		// To iterate on all bank accounts.
		for( i = Iteration_start ; i< accounts_nums ; i++ )
		{
	
			// Check if the input bank account password is exist.
			if( old_AccountPassword == bank_account[i].password )
			{
				// Assign the account number on the flag.
				old_Password_flag = i;
			
				break;
	          
			}
	 
			// if the input bank account password doesn't exist.
			else
			{
				
				// Assign a negative value on the flag.
				old_Password_flag = Flag_Incorrect ;
			 
			 
			}
	      
	     
			
		}
		
		
		// If the flag isn't a negative value so the input bank account password is exist.
		if ( old_Password_flag >= Flag_Correct )
		{	
	
			unsigned long long int 	new_AccountPassword = Initialized_by_Zero 	; // Is a variable for the old account password.
			
			// To scan the new account password of the bank account.
			new_AccountPassword = get_long_long("\nEnter the new bank account password: ") ;
			
			
			// In case the new password is token before.
			while( new_AccountPassword == bank_account[i].password )
			{
				
				printf("\nThere's a bank account with the same password, enter another password\n") ;
			
				// To scan the new account password of the bank account.
				new_AccountPassword = get_long_long("\nEnter the new bank account password: ") 	;
				
				
			}
			
			
			// Changing the old password with a new one.
			bank_account[old_Password_flag].password = new_AccountPassword ;
		
		
	
			break;
		  
		  
	     
	   	}
	  
	 
	 
	 
	 
	}
	
	
	// If he enters a nonexistent bank account password for the third time exit from the function.
	if( old_Password_flag < Flag_Correct )
	{
	
	
	
		printf("\nNo more tries\n\n");
		
		
	    
	    
	} 
	
	
	
	
	
	
	
	
}





/*****************************************************************************************************************************************/
/****************************************************************************************************************************************/


/*
 * @Function  name 	:	vClient_Get_Cash( ).
 * @Function  info. 	:	Get cash from a bank account. 
 * @Function  input	:	None.
 * @@Function return	:	None.
 * 
 */
void vClient_Get_Cash( void )
{



	int cash = Initialized_by_Zero ; // Is a variable for getting cash from the bank account.
	
	

	printf("\n\n\n/*---------------------------------- Get Cash -----------------------------------*/\n\n");


	// if the open account is active return 0.
	open_account_activation = strcmp( bank_account[clientWindow_flag].account_status 	, "Active" ) ;

	// Check if the both accounts is active equal 0.
	if( Equal_strings == open_account_activation )
	{
    
		// To scan the amount of money to be got.
		cash = get_int("\nEnter the cash amount you want from this account: ") ;
    
    	// To make sure that the amount of money is less than your client’s balance or the transaction won’t be completed.
    	if( cash < bank_account[clientWindow_flag].balance )
    	{
    		
    		// Assign the Client bank_ID that has been entered to the client bank_ID, who wants to transact the money.			
    		bank_account[clientWindow_flag].bank_account_ID	= 	client_bank_ID	;
    	
    		
    		// Substracting the amount of money that will be taken from the client account, who wants to get the money. 
    		bank_account[clientWindow_flag].balance 	    -= 	cash 			;
    		
    		
    	}
    	
    	
    	//The money is less than your client’s balance, the transaction won’t be completed.
    	else
    	{
    	
    		printf("\nThe money is less than your client’s balance, the transaction won’t be completed.") ;
    		
    		
    		
    	}
     
     
     
     
    }
    
    // If the open account isn't Active.
    else
    {
    
    	printf("\nThe open account isn't Active.") ;
    	
    }
	




}



/*****************************************************************************************************************************************/
/****************************************************************************************************************************************/


/*
 * @Function  name 	:	vClient_Deposit_in_Account( ).
 * @Function  info. 	:	Add cash to a bank account. 
 * @Function  input	:	None.
 * @@Function return	:	None.
 * 
 */
void vClient_Deposit_in_Account( void )
{



	int add_cash = Initialized_by_Zero ; // Is a variable for adding cash to a bank account.
	
	
	
	printf("\n\n\n/*---------------------------------- Deposit in Account -----------------------------------*/\n\n");
	
	
	// if the open account is active return 0.
	open_account_activation = strcmp( bank_account[clientWindow_flag].account_status 	, "Active" ) ;
	
	// Check if the both accounts is active equal 0.
	if( Equal_strings == open_account_activation )
	{

		// To scan the amount of money to be deposited.
		add_cash = get_int("\nEnter the cash amount you want to add to this account: ") ;
		
		// Assign the open_bank_ID that has been entered to the client bank_ID, who wants to transact the money.			
		bank_account[clientWindow_flag].bank_account_ID	= 	client_bank_ID 	;
		
		
		// Substracting the amount of money that will be taken from the client account, who wants to get the money. 
		bank_account[clientWindow_flag].balance 	    += 	add_cash 	 	;
		
		
	}
	
	// If the open account isn't Active.
	else
	{
	
		printf("\nThe open account isn't Active.") ;
		
	}
	

	
	


}




/*****************************************************************************************************************************************/
/****************************************************************************************************************************************/
