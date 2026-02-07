#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct book{
	int year;
	string title;
	string author;
	int isbn;
	book *p,*n;
};
class list{
	book *start,*cur,*temp;
	int count;
	public:
		list(){
			start = NULL;
		}
		
		bool isduplicate(int n){
			cur = start;
			
			while(cur!=NULL){
				if(cur->isbn == n){
					return true;
				} cur = cur->n;
			} return false;
		}
		
		void insert(string a,int n,string t,int y){
			
			if (isduplicate(n)){
				cout<<"Insertion failed ISBN must be unique!!\n";
				
				return;
			}
			if (start == NULL){
				start = new book;
				start->author=a;
				start->isbn=n;
				start->title=t;
				start->year=y;
				start->p=NULL;
				start->n=NULL;
				count++;
			}
			else{
				cur = start;
				
				while(cur->n!=NULL)
				   cur = cur->n;
				   
				temp = new book;
				temp->author=a;
				temp->isbn=n;
				temp->title=t;
				temp->year=y;
				temp->p=cur;
				temp->n=NULL;
				cur->n=temp;
				count++;
			}
		}
		
		void dispaly(){
			if (start == NULL){
				cout<<"List is Empty!!\n";
				return;
			}
				cur = start;
			while(cur != NULL){
			     
					cout<<"Title: "<<cur->title<<"\tAuthor: "<<cur->author<<"\tYear: "<<cur->year<<"\tINSB: "<<cur->isbn;
					cout<<endl; 
					cur = cur->n;
					}
				 cout<<"Totle No OF BOOKS: "<<count<<endl;
				 return;
			}
			
		
		void search(){
		int i,c; string t;
		cout<<"Search By ISBN(1) or Title(2)? ";
		cin>>c;
		if(c==1){
		
		cout<<"\nEnter the ISBN Number of Book You want to search: ";
		cin>>i;
		cur = start;
		while(cur!=NULL){
			if(cur->isbn == i){
				cout<<"Found!!\n";
				return;
			}
			cur= cur->n;
		}
      } 
	   else if(c == 2){
	    cout<<"\nEnter the Title  of Book You want to search: ";
		cin>>t;
		cur = start;
		while(cur!=NULL){
			if(cur->title == t){
				cout<<"Found!!\n";
				return;
			}
			cur= cur->n;
    }
		} 
		else{
			cout<<"Invlid entry!!\n";
			return;
		} cout<<"NOT Found!!\n";
	}
	
	
		void update(){
		 int i;
		
		cout<<"=======Avalibe BOOks========\n";
		
		dispaly();
		cout<<"\nEnter the ISBN Number of Book You want to search: ";
		cin>>i;
		cur = start;
		while(cur!=NULL){
			if(cur->isbn == i){
				cout<<"Found!!\n";
				cout<<"Enter new Author, Title, Year, ISBN of the BOOk\n";
				cin>>cur->author>>cur->title>>cur->year>>cur->isbn;
				
				return;
			}
			cur= cur->n;
		}
			
			
		}
		
};
int main(int argc, char** argv) {
	list l;
	int c,y,i;
	string a,t;
	
	 do{
	 	cout<<"=======Welcome TO OUR Library========\n";
	 	cout<<"\n1. To insert\n2. To search\n3. To update\n4. To Dispaly\n5. Exist\n";
	 	cout<<"Enter Your choice: ";
	 	cin>>c;
	 	switch(c){
	 		case 1:
	 				
	 			cout<<"\nEnter Author, Title, Year, ISBN(Unique) of the BOOk\n";
	 			cin>>a>>t>>y>>i;
	 			l.insert(a,i,t,y); cout<<endl;
	 			break;
	 		case 2: 
	 		    l.search(); cout<<endl;
	 		    break;
	 		case 3: 
	 		     l.update(); cout<<endl;
	 		     break;
	 		case 4:
	 			l.dispaly(); cout<<endl;
	 			break;
	 		case 5:
	 			cout<<"Existing!!\n"; break;
	 		default: 
	 		    cout<<"Invalid Entry!!\n";
	 		    break;
		 }
	 } while(c != 5);
	return 0;
}
