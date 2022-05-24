/*
 * @file 		Bank_config.h
 * @author 		Ali El_bana (alitheboss922@gmail.com)
 * @brief 
 * @version 	0.1
 * @date 		2022-04-17
 * 
 * @copyright 	Copyright (c) 2022
 * 
 */



#ifndef _Bank_config_H
#define _Bank_config_H






	/*------------------------------------------------The main Macros----------------------------------------------------*/

	// Is a macro for defining the maximum numbers of bank accounts you want to enter.
	#define Max_Accounts				1000
	
	// Is a macro for defining the maximum character numbers of client name you want to enter.
	#define Max_name_chars	 			150
	
	// Is a macro for defining the minimum character numbers of client name.
	#define Min_name_chars	 			15
	
	// Is a macro for defining the minimum alphabet numbers of client name.
	#define Min_name_alphabets	 		12
	
	// Is a macro for defining the maximum numbers in the client name.
	#define Max_name_nums	 			0
	
	// Is a macro for defining the minimum number of spaces in the client name.
	#define Min_name_spaces	 			3
	
	// Is a macro for defining the maximum special characters in the client name.
	#define Max_name_special_char		0
	
	// Is a macro for defining the minimum character numbers of client address.
	#define Min_address_chars			15
	
	// Is a macro for defining the maximum character numbers of bank account status you want to enter.
	#define Max_Status_chars 			10
	
	// Is a macro for defining the starting value of the iteration variable.
	#define Iteration_start				0
	
	// Is a macro for defining the defualt lower limit password of the bank account.
	#define Password_lower_limit 		1000000000
	
	// Is a macro for defining the defualt upper limit password of the bank account.
	#define Password_upper_limit 		9999999999
	
	// Is a macro for defining the last limit of defualt passwords and bank_IDs.
	#define The_last_limit 				1
	
	// Is a macro for defining the defualt lower limit bank account_ID of the bank account.
	#define Bank_account_ID_lower_limit 2081200000
	
	// Is a macro for defining the defualt upper limit bank account_ID of the bank account.
	#define Bank_account_ID_upper_limit 2081209999
	
	// Is a macro for defining the minor age of the client.
	#define Minor_age 					21
	
	// Is a macro for defining the the ending character of the client name string.
	#define	Null						'\0'
	
	// Is a macro for empty the name_alphabet, name_nums, spaces_in_name and name_special_char counters.
	#define Empty_name_counters 		s = name_alphabet = name_nums = spaces_in_name = name_special_char = Initialized_by_Zero
	
	// Is a macro for defining the twice repeataions of the block of code inside the iteration.
	#define Twice						2
	
	// Is a macro for defining the digit unit of a number.
	#define Digit_unit					10

	// Is a macro for defining the end of counting digits operation.
	#define End_of_CoutingDigits		0
	
	// Is a macro for defining the number of national_ID digits.
	#define Digits_of_national_ID 		14
	
	// Is a macro for defining the incorrect value of the flag.
	#define Flag_Incorrect				-1
	
	// Is a macro for defining the correct value of the flag.
	#define Flag_Correct				0
	

	/*--------------------------------The choices part of the Admin Window-------------------------------------*/
	
	// Is a macro for defining the Exit from Admin Window choice number of the Admin Window choices.
	#define Exit_AdminWindow		0

	// Is a macro for defining the Create Bank Accounts choice number of the Admin Window choices.
	#define Create_BankAccounts		1
	
	// Is a macro for defining the Open Existing Account choice number of the Admin Window choices.
	#define Open_ExistingAccount	2
	
	

	/*---------------------------The choices part of the Open Existing Account Menu----------------------------*/
	
	// Is a macro for defining the Make Transaction choice number of the Open Existing Account Menu.
	#define Make_Transaction 		1
	
    // Is a macro for defining the Change Account Status choice number of the Open Existing Account Menu.
    #define Change_Account_Status	2
    
	// Is a macro for defining the Get Cash choice number of the Open Existing Account Menu.
    #define Get_Cash				3
    
	// Is a macro for defining the Deposit in Account choice number of the Open Existing Account Menu.
    #define Deposit_in_Account		4

	// Is a macro for defining the Return to main Menu choice number of the Open Existing Account Menu.
	#define Return_to_mainMenu		0



	/*--------------------------------The choices part of Change Bank Account Status----------------------------*/
	
	// Is a macro for defining the Active State choice number of the Change Bank Account Status choices.
	#define Active_State		1
	
	// Is a macro for defining the Closed State choice number of the Change Bank Account Status choices.
	#define Closed_State 		2
	
	// Is a macro for defining the Restricted State choice number of the Change Bank Account Status choices.
	#define Restricted_State	3
	
	
	
	/*---------------------------------The choices part of the Client Window-----------------------------------*/
	
	// Is a macro for defining the Make Transaction choice number of the Client Window choices.
	#define Client_Make_Transaction 	1
    
	// Is a macro for defining the Change Account Password choice number of the Client Window choices.
    #define Change_Account_Password		2
    
	// Is a macro for defining the Get Cash choice number of the Client Window choices.
    #define Client_Get_Cash				3
    
	// Is a macro for defining the Deposit in Account choice number of the Client Window choices.
    #define Client_Deposit_in_Account	4

	
	
	/*--------------------------------------------------------------------The Conditional Macros-----------------------------------------------------------------------------*/
	
	// Is a macro for a condition when there's a bank account with the same national_ID. 
	#define Same_national_ID								(bank_account[i].national_ID == bank_account[j].national_ID)
	
	// Is a macro for a condition when the user selects a number other than the available ones (0,1,2).
	#define Default_of_select_AdminFeatures					( (select_AdminFeatures !=  1 ) && ( select_AdminFeatures !=  2 ) && ( select_AdminFeatures !=  0 ) )

	// Is a macro for a condition when the user selects a number other than the available ones (0,1,2,3,4).
	#define Default_of_select_Open_ExistingAccount_Menu 	( (select_Open_ExistingAccount_Menu !=  1 ) && ( select_Open_ExistingAccount_Menu !=  2 ) && ( select_Open_ExistingAccount_Menu !=  3 ) && ( select_Open_ExistingAccount_Menu !=  4 ) && ( select_Open_ExistingAccount_Menu !=  0 ) )
	
	// Is a macro for a condition when the user selects a number other than the available ones (1,2,3).
	#define Default_of_select_AccountStatus					( (select_AccountStatus !=  1 ) && ( select_AccountStatus !=  2 ) && ( select_AccountStatus !=  3 ) )

	// Is a macro for checking that the client enters the correct bank_ID and password.
	#define	Correct_ClientbankID_and_password				( (client_bank_ID == bank_account[i].bank_account_ID) && (client_password == bank_account[i].password) )
	
	// Is a macro for a condition when the user selects a number other than the available ones (0,1,2,3,4).
	#define Default_of_select_ClientFeatures 				( (select_ClientFeatures !=  1 ) && ( select_ClientFeatures !=  2 ) && ( select_ClientFeatures !=  3 ) && ( select_ClientFeatures !=  4 ) && ( select_ClientFeatures !=  0 ) )
	
	// Is a macro for couting the alphabets in the client name.
	#define BankAccountNameContains_Alphabets				( (bank_account[i].name[s] >= 'a' && bank_account[i].name[s] <= 'z') || (bank_account[i].name[s] >= 'A' && bank_account[i].name[s] <= 'Z') )
    
	// Is a macro for couting the numbers in the client name.
    #define BankAccountNameContains_Numbers  				( (bank_account[i].name[s] >= '0') && (bank_account[i].name[s] <= '9') )
    
	// Is a macro for couting the spaces in the client name.
    #define BankAccountNameContains_Spaces               	(bank_account[i].name[s] == ' ')

	









#endif