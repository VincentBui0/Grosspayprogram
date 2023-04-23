
#include "stdafx.h"
#include "Inventoryclass.h"
 
int Inventoryclass::count=0;
double Inventoryclass::totalamount=0;
		

Inventoryclass::Inventoryclass()
{

}


Inventoryclass::Inventoryclass( int i, CString & it, int dp, int qt, double uc, CString & pic, CString & cat)
{
	 id = i;
	 item = it;
	 department = dp;
	 quantity = qt;
	 unitcost = uc;
	 picture = pic;
	 category = cat;

	 compute();

}
 
 
 double Inventoryclass::getamount()
 {
	 return amount;
 }

void Inventoryclass::compute()
{
	amount = quantity * unitcost;
	totalamount += amount;
     count++;
}





double Inventoryclass::gettotalamount()
{
  return totalamount;
}


bool Inventoryclass::operator > (Inventoryclass  * p)
{    
	return (amount > p->amount);
}


int Inventoryclass::binarysearch(CObList * list, CString & key)
{
 
        POSITION pos; 
        pos= list->GetTailPosition();
        CObject *b2 =list->GetPrev(pos);	   
	 Inventoryclass * pa1;     
        pa1 = (Inventoryclass *)b2;
	   int number = list->GetCount();

	   CObArray arraywithdata;

	   for (int st = 0; st < number; st++)
          {
                 arraywithdata.Add(pa1);

	             if (st < number-1)
		         {
			          b2 =list->GetPrev(pos);
			          pa1 = (Inventoryclass *)b2;
		          }
            }

	    int low = 0; // low index of elements to search
          int high = number - 1; // high index of elements to search
          int middle = ( low + high + 1 ) / 2; // middle element
          int location = -1; // key's index; -1 if not found



   int st=0;
   Inventoryclass * obj;


   do 
   {

	  obj = (Inventoryclass *)arraywithdata.GetAt(middle);
      // if the element is found at the middle
	   CString mword= obj->item;
	   


      if ( key == mword )
         location = middle; // location is the current middle
      else if ( key < mword  ) // middle is too high
         high = middle - 1; // eliminate the higher half
      else // middle element is too low
         low = middle + 1; // eliminate the lower half

      middle = ( low + high + 1 ) / 2; // recalculate the middle

   } while ( ( low <= high ) && ( location == -1 ) );

   return location; // return location of key
}




int Inventoryclass::getcount()
{
	return count;
}

  








void Inventoryclass::getdata(int&  i, CString & it, int & dp, int & qt, double & uc,double & amt, CString & pic, CString & cat, int key, CObList * list)
{

	 POSITION pos; 
        pos= list->GetTailPosition();
        CObject *b2 =list->GetPrev(pos);	   
	 Inventoryclass * pa1;     
        pa1 = (Inventoryclass *)b2;
	   int number = list->GetCount();


	    for (int st = 0; st < number; st++)
            {
                    if (st==key)
			 {	
			    i = pa1->id;
                       it = pa1->item;
                       dp = pa1->department;
                       qt = pa1->quantity;
                       uc = pa1->unitcost;
                       amt = pa1->amount;
                       pic =  pa1->picture;
                       cat = pa1->category;

			 }

	             if (st < number-1)
		         {
			          b2 =list->GetPrev(pos);
			          pa1 = (Inventoryclass *)b2;
		          }
            }

}
 
 
 



  
void Inventoryclass::sort(CObList * list)
{
        POSITION pos; 
        pos= list->GetTailPosition();
        CObject *b2 =list->GetPrev(pos);	   
	 Inventoryclass * pa1;     
        pa1 = (Inventoryclass *)b2;
	 int number = list->GetCount();
	 CObArray arraywithdata;

	 for (int st = 0; st < number; st++)
        {
                 arraywithdata.Add(pa1);

	             if (st < number-1)
		         {
			          b2 =list->GetPrev(pos);
			          pa1 = (Inventoryclass *)b2;
		          }
            }


	   Inventoryclass * hold;
          Inventoryclass * obj1, * obj2;
     
		  for (int pass = 1; pass <=number-1 ; pass++)  
		  {
                   for (int i = 0; i <= number-2 ; i++)       
	             {        
                       obj1 = (Inventoryclass *) arraywithdata.GetAt(i); 
                       obj2 = (Inventoryclass *)  arraywithdata.GetAt(i+1);
      
                       if (obj1->item.CompareNoCase(obj2->item) > 0)
                       {
                          hold =  (Inventoryclass *) arraywithdata.GetAt(i);                   
                          arraywithdata.SetAt(i, ((Inventoryclass *) arraywithdata.GetAt(i + 1)  ));
                          arraywithdata.SetAt(i + 1, hold);
                       }
                    }
		  }
     
	   list->RemoveAll();


        Inventoryclass *fromarray;
        fromarray = (Inventoryclass *) arraywithdata.GetAt(0);


        for (int st = 1; st <  number; st++)
         {          
              list->AddHead(fromarray);

	          if (st < number)
	          {
	             fromarray = (Inventoryclass *) arraywithdata.GetAt(st);			 
   	           }
           } 
}



























