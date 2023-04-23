#ifndef INVENTORYCLASS_H
#define INVENTORYCLASS_H

#include "stdafx.h" 
 

class Inventoryclass : public CObject
{        
       public:

          Inventoryclass();	
	   Inventoryclass(  int  , CString &  , int ,int,  double , CString &, CString& );	 
 	   
	   void compute();
	   double getamount();

	   void getdata(int & id, CString & item, int & department, int & quantity ,double & unitcost, double & ,CString &, CString &, int key, CObList * list);	  
	   static double gettotalamount();	   
         static int getcount();  	  
	   bool operator>(Inventoryclass * p);
	   void sort(CObList * list);

	   int binarysearch(CObList * list, CString & it);

		 
   private:
   
	       int id, quantity;
	       CString item;
		int department;
		double unitcost, amount;
		CString category, picture;

		static int count;
		static double totalamount;    
		
   };  

#endif

