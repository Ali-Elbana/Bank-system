/*
 * @file 		Bank_interface.h
 * @author 		Ali El_bana (alitheboss922@gmail.com)
 * @brief 
 * @version 	0.1
 * @date 		2022-04-17
 * 
 * @copyright 	Copyright (c) 2022
 * 
 */




#ifndef _Bank_interface_H
#define _Bank_interface_H




#include <stdio.h>

#include "Bank_private.h"




	/*------------------------------------------------The main Macros---------------------------------------------------------*/
	
	// Is a macro for defining the Admin choice number of the Bank Systen Window choices.
	#define Admin  						1
	
	// Is a macro for defining the Client choice number of the Bank Systen Window choices.
	#define Client 						2
	
	// Is a macro for defining the Admin choice number of the Bank Systen Window choices.
	#define Exit   						0
	
	// Is a macro for defining the Admin password.
	#define Correct_AdminPass 			_AdminPass
	
	// Is a macro for defining the Admin username.
	#define Correct_AdminUsername 		_AdminUsername
	
	// Is a macro for defining that the compared strings are the same.
	#define Equal_strings 				0 
	
	// Is a macro for defining the initialized value of the variables.
	#define Initialized_by_Zero			0
	
	
	/*------------------------------------------------The Conditional Macros---------------------------------------------------------*/
	
	// Is a macro for a condition when the user selects a number other than the available ones (0,1,2).
	#define Default_of_select_window		( (select_window !=  1 ) && ( select_window !=  2 ) && ( select_window !=  0 ) )
	
	// Is a macro for checking that the Admin enters the correct Admin Username and password.
	#define	Correct_AdminUsername_and_pass	( (Correct_AdminPass == admin_pass) && (check_admin_name == Equal_strings) )
	
	// Is a macro for checking that the Admin doesn't enter the correct Admin Username and password.
	#define	Incorrect_AdminUsername_or_pass	( (Correct_AdminPass != admin_pass) || (check_admin_name != Equal_strings) )
	


	/*---------------------------------------------The fuctions prototype part------------------------------------------------*/

	/* @Function  info. : Display the main available windows of the Bank system. */
	void vDisp_mainWindow( void )			;
	
	/* @Function  info. : Select the features of the Admin window. */
	void vAdmin_windowFeatures( void ) 		;

	/* @Function  info. : Give two more tries to the Admin to enter the correct username and password. */
	void vAdminUsername_and_Pass_Check3times( string admin_name , int admin_pass , int check_admin_name  ) 	;
	
	/* @Function  info. : Create bank_accounts. */
	void vCreate_New_Account(void)			;
	
	/* @Function  info. : Open the existing accounts and make operations. */
	void vOpen_ExistingAccount( void )		;
	
	/* @Function  info. : Select the features of the Open Existing Account Menu. */
	void vOpen_ExistingAccount_Menu( void )	;

	/* @Function  info. : Give two more tries to the Admin to enter an existent bank account_ID. */
	void vOpen_ExistingAccount_Flag_Check3times( int OpenExistingAccount_flag ) 							;

	/* @Function  info. : Transfaring amount of money from one account to another. */ 
	void vMake_Transaction( void )			;

	/* @Function  info. : Give two more tries to the Admin to enter an existent bank account_ID. */
	void vMake_Transaction_Flag_Check3times( int MakeTransaction_flag )										;

	/* @Function  info. : Change Bank Account Status. */
	void vChange_Account_Status( void )		;

	/* @Function  info. : Get cash from a bank account. */
	void vGet_Cash( void )					;

	/* @Function  info. : Add cash to a bank account. */
	void vDeposit_in_Account( void )		;

	/* @Function  info. : Select the features of the client window.*/
	void vClient_windowFeatures( void )		;
	
	/* @Function  info. : Give two more tries to the Client to enter an existent bank account_ID and password. */
	void vClientWindow_Flag_Check3times( int clientWindow_flag )											;
	
	/* @Function  info. : Transfaring amount of money from one account to another. */
	void vClient_Make_Transaction( void )	;

	/* @Function  info. : Give two more tries to the Admin to enter an existent bank account_ID. */
	void vClient_Make_Transaction_Flag_Check3times( int client_MakeTransaction_flag )						;

	/* @Function  info. : Change Bank Account Password. */
	void vChange_Account_Password( void )	;

	/* @Function  info. : Give two more tries to the Client to enter an existent bank account password. */
	void vOld_Password_Flag_Check3times( int old_Password_flag )											;

	/* @Function  info. : Get cash from a bank account. */
	void vClient_Get_Cash( void )			;

	/* @Function  info. : Add cash to a bank account. */
	void vClient_Deposit_in_Account( void ) ;

	





#endif