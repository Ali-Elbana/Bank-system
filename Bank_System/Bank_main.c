/*
 * @file 		Bank_main.c
 * @author 		Ali El_bana (alitheboss922@gmail.com)
 * @brief 
 * @version 	0.1
 * @date 		2022-04-17
 * 
 * @copyright 	Copyright (c) 2022
 * 
 */



/*

 * Note that: I'am using a CS50 library for handling the disadvantages of the scanf function.

 * So, I put this library in my compiler libraries file and include it as a standard refrence.
 
 * If you want to run this code take the CS50 library files and include them as a relative refrences in the Bank_main.c and Bank_program.c files,
   instead of my standard refrences or put them in your compiler libraries file and leave my refrences as they are.

 */


#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

#include "LSTD_TYPES.h"
#include "Bank_interface.h"




void main ( void )
{
	
	/* Is a function from stdlib.h to clear the console screen */
	system( "cls" ) ;
	
	
	int 	select_window 		=  	Initialized_by_Zero  	; 	// Is a variable to select from the windows of the system.
	
	int 	admin_pass    		=  	Initialized_by_Zero  	;	// Is a variable for taking a password from the admin.
	
	string 	admin_name 			=  	NULL 					; 	// Is a string for taking the user name of the admin.
	
	int 	check_admin_name	=	Initialized_by_Zero		;	// Is a varaible to check on the admin username (if correct = 0) (else =1).		
	
	
	
	// Making a window for the Bank system.
	do
	{
		
		
		
		/* To display the main available windows of the Bank system */
		vDisp_mainWindow( ) ;
		
	
		
		/* To scan the window you choose from the main windows of the Bank system */
		select_window = get_int("\nKindly, select the window number: ") ;
		
		
		/* 
		
		 * To handle entering a number other than the available ones (0,1,2):
		 
		 * If you enter a number other than (0,1,2) 
		 the program will (display Not a choice.try again, please.)
		 and will ask you to enter your choice again and repeat that if you enter 
		 a not available choice, until you enter one of the available choices then the program 
		 will continue.
			
		*/
		while ( Default_of_select_window )
		{
			
			printf("\n\nNot a choice.try again, please.\n") ;
			
			/* To scan the window you choose from the main windows of the Bank system */
			select_window = get_int("\nKindly, select the window number: ") ; 
			
			
		}
		
	
	
	
		/* To switch on your selection from the main windows */
		switch( select_window )
		{
			
			
			/*--------------------------------------Admin window-----------------------------------------*/
			
			
			
			/* The Admin window */ 
			case Admin :
			
			/* To scan the Admin username */
			admin_name = get_string("\nEnter the Admin username: ") ;
			
			
			/* To scan the Admin password */
			admin_pass = get_int("\nEnter the Admin password: ") 	;
			
		
			/* To check on the admin username (if correct return 0) (else return 1) */
			check_admin_name = strcmp( Correct_AdminUsername , admin_name ) ;
		
		
		
			/* Check if the admin username and password is correct to get the features of the admin window */
			if( Correct_AdminUsername_and_pass )
			{
			
				/* Select the features of the Admin window */
				vAdmin_windowFeatures( );
				
			}
		
			
			
			else
			{
			
				/* Give two more tries to the Admin to enter the correct username and password */
				vAdminUsername_and_Pass_Check3times( admin_name , admin_pass , check_admin_name ) ;
				
			}
			
	
			
			break ;
			
			
			
			
			
			
			/*--------------------------------------Client window-----------------------------------------*/
			
	
			case Client :
			
			
			
			/*Select the features of the client window.*/
			vClient_windowFeatures( );
			
	
			
			break ;
			
	
			
			/*--------------------------------------Exit from the main window-----------------------------------------*/
			
			
	
			case Exit:
			
			
			printf("\n\nThe program has been implemented\n")		;
			
			printf("\nYou now signed out from the Bank System\n") 	;
			
			/* Is a function from stdlib.h to terminate the program */
			exit( Exit ) ;
			
			
			
			break ;
			
			

			
			/*--------------------------------------The End of Switch-----------------------------------------*/
		 
			
		}	
		
		
		
		
		
		
		// Do that until the user choose to exit from the Bank system window.
	}while( select_window != Exit ) ;
	

	
	
	
	
}