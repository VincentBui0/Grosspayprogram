
#include "stdafx.h"
#include "OOPClass.h"
 
int InventoryCostClass::count=0;
double InventoryCostClass::totalinventorycost=0;
		

InventoryCostClass::InventoryCostClass()
{

}


InventoryCostClass::InventoryCostClass(int i, CString& ite, int depa, int quan, double unit, double invenc, CString& pic)
{
	id = i;
	item = ite;
	department = depa;
	quantity = quan;
	unitcost = unit;
	inventorycost = invenc;

	picture = pic;

	compute();
}

 
 
double InventoryCostClass::getcomputedvalue()
{
	return inventorycost;
}

void InventoryCostClass::compute()
{
	inventorycost = quantity * unitcost;
	count++;
}

double InventoryCostClass::gettotal()
{
	return totalinventorycost;
}

bool InventoryCostClass::operator > (InventoryCostClass* p)
{
	return (inventorycost > p->inventorycost);
}

int InventoryCostClass::binarysearch(CObList* list, CString& key)
{
	POSITION pos;
	pos = list->GetTailPosition();
	CObject* b2 = list->GetPrev(pos);
	InventoryCostClass* pa1;
	pa1 = (InventoryCostClass*)b2;
	int number = list->GetCount();


	CObArray arraywithdata;

	for (int st = 0; st < number; st++)
	{
		arraywithdata.Add(pa1);

		if (st < number - 1)
		{
			b2 = list->GetPrev(pos);
			pa1 = (InventoryCostClass*)b2;
		}
	}

	int low = 0; //low index of elements to search
	int high = number - 1;//high index of elements to search
	int middle = (low + high + 1) / 2;//middle element
	int location = -1;//key's index; -1 if not found
	int st = 0;

	InventoryCostClass* obj;

	do
	{
		obj = (InventoryCostClass*)arraywithdata.GetAt(middle);
		// if the element is found at the middle
		CString mword = obj->item;

		if (key == mword)
			location = middle;//location is the current middle
		else if (key < mword)//middle is too high
			high = middle - 1;//eliminate the higher half
		else//middle element is too low
			low = middle + 1;//eliminate the lower half

		middle = (low + high + 1) / 2;//recalculate the middle

	} while ((low <= high) && (location == -1));

	return location;//return location of key
}




int InventoryCostClass::getcount()
{
	return count;
}
  








void InventoryCostClass::getdata(int & i, CString& ite, int & depa, int & quan, double & unit, double & invenc, CString& pic, int& key, CObList* list)
{
	POSITION pos;
	pos = list->GetTailPosition();
	CObject* b2 = list->GetPrev(pos);
	InventoryCostClass* pa1;
	pa1 = (InventoryCostClass*)b2;
	int number = list->GetCount();

	for (int st = 0; st < number;st++)
	{
                    if (st==key)
			 {	
			    i = pa1->id;
                       i = pa1->id;
                       ite = pa1->item;
					   depa = pa1->department;
                       quan = pa1->quantity;
                       unit = pa1->unitcost;
					   invenc= pa1->inventorycost;
                       pic =  pa1->picture;
                      

			 }

	             if (st < number-1)
		         {
			          b2 =list->GetPrev(pos);
			          pa1 = (InventoryCostClass *)b2;
		          }
            }

}
 
 
 




void InventoryCostClass::sort(CObList* list)
{
	INT_PTR  number = list->GetCount();

	POSITION pos;

	CObArray thearray;

	pos = list->GetTailPosition();
	CObject* b2 = list->GetPrev(pos);

	bool swapflag = false;

	InventoryCostClass* pa1;

	pa1 = (InventoryCostClass*)b2;

	// ******************COPY DATA FROM THE LIST OBJECT TO THE ARRAY OBJECT 

	for (int st = 0; st < number; st++)
	{
		thearray.Add(pa1);

		if (st < number - 1)
		{
			b2 = list->GetPrev(pos);
			pa1 = (InventoryCostClass*)b2;
		}
	}

	//**********************SORT DATA IN THE ARRAY **********************

	CString employee;
	int arraySize = 0;
	arraySize = number - 1;

	merge_sort(thearray, 0, arraySize);

	list->RemoveAll();


	//******************* COPY DATA FROM THE ARRAY TO THE LIST OBJECT*************
	InventoryCostClass* fromarray;
	fromarray = (InventoryCostClass*)thearray.GetAt(0);

	for (int st = 1; st <= number; st++)
	{
		list->AddHead(fromarray);

		if (st < number)
		{
			fromarray = (InventoryCostClass*)thearray.GetAt(st);
		}
	}



}




void  InventoryCostClass::merge_sort(CObArray& thearray, const int low, const int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		merge_sort(thearray, low, mid);
		merge_sort(thearray, mid + 1, high);
		merge(thearray, low, mid, high);
	}
}











void  InventoryCostClass::merge(CObArray& arrayA, const int low, const int mid, const int high)
{

	InventoryCostClass* obj1, * obj2;

	CString employee;

	CObArray arrayB;

	int h, i, j, k;
	h = low;
	i = 0;
	j = mid + 1;

	// Merges the two array's into b[] until the first one is finish
	while ((h <= mid) && (j <= high))
	{

		obj1 = (InventoryCostClass*)arrayA.GetAt(h);
		obj2 = (InventoryCostClass*)arrayA.GetAt(j);

		CString hvalue = obj1->item;
		CString jvalue = obj2->item;

		if (hvalue <= jvalue)
		{
			arrayB.Add(obj1);
			h++;
		}
		else
		{
			arrayB.Add(obj2);
			j++;
		}
		i++;


	}


	// Completes the array filling in it the missing values
	if (h > mid)
	{
		for (k = j; k <= high; k++)
		{


			obj1 = (InventoryCostClass*)arrayA.GetAt(k);

			arrayB.Add(obj1);
			i++;
		}
	}
	else
	{
		for (k = h; k <= mid; k++)
		{

			obj1 = (InventoryCostClass*)arrayA.GetAt(k);
			arrayB.Add(obj1);
			i++;
		}
	}



	for (k = 0; k <= high - low; k++)
	{
		obj1 = (InventoryCostClass*)arrayB.GetAt(k);
		arrayA.SetAt((k + low), obj1);
	}

}





























