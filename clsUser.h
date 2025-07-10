#pragma once
#include<iostream>  
#include<string>  
#include"clsPerson.h"  
#include"clsString.h" 
#include"clsUtil.h"	 
#include<vector>
#include"clsDate.h"	 
#include"fstream"  



using namespace std;  

class clsUser : public clsPerson
{


private :  
	 enum enMode {EmptyMode = 0, UpdateMode = 1 , AddNewMode = 2 };

	 enMode _Mode; 
	 string _UserName;  
	 string _PassWord;  
	 int _Permissions; 
	 

	 bool _MarkToDelete = false; 

	
	 struct stLoginRegisterRecord;
	 static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
	 {
		 stLoginRegisterRecord LoginRegisterRecord;


		 vector <string> LoginRegisterDataLine = clsString::Split(Line, Seperator);
		 LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
		 LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
		 LoginRegisterRecord.PassWord =clsUtil::DecryptText(LoginRegisterDataLine[2]);
		 LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);

		 return LoginRegisterRecord;

	 }

	 static clsUser _ConvertLineToRecordUser(string Line, string Seperator = "#//#")
	 {

		 vector<string> vClientData;
		 vClientData = clsString::Split(Line, Seperator);


		 return clsUser(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
			 vClientData[3], vClientData[4], clsUtil::DecryptText(vClientData[5]), stod(vClientData[6]));

	 }

	 string _PrepareLoginInRecord(string Seperator = "#//#")
	 {
		 string LoginRecord = ""; 

		 LoginRecord += clsDate::GetSystemDateTimeString() + Seperator; 
		 LoginRecord += UserName + Seperator; 
		 LoginRecord += clsUtil::EncryptText( PassWord) + Seperator;  
		 LoginRecord += to_string(Permissions); 

		 return LoginRecord; 
	 }

	 static clsUser _GetEmptyUser()
	 {
		 return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	 }


	 static string _ConverUserObjectToLine(clsUser  User, string Seperator = "#//#")
	 {

		 string stUserRecord = "";
		 stUserRecord += User.FirstName + Seperator;
		 stUserRecord += User.LastName + Seperator;
		 stUserRecord += User.Email +  Seperator;
		 stUserRecord += User.Phone + Seperator;
		 stUserRecord += User.UserName + Seperator;
		 stUserRecord +=clsUtil::EncryptText( User.PassWord) + Seperator;
		 stUserRecord += to_string(User.Permissions);

		 return stUserRecord;

	 }

	

	 static vector<clsUser> _LoadUserDataFromFile()
	 {
		 vector<clsUser> vUser;
		 fstream MyFile;
		 MyFile.open("Users.txt", ios::in);

		 if (MyFile.is_open())
		 {
			 string Line;

			 while (getline(MyFile, Line))
			 {
				 clsUser User = _ConvertLineToRecordUser(Line);
				 vUser.push_back(User);
			 }
			 MyFile.close();
		 }
		 return vUser;
	 }

	 static void _SaveUserDataToFile(vector<clsUser>vUser)
	 {
		 fstream MyFile;
		 MyFile.open("Users.txt", ios::out);//overwrite

		 string DataLine;

		 if (MyFile.is_open())
		 {

			 for (clsUser U : vUser)
			 {
				 if (U._MarkToDelete == false)
				 {

					 DataLine = _ConverUserObjectToLine(U);
					 MyFile << DataLine << endl;
				 }
			 }

			 MyFile.close();

		 }
	 }
	
	

			 
	
	

	 void _Update()
	 {
		 vector<clsUser> _vUser;
		 _vUser = _LoadUserDataFromFile();

		 for (clsUser& U : _vUser)
		 {
			 if (U.UserName == UserName)
			 {
				 U = *this;
				 break;
			 }
		 }
		 _SaveUserDataToFile(_vUser);
	 }

	 void _AddDataLineToFile(string  stDataLine)
	 {
		 fstream MyFile;
		 MyFile.open("Clients.txt", ios::out | ios::app);

		 if (MyFile.is_open())
		 {

			 MyFile << stDataLine << endl;

			 MyFile.close();
		 }
	 }

	 void _AddNew()
	 {
		 _AddDataLineToFile(_ConverUserObjectToLine(*this)); 
	 }


public :  

	struct stLoginRegisterRecord;
	enum enPermissions {
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClients = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64	 ,
		pShowLoginRegister  =128
	};

	struct stLoginRegisterRecord {
		string DateTime;
		string UserName;
		string PassWord; 
		int Permissions;

	};
	clsUser(enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string UserName, string PassWord,
		int Permissions) : clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode; 
		_UserName = UserName;  
		_PassWord = PassWord; 
		_Permissions = Permissions; 
	}

	

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
	bool MarkedForDeleted()
	{
		return _MarkToDelete; 
	}
	
	void SetUserName(string UserName)
	{
		_UserName = UserName; 
	}
	string GetUserName()
	{
		return _UserName; 
	}

	__declspec(property(get = GetUserName, put = SetUserName))string UserName; 

	void SetPassWord(string PassWord)
	{
		_PassWord = PassWord; 
	}
	string GetPassWord()
	{
		return _PassWord; 
	}
	__declspec(property(get = GetPassWord, put = SetPassWord))string PassWord;
	void SetPermissions(int Permissions) {
		_Permissions = Permissions; 
	}
	int GetPermissions()
	{
		return _Permissions; 
	}
	__declspec(property(get = GetPermissions, put = SetPermissions))int Permissions;  
	string FullName()
	{
		return FirstName + " "+ LastName;
	}

	static clsUser Find(string UserName)
	{
		fstream MyFile; 
		MyFile.open("Users.txt", ios::in); 

		if (MyFile.is_open())
		{
			string Line;   
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToRecordUser(Line); 
				if (User.UserName == UserName)
				{
					MyFile.close(); 
					return User; 
				}

			}
			MyFile.close(); 
		}

		return 	 _GetEmptyUser(); 
	}


	static clsUser Find(string UserName, string PassWord)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToRecordUser(Line);
				if (User.UserName == UserName && User.PassWord == PassWord)
				{
					MyFile.close();
					return User;
				}

			}
			MyFile.close();
		}

		return 	 _GetEmptyUser();
	}

	static bool IsUserExist(string UserName)
	{
		clsUser User = clsUser::Find(UserName); 
		
		return (!User.IsEmpty()); ; 
	}
	bool Delete()
	{
		vector<clsUser> vUser = _LoadUserDataFromFile(); 
		for (clsUser& User : vUser)
		{
			if (User.UserName == _UserName)
			{
				User._MarkToDelete = true; 
				break; 
			}
		}
		_SaveUserDataToFile(vUser);  

		*this = _GetEmptyUser(); 
		return true; 
	}

	static vector<clsUser> GetUsersList()
	{
		return _LoadUserDataFromFile(); 
	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName,"", 0);
	}

	bool CheckAccessPermissions(enPermissions Permissions)
	{
		if (this->Permissions == enPermissions::eAll)
			return true; 

		 if ((Permissions & this->Permissions) == Permissions)
		return true;

		else
			return false; 
	}
	

	void RegisterLogin()
	{
		string stDataLine = _PrepareLoginInRecord();  

		fstream MyFile;  
		MyFile.open("LoginFile.txt", ios::out | ios::app); 

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl; 
			MyFile.close();  
		}


	}
	static  vector <stLoginRegisterRecord> GetLoginRegisterList()
	{
		vector <stLoginRegisterRecord> vLoginRegisterRecord;

		fstream MyFile;
		MyFile.open("LoginFile.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;

			stLoginRegisterRecord LoginRegisterRecord;

			while (getline(MyFile, Line))
			{

				LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);

				vLoginRegisterRecord.push_back(LoginRegisterRecord);

			}

			MyFile.close();

		}

		return vLoginRegisterRecord;

	}

	enum enSaveResult{svFailedEmptyObject= 0 , svSucceeded= 1 , svFailedUserExist};

	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode  :
		{
			if (IsEmpty())
			{
				return enSaveResult::svFailedEmptyObject; 
			}
		}
		case enMode::UpdateMode  : 
		{
			_Update(); 
			return enSaveResult::svSucceeded; 
			break; 
		}
		case enMode::AddNewMode : 
		{
			if (clsUser::IsUserExist(_UserName))
			{
				return enSaveResult::svFailedUserExist;
			}
			else
			{
				_AddNew();  

				_Mode = enMode::UpdateMode; 
				return enSaveResult::svSucceeded; 
			}
			break;  
		}
		
		}
	}
	
};

