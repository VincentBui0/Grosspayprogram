#ifndef InventoryCostClass_H
#define InventoryCostClass_H

#include "stdafx.h"

class InventoryCostClass : public CObject
{
public:

	InventoryCostClass();
	InventoryCostClass(int i, CString& ite, int depa, int quan, double unit, double invenc, CString& pic);

	void compute();
	double getcomputedvalue();

	void getdata(int& i, CString& ite, int & depa, int& quan, double& unit, double& invenc, CString& pic, int& key, CObList* list);

	static double gettotal();
	static int getcount();
	bool operator>(InventoryCostClass* p);
	void sort(CObList* list);
	void merge_sort(CObArray& thearray, const int low, const int high);
	void merge(CObArray& thearray, const int low, const int mid, const int high);

	int binarysearch(CObList * list, CString & it);

		 
   private:
   
	   int id, department, quantity;
	   CString item;
	   double unitcost, inventorycost;
	   CString picture;

	   static int count;
	   static double totalinventorycost;
};

#endif