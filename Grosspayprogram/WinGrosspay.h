#include "stdafx.h"
#include "OOPClass.h"
#include "afxwin.h"
#include <afxdb.h>
#include <time.h>
#include <cstdlib>
#include <exception>
#include <atltime.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


namespace Grosspayprogram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::IO;
	using namespace System::Runtime::Serialization;
	using namespace System::Runtime::Serialization::Formatters::Binary;
	/// <summary>
	/// Summary for WinGrosspay
	/// </summary>
	public ref class WinGrosspay : public System::Windows::Forms::Form
	{
	public:
		WinGrosspay(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~WinGrosspay()
		{
			if (components)
			{
				delete components;
			}
		}

	private:


		static CObList * itemlist = new CObList;


		InventoryCostClass * itempa2;
		InventoryCostClass  * itempa3;


		 


	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  txtsearch;


	private: System::Windows::Forms::ListBox^  lstData;
	private: System::Windows::Forms::PictureBox^  pic;

	private: System::Windows::Forms::Button^  cmdsearch2;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openDatabaseToolStripMenuItem;

		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtsearch = (gcnew System::Windows::Forms::TextBox());
			this->lstData = (gcnew System::Windows::Forms::ListBox());
			this->pic = (gcnew System::Windows::Forms::PictureBox());
			this->cmdsearch2 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openDatabaseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(85, 74);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(105, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Search Value";
			// 
			// txtsearch
			// 
			this->txtsearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->txtsearch->Location = System::Drawing::Point(205, 68);
			this->txtsearch->Name = L"txtsearch";
			this->txtsearch->Size = System::Drawing::Size(100, 26);
			this->txtsearch->TabIndex = 1;
			// 
			// lstData
			// 
			this->lstData->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lstData->FormattingEnabled = true;
			this->lstData->ItemHeight = 18;
			this->lstData->Location = System::Drawing::Point(12, 148);
			this->lstData->Name = L"lstData";
			this->lstData->Size = System::Drawing::Size(868, 40);
			this->lstData->TabIndex = 3;
			// 
			// pic
			// 
			this->pic->Location = System::Drawing::Point(292, 297);
			this->pic->Name = L"pic";
			this->pic->Size = System::Drawing::Size(100, 50);
			this->pic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pic->TabIndex = 4;
			this->pic->TabStop = false;
			// 
			// cmdsearch2
			// 
			this->cmdsearch2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->cmdsearch2->Location = System::Drawing::Point(343, 74);
			this->cmdsearch2->Name = L"cmdsearch2";
			this->cmdsearch2->Size = System::Drawing::Size(90, 29);
			this->cmdsearch2->TabIndex = 5;
			this->cmdsearch2->Text = L"Search";
			this->cmdsearch2->UseVisualStyleBackColor = true;
			this->cmdsearch2->Click += gcnew System::EventHandler(this, &WinGrosspay::cmdsearch2_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->fileToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(933, 29);
			this->menuStrip1->TabIndex = 6;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->openDatabaseToolStripMenuItem});
			this->fileToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(46, 25);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openDatabaseToolStripMenuItem
			// 
			this->openDatabaseToolStripMenuItem->Name = L"openDatabaseToolStripMenuItem";
			this->openDatabaseToolStripMenuItem->Size = System::Drawing::Size(186, 26);
			this->openDatabaseToolStripMenuItem->Text = L"Open Database";
			this->openDatabaseToolStripMenuItem->Click += gcnew System::EventHandler(this, &WinGrosspay::openDatabaseToolStripMenuItem_Click);
			// 
			// WinGrosspay
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(933, 594);
			this->Controls->Add(this->cmdsearch2);
			this->Controls->Add(this->pic);
			this->Controls->Add(this->lstData);
			this->Controls->Add(this->txtsearch);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"WinGrosspay";
			this->Text = L"Binary Search";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pic))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	 
	
private: System::Void cmdsearch2_Click(System::Object^  sender, System::EventArgs^  e) 
 {

			 String ^ fmtStr1 = "{0,-6}{1, 11}{2, 12}{3, 9}{4,9}{5, 12}";
	String ^ fmtStr2 = "{0, -15}";


			 CString search = txtsearch->Text;



		int id, department, quantity, amount;
		CString  item, category,  picture;
		 double  unitcost, inventorycost;
		int key;
			 
      
 key = itempa2->binarysearch(itemlist, search);
 if (key > -1)
 {
	itempa2->getdata(id, item, department, quantity, unitcost, inventorycost, picture, key, itemlist);

     TCHAR *  sname = item.GetBuffer(0);
       String ^ sitem  = gcnew String (sname); 


       sname = picture.GetBuffer(0);
      String ^ kpicture = gcnew String (sname);

	lstData->Items->Add(String::Format(fmtStr1, id, sitem, department, quantity, unitcost, inventorycost));


       Bitmap^ image1;
	String ^   fileToDisplay;

	String ^  kpicture2= "C:\\VisualStudio\\Final\\DataBaseswithImages\\DataBaseswithImages\\InventoryCost\\images\\";
	fileToDisplay = kpicture2 + kpicture;

	                   try
                          {
                              // Retrieve the image.
                              image1 = gcnew Bitmap( fileToDisplay ,true );
         
                               pic->AutoSize=false;
                              // Set the PictureBox to display the image.
                               pic->Image = image1;
 
                           }
                           catch ( ArgumentException^ ) 
                           {

							    
                                  MessageBox::Show( "There was an error."
                                   "Check the path to the image file." );
                            }


		 }

     }
private: System::Void openDatabaseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs ^ e)
{
	using namespace System::IO;

	CString Connection;
	CDatabase database;
	
	CString username;
	CString password;

	username = "MSI\\SQLSERVEREXPRESS\\Vincent Bui";

	Connection = _T("Driver={SQL Server Native Client 11.0};Server=MSI\\SQLSERVEREXPRESS;AttachDbFilename=C:\\VisualStudio\\Final\\DataBaseswithImages\\DataBaseswithImages\\InventoryCost\\CategoryDB\\InventorySQL.mdf;Trusted_Connection=Yes;Uid=") + username + _T(";Pwd=") + password + _T(";");
	

	database.OpenEx(Connection, CDatabase::useCursorLib);

	CString thestring;

	CString query = "SELECT ID, Item, Department, Quantity, UnitCost, Amount, Pictures FROM Items";

	CRecordset recordset(&database);
	CString temp, record;
	recordset.Open(CRecordset::forwardOnly, query, CRecordset::readOnly);

	CString sid, item, sdepartment, squantity, sunitcost, samount, pictures;

	int id, department, quantity;
	double unitcost, inventorycost, amount, totalinventorycost = 0;


	int count = 0;

	while (!recordset.IsEOF())
	{
		record = _T("");
		register int len = recordset.GetODBCFieldCount();

		recordset.GetFieldValue("ID", sid);
		recordset.GetFieldValue("Item", item);
		recordset.GetFieldValue("Department", sdepartment);

		recordset.GetFieldValue("Quantity", squantity);
		recordset.GetFieldValue("UnitCost", sunitcost);
		recordset.GetFieldValue("Amount", samount);
		

		recordset.GetFieldValue("Pictures", pictures);
	
		id = atoi(sid);
		department = atoi(sdepartment);
		quantity = atoi(squantity);
		unitcost = atof(sunitcost);
		amount = atof(samount);

		itemlist->AddHead(itempa2 = new InventoryCostClass(id, item, department, quantity, unitcost, amount, pictures));

		inventorycost = itempa2->getcomputedvalue();

		recordset.MoveNext();

	}

	itempa2->sort(itemlist);



}
	};

}
