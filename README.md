# Bank-system
Bank system (C project). 

This project consist of 2 main features
1- Admin Window.
2- Client Window.

Bank Account Bank Account must include those information:

- Full Name.
You must enter at least first four names ex: Mohamed Salah Hamed Mahrous

- Full Address.
ex: 6 Hussien Wassef, F rom El-Dokki st , G i z a .

- National ID.
You must enter National ID which consist of 14 digit Number ex: 29805070100179

- Age
ex: 25

- Bank Account ID
Bank Account ID must be generated automatically(10 digit) ex: 1000000000

- Guardian
In case of user is less than 21 he must have a guardian

- Guardian National ID.
You must enter National ID which consist of 14 digit Number ex: 29805070100179

- Account Status.
By default Account Status is Active, but it can be also (Restricted or Closed)
Note: If account is Restricted or Closed you can’t perform any action on it

- Balance.
ex: 75000

- Password.
Random Password will be generated for each account during creation of it.

Admin Window:
To Enter this Window, Admin must use correct Username and Password.
In this window Admin can perform the following actions:

1- Create New Account
In this Feature you will be asked to enter the following parameters
- Full Name
- Full Address
- Age
- National ID
- Guardian National ID
(If Age < 21 you will be asked automatically for Guardian National ID)
- Balance
Note that (Password, and Bank account ID will be generated automatically)
Note also that the account status will be active once it is created.

2- Open Existing Account
In this Feature you will be asked to enter Client Bank Account ID then
choose between the following features:

- Make Transaction
In this feature you will be asked to enter the Bank Account ID you want to
transfer money to. Then you will be asked to enter amount of money to
transfer it to the this account.
You have to make sure that the amount of money is less than your client’s
balance or the transaction won’t be completed.
You have to make sure that both accounts are Active.

- Change Account Status
In this feature you will be asked to enter the Bank Account Status, you want for
this account
1- Set Account to Active State
2- Set Account to Restricted State
3- Set Account to Closed

- Get Cash
In this feature you will be asked to enter the cash amount you want from
this account and it will be reduced from your account balance.
make sure the cash amount is less than the account balance before
performing this feature.

- Deposit in Account
In this feature you will be asked to enter the cash amount you want to add
to this account.
- Return to main menu
In this feature you will return to Admin Main Menu
3- Exit the System
In this Feature you Admin menu will be terminated



Client Window
To Enter this Window, Client must use correct Bank Account ID and Password.
In this window Client can perform the following actions:

- Make Transaction
In this feature you will be asked to enter the Bank Account ID you want to
transfer money to. Then you will be asked to enter amount of money to
transfer it to the this account.
You have to make sure that the amount of money is less than your client’s
balance or the transaction won’t be completed.
If one Account is Restricted or Closed you won’t be able to perform
this transaction.

- Change Account Password
In this feature client will be able to change his password by entering old
password then the new password

- Get Cash
In this feature you will be asked to enter the cash amount you want from
this account and it will be reduced from your account balance.
make sure the cash amount is less than the account balance before
performing this feature.

- Deposit in Account
In this feature you will be asked to enter the cash amount you want to add
to this account

- Return to main menu
In this feature you will return to Admin Main Menu.





